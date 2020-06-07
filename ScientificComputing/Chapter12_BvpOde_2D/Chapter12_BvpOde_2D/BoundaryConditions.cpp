#include "BoundaryConditions.hpp"
#include <cassert>
#include <cmath>

BoundaryConditions::BoundaryConditions(double YFcnAtXmin(double y),
	double YFcnAtXmax(double y),
	double XFcnAtYmin(double x),
	double XFcnAtYmax(double x),
	int numNodesX, double xMin, double xMax,
	int numNodesY, double yMin, double yMax)
{
	//resize vectors
	YAtXmin.resize(numNodesY);
	YAtXmax.resize(numNodesY);

	XAtYmin.resize(numNodesX);
	XAtYmax.resize(numNodesX);
	
	// equidistant grid
	double distX = (xMax - xMin) / ((double)numNodesX - 1.0);
	double distY = (yMax - yMin) / ((double)numNodesY - 1.0);

	//evaluate functions
	for (int i = 0; i < numNodesY; ++i)
		YAtXmin[i] = YFcnAtXmin(yMin + i * distY);
	for (int i = 0; i < numNodesY; ++i)
		YAtXmax[i] = YFcnAtXmax(yMin + i * distY);

	for (int i = 0; i < numNodesX; ++i)
		XAtYmin[i] = XFcnAtYmin(xMin + i * distX);
	for (int i = 0; i < numNodesX; ++i)
		XAtYmax[i] = XFcnAtYmax(xMin + i * distX);

	//assert the values in the corner nodes
	double tolerance = 1e-6;
	assert(fabs(YAtXmin[0] - XAtYmin[0]) <= tolerance);
	assert(fabs(YAtXmin[numNodesY - 1] - XAtYmax[0]) <= tolerance);
	assert(fabs(YAtXmax[0] - XAtYmin[numNodesX - 1]) <= tolerance);
	assert(fabs(YAtXmax[numNodesY - 1] - XAtYmax[numNodesX - 1]) <= tolerance);
}