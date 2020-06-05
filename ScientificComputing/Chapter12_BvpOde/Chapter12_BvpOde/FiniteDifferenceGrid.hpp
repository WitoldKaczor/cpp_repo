#ifndef FINITEDIFFERENCEGRIDHEADERDEF
#define FINITEDIFFERENCEGRIDHEADERDEF
#include <vector>
#include "Node.hpp"

class FiniteDifferenceGrid
{
public:
	// The boundary value class is able to access the nodes
	friend class BvpOde;
private:
	std::vector<Node> mNodes;
public:
	FiniteDifferenceGrid(int numNodes, double xMin,	double xMax);
	void SetGrid(std::vector<double> inputCoordVec);
};

#endif