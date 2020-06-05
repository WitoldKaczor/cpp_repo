#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "BvpOde.hpp"
constexpr double M_PI = 3.14159265358979323846; // pi

int main(int argc, char* argv[])
{
	//SecondOrderOde ode_mp1(-1.0, 0.0, 0.0, [](double x) { return 1.0; }, 0.0, 1.0);
	// alternative way to initialize ODE with overriden default constructor
	SecondOrderOde ode_mp1;
	ode_mp1.SetCoeffOfUxx(-1.0);
	ode_mp1.SetCoeffOfUx(0.0);
	ode_mp1.SetCoeffOfU(0.0);
	ode_mp1.SetRhsFunc([](double x) { return 1.0; });
	ode_mp1.SetXmin(0.0);
	ode_mp1.SetXmax(1.0);
	
	BoundaryConditions bc_mp1;
	bc_mp1.SetLhsDirichletBc(0.0);
	bc_mp1.SetRhsDirichletBc(0.0);

	BvpOde bvpode_mp1(&ode_mp1, &bc_mp1, 11);
	bvpode_mp1.SetFilename("model_problem_results1.dat");

	int numNodesNew = 31;
	std::vector<double> GridVec(numNodesNew);
	for (int i = 0; i < numNodesNew; ++i)
		GridVec[i] = 0.0 + (double)i * (1.0 - 0.0) / ((double)numNodesNew - 1.0);
	bvpode_mp1.SetGrid(GridVec);
	
	bvpode_mp1.Solve();
	bvpode_mp1.WriteSolutionFile();


	/*SecondOrderOde ode_mp2(1.0, 3.0, -4.0, [](double x) { return 34.0 * sin(x); }, 0.0, M_PI);
	BoundaryConditions bc_mp2;
	bc_mp2.SetLhsNeumannBc(-5.0);
	bc_mp2.SetRhsDirichletBc(4.0);

	BvpOde bvpode_mp2(&ode_mp2, &bc_mp2, 101);
	bvpode_mp2.SetFilename("model_problem_results2.dat");
	bvpode_mp2.Solve();
	bvpode_mp2.WriteSolutionFile();*/
	

	std::cout << "done\n";

	std::cin.get();
	return 0;
}

// After writing the solutions to a file plottted in gnuplot with:
//plot [-0.05:1.05][-0.1:0.15] (0.5 * x * (1-x)) title "Exact solution", "C:/Dev/git_repos/cpp_repo/ScientificComputing/Chapter12_BvpOde/Chapter12_BvpOde/model_problem_results1.dat" title "BvpOde Solver"
//plot [0:pi][-6:4] ( (4*exp(x) + exp(-4*x)) / (4*exp(pi)+exp(-4*pi)) - 5*sin(x) - 3*cos(x) ) title "Exact solution", "C:/Dev/git_repos/cpp_repo/ScientificComputing/Chapter12_BvpOde/Chapter12_BvpOde/model_problem_results2.dat" title "BvpOde Solver"