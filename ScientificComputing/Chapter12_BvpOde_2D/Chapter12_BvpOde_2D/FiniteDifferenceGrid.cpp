#include "FiniteDifferenceGrid.hpp"
#include <cassert>
//#include <iostream>
//#include <iomanip>

FiniteDifferenceGrid::FiniteDifferenceGrid(int numNodesX, double xMin, double xMax,
	int numNodesY, double yMin, double yMax)
{
	assert(numNodesX > 2);
	assert(xMax > xMin);
	assert(numNodesY > 2);
	assert(yMax > yMin);

	// equidistant grid
	double distX = (xMax - xMin) / ((double)numNodesX - 1.0);
	double distY = (yMax - yMin) / ((double)numNodesY - 1.0);

	mNodes.resize(numNodesX * numNodesY);

	for (int i = 0; i < numNodesX; ++i)
		for (int j = 0; j < numNodesY; ++j)
		{
			mNodes[i + numNodesX * j].X = xMin + i * distX;
			mNodes[i + numNodesX * j].Y = yMin + j * distY;
		}

	// print grid to console
	/*for (int j = numNodesY - 1; j > -1; --j)
		for (int i = 0; i < numNodesX; ++i)
		{
			if (!i) { std::cout << '\n'; }
			std::cout << std::fixed << std::setprecision(2);
			std::cout << mNodes[i + numNodesX * j].X << ", "
				<< mNodes[i + numNodesX * j].Y << "  ";
		}
	std::cout << "\n\n";*/
}