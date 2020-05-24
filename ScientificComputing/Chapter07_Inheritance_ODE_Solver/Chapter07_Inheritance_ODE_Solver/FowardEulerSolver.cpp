#include "FowardEulerSolver.hpp"
//#include <iostream>
#include <fstream>
#include <cassert>

void FowardEulerSolver::SolveEquation(double (*pRightHandSide) (double, double))
{
	double actualValue; // y(i)
	double lastValue; // y(i-1)
	double actualTime; // t(i)
	double lastTime; // t(i-1)
	int iterNum;
	
	// define and open file
	std::ofstream writeFileEuler;
	writeFileEuler.open("EulerSolver.dat");
	assert(writeFileEuler.is_open());
	writeFileEuler.setf(std::ios::showpos);
	writeFileEuler.setf(std::ios::scientific);
	writeFileEuler.precision(6);

	// calculate iteration number 
	iterNum = (int)((finalTime - initialTime) / stepSize) + 1;

	// initialization
	actualValue = initialValue;
	actualTime = initialTime;
	writeFileEuler << actualTime << '\t' << actualValue << '\n';
	//std::cout << actualTime << '\t' << actualValue << '\n';

	for (int i = 1; i <= iterNum; ++i)
	{
		lastValue = actualValue;
		lastTime = actualTime;

		
		if (i != iterNum)
		{
			// calculation of t(i)
			actualTime = initialTime + i * stepSize;
			// calculation of y(i), forward Euler method
			actualValue = lastValue + stepSize * pRightHandSide(lastValue, lastTime);
		}
		else // i == iterNum
		{
			if (fabs((finalTime - initialTime) - (iterNum - 1.0) * stepSize) < 1e-6)
				continue;
			// the last step is smaller than the others 
			actualTime = lastTime + ((finalTime - initialTime) - (iterNum - 1.0) * stepSize);
			actualValue = lastValue + ((finalTime - initialTime) - (iterNum - 1.0) * stepSize) * pRightHandSide(lastValue, lastTime);
		}
			
		// write ti and yi to file
		writeFileEuler << actualTime << '\t' << actualValue << '\n';
		//std::cout << actualTime << '\t' << actualValue << '\n';
	}
}