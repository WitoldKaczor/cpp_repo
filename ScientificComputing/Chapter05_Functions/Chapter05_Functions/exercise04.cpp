//Write a function that can be used to calculate the mean and standard 
//deviation of an array of double precision floating point numbers.

#include <iostream>
#include <cmath>

void MeanAndStdDev(double* arr, int arrSize, double& mean, double& stdDev);

int main(int argc, char* argv[])
{
	const int arrSize = 10;
	double* arr = new double[arrSize];
	for (int i = 0; i < arrSize; ++i)
		arr[i] = i;
	double mean;
	double stdDev;

	MeanAndStdDev(arr, arrSize, mean, stdDev);
	std::cout << "Mean\t= " << mean << '\n';
	std::cout << "Std dev\t= " << stdDev << '\n';

	for (int i = 0; i < arrSize; ++i)
		std::cout << '\n' << arr[i];

	delete[] arr;

	std::cin.get();
	return 0;
}

void MeanAndStdDev(double* arr, int arrSize, double& mean, double& stdDev)
{
	//mean 
	mean = 0;
	for (int i = 0; i < arrSize; ++i)
	{
		mean += arr[i];
	}
	mean /= arrSize;

	// sample standard deviation 
	stdDev = 0;
	for (int i = 0; i < arrSize; ++i)
	{
		stdDev += (arr[i] - mean) * (arr[i] - mean); 
	}
	stdDev /= (arrSize - 1.0);
	stdDev = sqrt(stdDev);
}