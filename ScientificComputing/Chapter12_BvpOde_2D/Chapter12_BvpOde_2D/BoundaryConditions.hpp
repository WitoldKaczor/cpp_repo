#ifndef BOUNDARYCONDITIONSHEADERDEF
#define BOUNDARYCONDITIONSHEADERDEF

#include <vector>
#include <cassert>
#include <cmath>

class BoundaryConditions
{
public:
	// The boundary value class is able to
	// access the coefficients etc. of this equation
	friend class BvpOde;
private:
	std::vector<double> YAtXmax;
	std::vector<double> YAtXmin;
	std::vector<double> XAtYmax;
	std::vector<double> XAtYmin;
private:
	BoundaryConditions(double YFcnAtXmin(double y),
		double YFcnAtXmax(double y),
		double XFcnAtYmin(double x),
		double XFcnAtYmax(double x),
		int numNodesX, double xMin, double xMax,
		int numNodesY, double yMin, double yMax);
};

#endif