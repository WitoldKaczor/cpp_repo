#include "FiniteDifferenceGrid.hpp"
#include <cassert>

FiniteDifferenceGrid::FiniteDifferenceGrid(int numNodes, double xMin, double xMax)
{
	assert(numNodes > 2);
	assert(xMax > xMin);

	// equidistant grid
	double dist = (xMax - xMin) / ((double)numNodes - 1.0);

	mNodes.resize(numNodes);
	mNodes[0].coordinate = xMin;
	for (int i = 1; i < numNodes-1; ++i)
		mNodes[i].coordinate = mNodes[i-1].coordinate + dist;
	mNodes[numNodes - 1].coordinate = xMax;
}