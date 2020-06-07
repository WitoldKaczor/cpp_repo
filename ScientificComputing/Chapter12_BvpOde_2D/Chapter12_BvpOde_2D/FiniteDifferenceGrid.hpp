#ifndef FINITEDIFFERENCEGRIDHEADERDEF
#define FINITEDIFFERENCEGRIDHEADERDEF
#include <vector>
#include <cassert>
#include "Node.hpp"

class FiniteDifferenceGrid
{
public:
	// The boundary value class is able to access the nodes
	friend class BvpOde;
private:
	std::vector<Node> mNodes;
private:
	FiniteDifferenceGrid(int numNodesX, double xMin, double xMax,
		int numNodesY, double yMin, double yMax);
};

#endif