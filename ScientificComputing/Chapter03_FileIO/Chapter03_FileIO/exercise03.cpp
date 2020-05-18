//Write code to implement the implicit(or backward) Euler method to solve the
//initial value ordinary differential equation dy/dx = -y, y(0) = 1,
//on the interval 0 <= x <= 1 using a constant step size h. Allow the user to specify the
//number of grid points, N they want to use at the command line, and use an assert
//statement to ensure that the number of grid points is greater than 1. Use the number of
//grid points to calculate the step size h.Your code should print a file called xy.dat
//that has two columns : the calculated values of x;and the calculated values of y.Plot
//the data from the file xy.dat and hence compare it with the true solution y = exp(-x).

#include <iostream>
#include <fstream>
#include <cassert>

int main(int argc, char* argv[])
{
	assert(argc == 2); //two arguments obligatory (program name and N)

	int nGridPoints = atoi(argv[1]);
	assert(nGridPoints > 1); // N has to be greater than one

	double nStepSize = 1 / ((double)nGridPoints - 1);

	std::ofstream outputVar("xyImplicitEuler.dat");
	assert(outputVar.is_open());
	outputVar.setf(std::ios::scientific);
	outputVar.setf(std::ios::showpos);
	outputVar.precision(8);
	
	// y(x=0) = 1 
	outputVar << 0.0 << '\t' << 1.0 << '\n';

	double yLast = 1;
	double yAct;

	// implicit Euler method
	for (int i = 1; i <= nGridPoints - 1; ++i) // i = 1, 2, ..., N-1
	{
		yAct = yLast / (nStepSize + 1);
		outputVar << i * nStepSize << '\t' << yAct << '\n';
		yLast = yAct;
	}
	outputVar.close();

	std::cout << "Data saved\n";


	//gnuplot commands
	//set title "Function exp(-x)"
	//set grid
	//plot[-0.1:1.1][0.3:1.1] "C:/Dev/git_repos/cpp_repo/ScientificComputing/Chapter03_FileIO/Debug/xyImplicitEuler.dat" title "Euler implicit", exp(-x) title "Exact"
	
	return 0;
}