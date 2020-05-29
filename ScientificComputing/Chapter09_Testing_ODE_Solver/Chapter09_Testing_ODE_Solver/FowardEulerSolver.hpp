#ifndef FORWARDEULERSOLVERDEF
#define FORWARDEULERSOLVERDEF

#include "AbstractOdeSolver.hpp"

class FowardEulerSolver : public AbstractOdeSolver
{
public:
	void SolveEquation(double (*pRightHandSide) (double, double));
}; 

#endif