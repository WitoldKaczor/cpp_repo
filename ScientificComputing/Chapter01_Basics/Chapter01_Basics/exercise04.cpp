#include <iostream>

//Write code that declares four 2 × 2 matrices of double precision floating point
//numbers, A, B, C, D, and assigns values to the entries of A and B.Let C = A + B, and
//D = A * B. Extend your code so that it calculates the entries of C and D, and then prints
//the entries of these matrices to screen.

int main(int argc, char* argv[])
{
	double A[2][2] = { {1.5,2},{3,0} };
	double B[2][2] = { {2,1},{0,2} };
	double C[2][2], D[2][2];

	std::cout << "A:\n";
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
		{
			if (j == 0 && i != 0) std::cout << '\n';
			std::cout << A[i][j] << '\t';
		}
	std::cout << "\n\nB:\n";
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
		{
			if (j == 0 && i != 0) std::cout << '\n';
			std::cout << B[i][j] << '\t';
		}

	for (int i=0;i<2;++i)
		for (int j = 0; j < 2; ++j)
			C[i][j] = A[i][j] + B[i][j];

	std::cout << "\n\nA + B = C:\n";
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
		{
			if (j == 0 && i != 0) std::cout << '\n';
			std::cout << C[i][j] << '\t';
		}

	D[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
	D[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
	D[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
	D[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];

	std::cout << "\n\nA * B = D:\n";
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
		{
			if (j == 0 && i != 0) std::cout << '\n';
			std::cout << D[i][j] << '\t';
		}

	std::cin.get();
	return 0;
}