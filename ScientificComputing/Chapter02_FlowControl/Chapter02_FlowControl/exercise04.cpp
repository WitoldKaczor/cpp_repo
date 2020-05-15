#include <iostream>

//This exercise uses the following vectors and matrices: u, v, w, A, B
//We now define vectors x, y, and z, and matrices Cand D, such that
//x = u - v,
//y = Au,
//z = Au - v,
//C = 4A - 3B,
//D = AB.
//Develop the program above to calculate the vectors x, y, and z and the matrices C
//and D, using loops where possible. Hint: make sure you define arrays of an appropriate
//size for these variables.Check your answer by printing out the results, and
//comparing with direct calculation.

int main(int argc, char* argv[])
{
	double u[3] = { 1.0, 2.0, 3.0 };
	double v[3] = { 6.0, 5.0, 4.0 };
	double A[3][3] = {	{1.0, 5.0, 0.0}, 
						{7.0, 1.0, 2.0},
						{0.0, 0.0, 1.0} };
	double B[3][3] = {	{-2.0, 0.0, 1.0},
						{1.0, 0.0, 0.0},
						{4.0, 1.0, 0.0} };
	
	double w[3];
	std::cout << "wT: ";
	for (int i = 0; i < 3; i++)
	{
		w[i] = u[i] - 3.0 * v[i];
		std::cout << w[i] << '\t';
	}

	//x = u - v
	double x[3];
	std::cout << "\n\nxT: ";
	for (int i = 0; i < 3; i++)
	{
		x[i] = u[i] - v[i];
		std::cout << x[i] << '\t';
	}

	//y = Au
	double y[3] = { 0, 0, 0 };
	std::cout << "\n\nyT: ";
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			y[i] += A[i][j] * u[j];
		}
	for (int i = 0; i < 3; i++)
		std::cout << y[i] << '\t';

	//z = Au - v
	double z[3] = { 0, 0, 0 };
	std::cout << "\n\nzT: ";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			z[i] += A[i][j] * u[j];
		}
		z[i] -= v[i];
	}
	for (int i = 0; i < 3; i++)
		std::cout << z[i] << '\t';

	//C = 4A - 3B
	double C[3][3];
	std::cout << "\n\nC:";
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			C[i][j] = 4 * A[i][j] - 3 * B[i][j];
			if (j == 0) { std::cout << '\n'; }
			std::cout << C[i][j] << '\t';
		}

	//D = AB
	double D[3][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				D[i][k] += A[i][j] * B[j][k];

	std::cout << "\n\nD:";
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (j == 0) { std::cout << '\n'; }
			std::cout << D[i][j] << '\t';
		}

	std::cin.get();
	return 0;
}