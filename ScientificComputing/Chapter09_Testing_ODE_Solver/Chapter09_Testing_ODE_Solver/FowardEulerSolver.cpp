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
		
		// rounding of numeric error
		if ((-1e-6) < actualValue && actualValue < 0.0)
			actualValue = 0.0;
		else if (1.0 < actualValue && actualValue < (1.0 + 1e6))
			actualValue = 0.0;

		// for error bigger than 1e6 halve the stepsize
		if (actualValue < (-1e-6) || (1.0 + 1e6) < actualValue)
		{
			actualValue = lastValue;
			actualTime = lastTime;
			stepSize /= 2; 
			// calculate new iteration number 
			iterNum = (int)((finalTime - initialTime) / stepSize) + 1; 
			// reset loop iterator
			i = 0; 
		}
		else
		{
			// write ti and yi to file
			writeFileEuler << actualTime << '\t' << actualValue << '\n';
		}

		// if stepsize smaller than critical value, then break calculation
		assert(stepSize > 1e-6);

		//std::cout << actualTime << '\t' << actualValue << '\t' << stepSize << '\n';
	}
}