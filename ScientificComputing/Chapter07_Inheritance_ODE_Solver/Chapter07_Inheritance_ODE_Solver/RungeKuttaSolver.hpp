#ifndef RUNGEKUTTASOLVERDEF
#define RUNGEKUTTASOLVERDEF

#include "AbstractOdeSolver.hpp"

class RungeKuttaSolver : public AbstractOdeSolver
{
public:
	void SolveEquation(double (*pRightHandSide) (double, double));
};

#endif