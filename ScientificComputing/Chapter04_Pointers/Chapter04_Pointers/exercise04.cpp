//Write code that dynamically allocates memory for three 2×2 matrices of double
//precision floating point numbers, A, B, C, and assigns values to the entries of A and
//B.Let C = A + B.Extend your code so that it calculates the entries of C, and then
//prints the entries of C to screen.Finally, de-allocate memory.Again, check you have
//de - allocated memory correctly by using a for loop as in the previous exercise.

#include <iostream>

int main(int argc, char* argv[])
{
	int iterNum = 1000000000;

	for (int iter = 0; iter < iterNum; ++iter)
	{
		// dynamically allocating memory
		double** A = new double* [2];
		for (int i = 0; i < 2; ++i)
			A[i] = new double[2];

		double** B = new double* [2];
		for (int i = 0; i < 2; ++i)
			B[i] = new double[2];

		double** C = new double* [2];
		for (int i = 0; i < 2; ++i)
			C[i] = new double[2];

		// assigning values
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
			{
				A[i][j] = (double)i * (double)j;
				B[i][j] = ((double)i - 2) + (double)j;

				C[i][j] = A[i][j] + B[i][j];
				/*if (i == 0 && j == 0) { std::cout << "C: "; }
				if (j == 0) { std::cout << '\n'; }
				std::cout << C[i][j] << '\t';*/
			}

		//deallocating memory
		for (int i = 0; i < 2; ++i)
			delete[] A[i];
		delete[] A;

		for (int i = 0; i < 2; ++i)
			delete[] B[i];
		delete[] B;

		for (int i = 0; i < 2; ++i)
			delete[] C[i];
		delete[] C;
	}



	std::cout << "Done";
	std::cin.get();
	return 0;
}