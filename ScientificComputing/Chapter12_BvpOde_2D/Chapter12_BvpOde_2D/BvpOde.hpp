#ifndef BVPODEHEADERDEF
#define BVPODEHEADERDEF

#include <string>
#include <fstream>
#include <cassert>
#include "Matrix.hpp"
#include "Vector.hpp"
#include "LinearSystem.hpp"
#include "FiniteDifferenceGrid.hpp"
#include "PoissonEq.hpp"
#include "BoundaryConditions.hpp"

class BvpOde
{
public:
	// Sole constructor
	BvpOde(double poissonEqRhsFcn(double x, double y),
		int numXNodes, int xMin, int xMax,
		int numYNodes, int yMin, int yMax,
		double YFcnAtXmin(double y),
		double YFcnAtXmax(double y),
		double XFcnAtYmin(double x),
		double XFcnAtYmax(double x));

		// As memory is dynamically allocated the destructor is overridden
		~BvpOde();
	private:
		// Only allow instance to be created from a PDE, boundary
		// conditions, and number of nodes in the mesh 
		// (the copy constructor is private)
		BvpOde(const BvpOde& otherBvpOde);

private:
	// Number of nodes in the grid, and a pointer to a grid
	int mNumNodesX;
	int mNumNodesY;
	FiniteDifferenceGrid* mpGrid;

	// Pointer to instance of an ODE
	PoissonEq* mpOde;

	// Pointer to an instance of boundary conditions
	BoundaryConditions* mpBcs;

	// Vector for solution to unknowns
	Vector* mpSolVec;

	// Right-hand side vector
	Vector* mpRhsVec;

	// Matrix for linear system
	Matrix* mpLhsMat;

	// Linear system that arises
	LinearSystem* mpLinSys;

	// Allow user to specify the output file or
	// use a default name
	std::string mFilename;

private:
	// Private methods for setting up linear system and solving it
	void PopulateMatrix();
	void PopulateVector();
	void ApplyBoundaryConditions();
	
public:
	void SetFilename(const std::string& name);
	void Solve();
	void WriteSolutionFile();
	Vector* OutputSolution() const;
};

#endif