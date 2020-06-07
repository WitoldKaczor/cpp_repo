#include <iostream>
#include "LinearSystem.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"
#include "PoissonEq.hpp"
#include "FiniteDifferenceGrid.hpp"
#include "BoundaryConditions.hpp"
#include "BvpOde.hpp"

int main(int argc, char* argv[])
{
	// define Bvp
	auto poissonEqRhsFcn = [](double x, double y) 
		{ return (-4 * (1 - x * x - y * y) * (exp(-(x * x + y * y)))); };
	double xMinimum = 0.0;
	double xMaximum = 1.0;
	double yMinimum = 0.0;
	double yMaximum = 2.0;
	auto YFcnAtXmin = [](double y) { return ( exp( -(y * y) ) ); };
	auto YFcnAtXmax = [](double y) { return ( exp( -(1 + y * y) ) ); };
	auto XFcnAtYmin = [](double x) { return ( exp( -(x * x) ) ); };
	auto XFcnAtYmax = [](double x) { return ( exp( -(4 + x * x) ) ); };

	// grid precision
	int numXNodes = 11;
	int numYNodes = 11;

	// initialize and solve Bvp
	auto pPeq = new PoissonEq(poissonEqRhsFcn, xMinimum, xMaximum, yMinimum, yMaximum);
	auto pFdg = new FiniteDifferenceGrid(numXNodes, xMinimum, xMaximum, numYNodes, yMinimum, yMaximum);
	auto pBc = new BoundaryConditions(YFcnAtXmin, YFcnAtXmax, XFcnAtYmin, XFcnAtYmax,
		numXNodes, xMinimum, xMaximum, numYNodes, yMinimum, yMaximum);
	BvpOde bvp(pPeq, pFdg, pBc, numXNodes, numYNodes);
	bvp.Solve();
	bvp.SetFilename("SolPoisEq.dat");
	bvp.WriteSolutionFile();

	delete pPeq;
	delete pFdg;
	delete pBc;


	std::cout << "done\n";
	std::cin.get();
	return 0;
}


// gnuplot:
//set xlabel "X axis"; set ylabel "Y axis"; set xrange [0:1]; set yrange [0:2]; set view 60, 30, 0.85, 1.1; set ticslevel 0; splot ( exp(-((x**2)+(y**2))) ), "C:/Dev/git_repos/cpp_repo/ScientificComputing/Chapter12_BvpOde_2D/Chapter12_BvpOde_2D/SolPoisEq.dat" title "BvpOde Solver"