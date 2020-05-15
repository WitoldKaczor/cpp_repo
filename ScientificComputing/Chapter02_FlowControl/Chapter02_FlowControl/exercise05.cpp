#include <iostream>
#include <cassert>

//1. Write code to calculate the inverse of the matrix A
//2. Check that the inverse calculated is correct by printing out the entries of the
//inverse, and comparing with direct calculation.
//3. Modify your code to include an assert statement that checks that the determinant
//of the matrix is nonzero.

int main(int argc, char* argv[])
{
	double A[2][2] = { { 4, 10 } , { 1, 1 } };

	double determinant = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	assert(abs(determinant)>1e-6); // determinant check

	double invA[2][2];
	invA[0][0] = A[1][1] / determinant;
	invA[0][1] = -A[0][1] / determinant;
	invA[1][0] = -A[1][0] / determinant;
	invA[1][1] = A[0][0] / determinant;

	std::cout << "Inverse of A";
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
		{
			if (j == 0) { std::cout << '\n'; }
			std::cout << invA[i][j] << '\t';
		}

	std::cin.get();
	return 0;
}