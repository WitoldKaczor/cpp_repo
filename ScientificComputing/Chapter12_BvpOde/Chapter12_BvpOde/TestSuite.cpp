#include <iostream>
//#include <cmath>
//#include <string>
#include <vector>
#include "BvpOde.hpp"
constexpr double M_PI = 3.14159265358979323846; // pi

class TestBvpOde1
{
public:
	TestBvpOde1()
	{
		double testTolerance = 1e-14;
		int NumNodes = 101;
		double Xmin = 0.0;
		double Xmax = 1.0;
		auto exactSol = [](double x) { return (0.5 * x * (1 - x)); };
		std::vector<double> GridVec(NumNodes);
		for (int i = 0; i < NumNodes; ++i)
			GridVec[i] = Xmin + (double)i * (Xmax - Xmin) / ((double)NumNodes - 1.0);

		SecondOrderOde ode_test1(-1.0, 0.0, 0.0, [](double x) { return 1.0; }, Xmin, Xmax);
		BoundaryConditions bc_test1;
		bc_test1.SetLhsDirichletBc(0.0);
		bc_test1.SetRhsDirichletBc(0.0);
		BvpOde bvpode_test1(&ode_test1, &bc_test1, NumNodes);
		bvpode_test1.SetGrid(GridVec);
		bvpode_test1.Solve();

		for (int i = 0; i < NumNodes; ++i)
		{
			TS_ASSERT_DELTA((*(bvpode_test1.OutputSolution()))[i],
				exactSol(GridVec[i]), testTolerance);	

			/*std::cout << GridVec[i] << '\t';
			std::cout << (*(bvpode_test1.OutputSolution()))[i] << '\t';
			std::cout << exactSol(GridVec[i]) << '\n';*/
		}

		std::cout << "Test01 passed\n";
	}
private:
	void TS_ASSERT_DELTA(double var1, double var2, double tolerance)
	{
		assert(fabs(var1 - var2) <= tolerance);
	}
};

class TestBvpOde2
{
public:
	TestBvpOde2()
	{
		double testTolerance = 1e-2;
		int NumNodes = 151;
		double Xmin = 0.0;
		double Xmax = M_PI;
		auto exactSol = [](double x) 
			{ return ((4 * exp(x) + exp(-4 * x)) / (4 * exp(M_PI) + exp(-4 * M_PI)) - 5 * sin(x) - 3 * cos(x)); };
		std::vector<double> GridVec(NumNodes);
		for (int i = 0; i < NumNodes; ++i)
			GridVec[i] = Xmin + (double)i * (Xmax - Xmin) / ((double)NumNodes - 1.0);

		SecondOrderOde ode_test2(1.0, 3.0, -4.0, [](double x) { return 34.0 * sin(x); }, Xmin, Xmax);
		BoundaryConditions bc_test2;
		bc_test2.SetLhsNeumannBc(-5.0);
		bc_test2.SetRhsDirichletBc(4.0);
		BvpOde bvpode_test2(&ode_test2, &bc_test2, NumNodes);
		bvpode_test2.SetGrid(GridVec);
		bvpode_test2.Solve();

		for (int i = 0; i < NumNodes; ++i)
		{
			TS_ASSERT_DELTA((*(bvpode_test2.OutputSolution()))[i],
				exactSol(GridVec[i]), testTolerance);

			/*std::cout << GridVec[i] << '\t';
			std::cout << (*(bvpode_test2.OutputSolution()))[i] << '\t';
			std::cout << exactSol(GridVec[i]) << '\n';*/
		}

		std::cout << "Test02 passed\n";
	}
private:
	void TS_ASSERT_DELTA(double var1, double var2, double tolerance)
	{
		assert(fabs(var1 - var2) <= tolerance);
	}
};

int main(int argc, char* argv[])
{
	// tests are called in the default constructor
	TestBvpOde1 testObj1;
	TestBvpOde2 testObj2;

	std::cin.get();
	return 0;
}