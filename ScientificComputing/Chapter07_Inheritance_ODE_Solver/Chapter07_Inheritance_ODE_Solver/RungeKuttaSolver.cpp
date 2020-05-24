#include "RungeKuttaSolver.hpp"
#include <fstream>
#include <cassert>
//#include <iostream>

void RungeKuttaSolver::SolveEquation(double (*pRightHandSide) (double, double))
{
	double actualValue; // y(i)
	double lastValue; // y(i-1)
	double actualTime; // t(i)
	double lastTime; // t(i-1)
	double k1, k2, k3, k4;
	int iterNum;

	// define and open file
	std::ofstream writeFileRungeKutta;
	writeFileRungeKutta.open("RungeKuttaSolver.dat");
	assert(writeFileRungeKutta.is_open());
	writeFileRungeKutta.setf(std::ios::showpos);
	writeFileRungeKutta.setf(std::ios::scientific);
	writeFileRungeKutta.precision(6);

	// calculate iteration number 
	iterNum = (int)((finalTime - initialTime) / stepSize) + 1;

	// initialization
	actualValue = initialValue;
	actualTime = initialTime;
	writeFileRungeKutta << actualTime << '\t' << actualValue << '\n';
	//std::cout << actualTime << '\t' << actualValue << '\n';

	for (int i = 1; i <= iterNum; ++i)
	{
		lastValue = actualValue;
		lastTime = actualTime;

		if (i != iterNum)
		{
			// calculation of t(i)
			actualTime = initialTime + i * stepSize;
			// calculation of y(i), fourth order Runge–Kutta method
			k1 = stepSize * pRightHandSide(lastValue, lastTime);
			k2 = stepSize * pRightHandSide((lastValue + k1 / 2.0), (lastTime + stepSize / 2.0));
			k3 = stepSize * pRightHandSide((lastValue + k2 / 2.0), (lastTime + stepSize / 2.0));
			k4 = stepSize * pRightHandSide((lastValue + k3), (lastTime + stepSize));
			actualValue = lastValue + (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
		}
		else // i == iterNum
		{
			double stepSizeLast = (finalTime - initialTime) - (iterNum - 1.0) * stepSize;
			if (fabs(stepSizeLast) < 1e-6)
				continue;
			// the last step is smaller than the others 
			actualTime = lastTime + stepSizeLast;
			k1 = stepSizeLast * pRightHandSide(lastValue, lastTime);
			k2 = stepSizeLast * pRightHandSide((lastValue + k1 / 2.0), (lastTime + stepSizeLast / 2.0));
			k3 = stepSizeLast * pRightHandSide((lastValue + k2 / 2.0), (lastTime + stepSizeLast / 2.0));
			k4 = stepSizeLast * pRightHandSide((lastValue + k3), (lastTime + stepSizeLast));
			actualValue = lastValue + (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
		}
		// write ti and yi to file
		writeFileRungeKutta << actualTime << '\t' << actualValue << '\n';
		//std::cout << actualTime << '\t' << actualValue << '\n';
	}
}