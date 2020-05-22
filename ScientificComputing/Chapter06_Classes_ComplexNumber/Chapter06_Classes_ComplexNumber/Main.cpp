#include "ComplexNumber.hpp"
#include <iostream>
#include <cassert>

int factorial(int x);
void MulScalarMatrix3x3(ComplexNumber** A, double scalar, ComplexNumber** Output);
void powMatrix3x3(ComplexNumber** A, int N, ComplexNumber** Output);
void expComplexMatrix(ComplexNumber** zArray, int iterNum, ComplexNumber** Output);

int main(int argc, char* argv[])
{
	ComplexNumber z1(4.0, 3.0);
	std::cout << "z1 = " << z1 << "\n";
	std::cout << "Modulus z1 = " << z1.CalculateModulus() << "\n";
	std::cout << "Argument z1 = " << z1.CalculateArgument() << "\n";

	ComplexNumber z2;
	z2 = z1.CalculatePower(3);
	std::cout << "z2 = z1*z1*z1 = " << z2 << "\n";
	std::cout << "Real part of z2 is " << z2.GetRealPart() << "\n";
	std::cout << "Imaginary part of z2 is " << z2.GetImaginaryPart() << "\n";

	ComplexNumber z3;
	z3 = -z2;
	std::cout << "z3 = -z2 = " << z3 << "\n";
	std::cout << "Complex conjugate of z3 is " << z3.CalculateConjugate() << "\n";
	std::cout << "z3 = " << z3 << "\n";

	ComplexNumber z4;
	z4 = z1 + z2;
	std::cout << "z4 = z1 + z2 = " << z4 << "\n";
	z4.SetToConjugate();
	std::cout << "z4 = " << z4 << "\n";

	ComplexNumber z5[2];
	z5[0] = z1;
	z5[1] = z2;
	std::cout << "Second element of z5 = z2 = " << z5[1] << "\n";
	
	ComplexNumber z6(3.5);
	std::cout << "z6 = " << z6 << "\n";
	std::cout << "Real part of z6 is " << RealPart(z6) << "\n";
	std::cout << "Imaginary part of z6 is " << ImaginaryPart(z6) << "\n";

	ComplexNumber z7;
	z7 = z1 * z2;
	std::cout << "z7 = z1 * z2 = " << z7 << "\n";
	
	ComplexNumber z8;
	z8 = z1 * 5;
	std::cout << "z8 = z1 * 5 = " << z8 << "\n";

	ComplexNumber z9;
	z9 = (ComplexNumber)2 * z2;
	std::cout << "z9 = 2 * z2 = " << z9 << "\n";

	ComplexNumber** zArray = new ComplexNumber* [3];
	for (int i = 0; i < 3; ++i)
		zArray[i] = new ComplexNumber[3];
	zArray[0][0] = ComplexNumber(1);	
	zArray[0][1] = ComplexNumber(1);	
	zArray[0][2] = ComplexNumber(0, 1);
	zArray[1][0] = ComplexNumber(0, 2);	
	zArray[1][1] = ComplexNumber(0, -1);
	zArray[1][2] = ComplexNumber(2, 2);
	zArray[2][0] = ComplexNumber(0);	
	zArray[2][1] = ComplexNumber(1, 0);
	zArray[2][2] = ComplexNumber(0);
	std::cout << "\nzArray";
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		{
			if (j == 0) { std::cout << '\n'; }
			std::cout << zArray[i][j] << '\t';
		}

	//// test of powMatrix3x3
	//ComplexNumber** zPowArray = new ComplexNumber * [3];
	//for (int i = 0; i < 3; ++i)
	//	zPowArray[i] = new ComplexNumber[3];
	//powMatrix3x3(zArray, 3, zPowArray);
	//std::cout << "\n\nzArray^x";
	//for (int i = 0; i < 3; ++i)
	//	for (int j = 0; j < 3; ++j)
	//	{
	//		if (j == 0) { std::cout << '\n'; }
	//		std::cout << zPowArray[i][j] << '\t';
	//	}
	//// test of MulScalarMatrix3x3 
	//MulScalarMatrix3x3(zArray, 2, zArray);
	//std::cout << "\n\nzArray*2";
	//for (int i = 0; i < 3; ++i)
	//	for (int j = 0; j < 3; ++j)
	//	{
	//		if (j == 0) { std::cout << '\n'; }
	//		std::cout << zArray[i][j] << '\t';
	//	}


	// exponential of the complex matrix
	for (int iter = 0; iter <= 10; ++iter)
	{
		ComplexNumber** Output = new ComplexNumber * [3];
		for (int i = 0; i < 3; ++i)
			Output[i] = new ComplexNumber[3];
		expComplexMatrix(zArray, iter, Output);

		std::cout << "\n\nexp(zArray), iter=" << iter << '\n';
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
			{
				if (j == 0) { std::cout << '\n'; }
				std::cout << Output[i][j] << '\t';
			}
		for (int i = 0; i < 3; ++i)
			delete[] Output[i];
		delete[] Output;
	}

	for (int i = 0; i < 3; ++i)
		delete[] zArray[i];
	delete[] zArray;


	std::cin.get();
	return 0;
}

void expComplexMatrix(ComplexNumber** zArray, int iterNum, ComplexNumber** Output)
{
	assert(iterNum >= 0);

	// allocate result and temp matrices and set it to zero
	ComplexNumber** resArray = new ComplexNumber * [3];
	for (int i = 0; i < 3; ++i)
		resArray[i] = new ComplexNumber[3];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			resArray[i][j] = 0;
	ComplexNumber** tmpArray = new ComplexNumber* [3];
	for (int i = 0; i < 3; ++i)
		tmpArray[i] = new ComplexNumber[3];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			tmpArray[i][j] = 0;

	// calculate the exponential
	for (int n = 0; n <= iterNum; ++n)
	{
		powMatrix3x3(zArray, n, tmpArray);
		MulScalarMatrix3x3(tmpArray, (1.0 / (double)factorial(n)), tmpArray);
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				resArray[i][j] = resArray[i][j] + tmpArray[i][j];
	}

	// write result to Output 
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			Output[i][j] = resArray[i][j];
	// deallocate result and temp matrices
	for (int i = 0; i < 3; ++i)
		delete[] tmpArray[i];
	delete[] tmpArray;
	for (int i = 0; i < 3; ++i)
		delete[] resArray[i];
	delete[] resArray;
}

int factorial(int x)
{
	if (x == 0 || x == 1)
		return 1;

	int res = 1;
	for (int i = 2; i <= x; ++i)
		res *= i;
	return res;
}

void MulScalarMatrix3x3(ComplexNumber** A, double scalar, ComplexNumber** Output)
{
	// multiplication: Output = scalar*A
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			Output[i][j] = A[i][j] * scalar;
}

void powMatrix3x3(ComplexNumber** A, int N, ComplexNumber** Output)
{
	// only non-negative power valid
	assert(N >= 0); 

	// when power is zero set the matrix 
	// to a identity matrix
	if (N == 0) 
	{
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
			{
				if (i == j)
				{
					Output[i][j] = 1;
				}
				else
				{
					Output[i][j] = 0;
				}
			}
		return;
	}

	// when power is one: Output=A
	if (N == 1)
	{
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				Output[i][j] = A[i][j];
		return;
	}

	// when N = 2 multiplicate the matrix once by itself
	if (N == 2)
	{
		// set output matrix to zero
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				Output[i][j] = 0;

		// matrix multiplication
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				for (int k = 0; k < 3; ++k)
					Output[i][j] = (A[i][k] * A[k][j]) + Output[i][j];

		return;
	}

	// when N > 2 multiplicate matrix by itself N-1 times
	// allocate temporary matrix and set it to Output
	ComplexNumber** M = new ComplexNumber* [3];
	for (int i = 0; i < 3; ++i)
		M[i] = new ComplexNumber[3];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			M[i][j] = A[i][j];

	// allocate result matrix
	ComplexNumber** M2 = new ComplexNumber* [3];
	for (int i = 0; i < 3; ++i)
		M2[i] = new ComplexNumber[3];

	for(int iter = 0; iter < N - 1; ++iter)
	{
		// set result matrix to zero
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				M2[i][j] = 0;
		// matrix multiplication
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				for (int k = 0; k < 3; ++k)
					M2[i][j] = M2[i][j] + (M[i][k] * A[k][j]);
		// set temp matrix to result
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				M[i][j] = M2[i][j];
	}

	// set Output matrix to the result
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			Output[i][j] = M2[i][j];

	// deallocate temporary matrices
	for (int i = 0; i < 3; ++i)
		delete[] M[i];
	delete[] M;
	for (int i = 0; i < 3; ++i)
		delete[] M2[i];
	delete[] M2;
}