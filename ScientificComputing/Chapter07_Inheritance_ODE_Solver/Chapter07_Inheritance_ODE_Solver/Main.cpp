#include "AbstractOdeSolver.hpp"
#include "FowardEulerSolver.hpp"
#include "RungeKuttaSolver.hpp"
#include <iostream>

double UserRightHandSideFcn(double y, double t)
{
	return (1 + t); // f(y,t) = 1 + t
}

int main(int argc, char* argv[])
{
	double h = 0.01;
	double t0 = 0.0;
	double t1 = 1.0;
	double y0 = 2.0;

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
//set title "dy/dt = 1 + t, y0 = 2"
//set grid
//plot[-0.1:1.1][1.8:3.7] "C:/Dev/git_repos/cpp_repo/ScientificComputing/Chapter07_Inheritance_ODE_Solver/Chapter07_Inheritance_ODE_Solver/EulerSolver.dat" title "Forward Euler method", "C:/Dev/git_repos/cpp_repo/ScientificComputing/Chapter07_Inheritance_ODE_Solver/Chapter07_Inheritance_ODE_Solver/RungeKuttaSolver.dat" title "Fourth order Runge–Kutta method", (x*x / 2 + x + 2) title "Exact y(t) = t^2/2 + t + 2"