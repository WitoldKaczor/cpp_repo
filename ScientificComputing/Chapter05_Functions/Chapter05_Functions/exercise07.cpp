//Extend the code in Sect. 5.10 to calculate the p-norm
//of a given vector, where p is a positive integer 
//and takes the default value 2.

#include <iostream>
#include <cmath>
#include <cassert>

double CalculateNorm(double* vec, int vecSize, int p = 2)
{
	assert(p > 0);
	double a = 0.0;
	for (int i = 0; i < vecSize; i++)
	{
		double temp = fabs(vec[i]);
		a += pow(temp, p);
	}
	return pow(a, 1.0 / p);
}

int main(int argc, char* argv[])
{
	const int xSize = 10;
	double* x = new double [xSize];
	for (int i = 0; i < xSize; i++)
		x[i] = i % 2 ? 1 : 3;
		
	std::cout << "P-Norm (p=2): " << CalculateNorm(x, xSize) << '\n';
	std::cout << "P-Norm (p=3): " << CalculateNorm(x, xSize, 3) << '\n';
	std::cout << "P-Norm (p=5): " << CalculateNorm(x, xSize, 5) << '\n';
	std::cout << "P-Norm (p=9): " << CalculateNorm(x, xSize, 9) << '\n';

	delete[] x;

	std::cin.get();
	return 0;
}