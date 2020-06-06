#ifndef BVPODEHEADERDEF
#define BVPODEHEADERDEF

#include <string>
#include "Matrix.hpp"
#include "Vector.hpp"
#include "LinearSystem.hpp"
#include "FiniteDifferenceGrid.hpp"
#include "SecondOrderOde.hpp"
#include "BoundaryConditions.hpp"
#include <vector>

class BvpOde
{
public:
	// Sole constructor
	BvpOde(SecondOrderOde* pOde, BoundaryConditions* pBcs, int numNodes);

	// As memory is dynamically allocated the destructor is overridden
	~BvpOde();
private:
	// Only allow instance to be created from a PDE, boundary
	// conditions, and number of nodes in the mesh 
	// (the copy constructor is private)
	BvpOde(const BvpOde& otherBvpOde);

private:
	// Number of nodes in the grid, and a pointer to a grid
	int mNumNodes;
	FiniteDifferenceGrid* mpGrid;

	// Pointer to instance of an ODE
	SecondOrderOde* mpOde;

	// Pointer to an instance of boundary conditions
	BoundaryConditions* mpBconds;

	// Vector for solution to unknowns
	Vector* mpSolVec;

	// Right-hand side vector
	Vector* mpRhsVec;

	// Matrix for linear system
	Matrix* mpLhsMat;

	// Linear system that arises
	LinearSystem* mpLinearSystem;

	// Allow user to specify the output file or
	// use a default name
	std::string mFilename;

private:
	// Methods for setting up linear system and solving it
	void PopulateMatrix();
	void PopulateVector();
	void ApplyBoundaryConditions();

public:
	void SetFilename(const std::string& name);
	void Solve();
	void WriteSolutionFile();
	void SetGrid(std::vector<double> inputCoordVec);
	Vector* OutputSolution() const;
};

#endif