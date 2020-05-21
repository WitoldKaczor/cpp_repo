//The determinant of a square matrix may be defined recursively.
//Write a recursive function that may be used to calculate the determinant of a square
//matrix of a given size. Check the accuracy of your code by comparison with the
//known formulae for square matrices of size 2 and 3

#include <iostream>
#include <cmath>

void minorMatrix(double** major, int sizeMajor, double** minor, int detRow, int detCol)
{
	int minorRow, minorCol;
	for (int i = 0; i < sizeMajor; ++i)
	{
		minorRow = i;
		if (i > detRow)
			--minorRow;

		for (int j = 0; j < sizeMajor; j++)
		{
			minorCol = j;
			if (j > detCol)
				--minorCol;
			if (i != detRow && j != detCol)
				minor[minorRow][minorCol] = major[i][j];
		}
	}
}

double detMatrix(double** A, int sizeA)
{
	if (sizeA == 1)
		return A[0][0];

	double det = 0.0;
	//Laplace expansion along the first row
	for (int i = 0; i < sizeA; ++i) 
	{
		int j = 0; // first row fixed
		double** D = new double* [sizeA - 1];
		for (int k = 0; k < sizeA - 1; ++k)
			D[k] = new double[sizeA - 1];

		minorMatrix(A, sizeA, D, i, j); 
		det += A[i][j] * pow(-1, i + j) * detMatrix(D, sizeA - 1);

		for (int k = 0; k < sizeA - 1; ++k)
			delete[] D[k];
		delete[] D;
	}
	return det;
}

int main(int argc, char* argv[])
{
	const int sizeA = 2;
	double** A = new double* [sizeA];
	for (int i = 0; i < sizeA; ++i)
		A[i] = new double[sizeA];
	
	A[0][0] = -4;
	A[0][1] = 2;
	A[1][0] = 1;
	A[1][1] = 1;


	std::cout << "A:";
	for (int i = 0; i < sizeA; ++i)
		for (int j = 0; j < sizeA; ++j)
		{
			if (j == 0) { std::cout << '\n'; }
			std::cout << A[i][j] << '\t';
		}

	std::cout << "\n\ndet(A) = " << detMatrix(A, sizeA) << '\n';

	//=========================================
	const int sizeC = 3;
	double** C = new double* [sizeC];
	for (int i = 0; i < sizeC; ++i)
		C[i] = new double[sizeC];

	C[0][0] = 1;
	C[0][1] = 3;
	C[0][2] = 2;
	C[1][0] = -1;
	C[1][1] = 2;
	C[1][2] = -2;
	C[2][0] = 1;
	C[2][1] = 1;
	C[2][2] = 1;

	std::cout << "\nC:";
	for (int i = 0; i < sizeC; ++i)
		for (int j = 0; j < sizeC; ++j)
		{
			if (j == 0) { std::cout << '\n'; }
			std::cout << C[i][j] << '\t';
		}

	std::cout << "\n\ndet(C) = " << detMatrix(C, sizeC) << '\n';

	for (int i = 0; i < 1000; ++i)///////////////////////////////////////
		detMatrix(C, sizeC);

	//=========================================
	// test of the function minorMatrix
	double** B = new double* [sizeA - 1];
	for (int i = 0; i < sizeA - 1; ++i)
		B[i] = new double[sizeA - 1];

	minorMatrix(A, sizeA, B, 1, 0);

	std::cout << "\n\nminor:";
	for (int i = 0; i < sizeA - 1; ++i)
		for (int j = 0; j < sizeA - 1; ++j)
		{
			if (j == 0) { std::cout << '\n'; }
			std::cout << B[i][j] << '\t';
		}
	

	//=========================================
	for (int i = 0; i < sizeA; ++i)
		delete[] A[i];
	delete[] A;

	for (int i = 0; i < sizeC; ++i)
		delete[] C[i];
	delete[] C;


	std::cin.get();
	return 0;
}