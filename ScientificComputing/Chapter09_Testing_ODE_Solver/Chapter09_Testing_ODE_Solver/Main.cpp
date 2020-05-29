#include "AbstractOdeSolver.hpp"
#include "FowardEulerSolver.hpp"
#include "RungeKuttaSolver.hpp"
//#include <iostream>

double UserRightHandSideFcn(double y, double t)
{
	return (-100 * y); // f(y,t) = -100*y
}

int main(int argc, char* argv[])
{
	double h = 0.2;
	double t0 = 0.0;
	double t1 = 20.0;
	double y0 = 0.8;

	FowardEulerSolver solver1;
	solver1.SetStepSize(h);
	solver1.SetTimeInterval(t0, t1);
	solver1.SetInitialValue(y0);
	solver1.SolveEquation(UserRightHandSideFcn);


	RungeKuttaSolver solver2;
	solver2.SetStepSize(h);
	solver2.SetTimeInterval(t0, t1);
	solver2.SetInitialValue(y0);
	solver2.SolveEquation(UserRightHandSideFcn);
	
	//std::cin.get();
	return 0;
}

//for comparison with exact solution plotted with gnuplot:
//set title "dy/dt = 100y, y0 = 0.8"
//set grid
//plot[-0.01:0.3][-0.1:0.9] "C:/Dev/git_repos/cpp_repo/ScientificComputing/Chapter09_Testing_ODE_Solver/Chapter09_Testing_ODE_Solver/EulerSolver.dat" title "Forward Euler method", "C:/Dev/git_repos/cpp_repo/ScientificComputing/Chapter09_Testing_ODE_Solver/Chapter09_Testing_ODE_Solver/RungeKuttaSolver.dat" title "Fourth order Runge–Kutta method", (0.8 * exp(-100*x)) title "Exact solution"