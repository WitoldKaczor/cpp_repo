#include <iostream>
#include "BvpOde.hpp"

int main(int argc, char* argv[])
{
	if (false) // true or false for the cases 01 and 02 respectively
	{
		// define Bvp01
		auto poissonEqRhsFcn = [](double x, double y)
		{ return (-4 * (1 - x * x - y * y) * (exp(-(x * x + y * y)))); };
		double xMin = 0.0;
		double xMax = 1.0;
		double yMin = 0.0;
		double yMax = 2.0;
		auto YFcnAtXmin = [](double y) { return (exp(-(y * y))); };
		auto YFcnAtXmax = [](double y) { return (exp(-(1 + y * y))); };
		auto XFcnAtYmin = [](double x) { return (exp(-(x * x))); };
		auto XFcnAtYmax = [](double x) { return (exp(-(4 + x * x))); };
		// grid precision
		int numXNodes = 11;
		int numYNodes = 21;

		// initialize and solve Bvp01
		BvpOde bvp01(poissonEqRhsFcn,
			numXNodes, xMin, xMax,
			numYNodes, yMin, yMax,
			YFcnAtXmin, YFcnAtXmax, XFcnAtYmin, XFcnAtYmax);
		bvp01.Solve();
		bvp01.SetFilename("SolPoisEq01.dat");
		bvp01.WriteSolutionFile();
	}
	else
	{
		// define Bvp02
		auto poissonEqRhsFcn = [](double x, double y)
			{return ((y - 1) * y * pow(x, y - 2) + pow(x, y) * pow(log(x), 2) + 18 * pow(x, 2) * y + 6 * pow(y, 3)); };
		double xMin = 1.0;
		double xMax = 2.0;
		double yMin = 1.0;
		double yMax = 2.0;
		auto YFcnAtXmin = [](double y) { return ( 3 * pow(y, 3) + 1); };
		auto YFcnAtXmax = [](double y) { return ( pow(2, y) + 12 * pow(y, 3) ); };
		auto XFcnAtYmin = [](double x) { return ( 3 * pow(x, 2) + x ); };
		auto XFcnAtYmax = [](double x) { return ( 25 * pow(x, 2) ); };
		// grid precision
		int numXNodes = 11;
		int numYNodes = 11;

		// initialize and solve Bvp02
		BvpOde bvp02(poissonEqRhsFcn,
			numXNodes, xMin, xMax,
			numYNodes, yMin, yMax,
			YFcnAtXmin, YFcnAtXmax, XFcnAtYmin, XFcnAtYmax);
		bvp02.Solve();
		bvp02.SetFilename("SolPoisEq02.dat");
		bvp02.WriteSolutionFile();
	}


	std::cout << "done\n";
	std::cin.get();
	return 0;
}

// gnuplot:
//set xlabel "X axis"; set ylabel "Y axis"; set xrange [0:1]; set yrange [0:2]; set view 60, 30, 0.85, 1.1; set ticslevel 0; splot ( exp(-((x**2)+(y**2))) ), "C:/Dev/git_repos/cpp_repo/ScientificComputing/Chapter12_BvpOde_2D/Chapter12_BvpOde_2D/SolPoisEq01.dat" title "BvpOde Solver"
//set xlabel "X axis"; set ylabel "Y axis"; set xrange [1:2]; set yrange [1:2]; set view 60, 30, 0.85, 1.1; set ticslevel 0; splot ( x**y + 3*x**2*y**3 ), "C:/Dev/git_repos/cpp_repo/ScientificComputing/Chapter12_BvpOde_2D/Chapter12_BvpOde_2D/SolPoisEq02.dat" title "BvpOde Solver"