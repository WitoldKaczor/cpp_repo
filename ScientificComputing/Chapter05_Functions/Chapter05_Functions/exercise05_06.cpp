//ex05 Write a function Multiply that may be used to multiply two matrices given
//the matrices and the size of both matrices. Use assertions to verify that the matrices
//are of suitable sizes to be multiplied

//ex06 Overload the function Multiply written in the previous exercise so that it may
//be used to multiply :
//1. a vector and a matrix of given sizes;
//2. a matrix and a vector of given sizes;
//3. a scalar and a matrix of a given size; and
//4. a matrix of a given size and a scalar.

#include <iostream>
#include <cassert>

double** Multiply(double** A, int rowA, int colA, double** B, int rowB, int colB); // matrix * matrix
double** Multiply(double* v, int rowV, double** A, int rowA, int colA ); // vector * matrix (1.)
double* Multiply(double** A, int rowA, int colA, double* v, int rowV); // matrix * vector (2.)
double** Multiply(double scalar, double** A, int rowA, int colA); // scalar * matrix (3.)
double** Multiply(double** A, int rowA, int colA, double scalar); // matrix * scalar (4.)

int main()
{
	//define size of the matrices
	const int rowA = 4;
	const int colA = 2;
	const int rowB = 2;
	const int colB = 2;
	
	// memory allocation for A
	double** A = new double* [rowA];
	for (int i = 0; i < rowA; ++i)
		A[i] = new double[colA];
	
	// memory allocation for B
	double** B = new double* [rowB];
	for (int i = 0; i < rowB; ++i)
		B[i] = new double[colB];

	// A init
	A[0][0] = 2;
	A[0][1] = 0;
	A[1][0] = 0;
	A[1][1] = 2;
	A[2][0] = 0;
	A[2][1] = 1;
	A[3][0] = 3;
	A[3][1] = 1;

	// B init
	B[0][0] = 0;
	B[0][1] = 1;
	B[1][0] = 3;
	B[1][1] = 1.5;

	//matrix multiplication: M = A*B
	double** M = Multiply(A, rowA, colA, B, rowB, colB);
	// show M 
	std::cout << "M = A * B";
	for (int i = 0; i < rowA; ++i)
		for (int j = 0; j < colB; ++j)
		{
			if (j == 0) { std::cout << '\n'; }
			std::cout << M[i][j] << '\t';
		}

	// deallocate memory of M
	for (int i = 0; i < rowA; ++i)
		delete[] M[i];
	delete[] M;

	//=============================================
	//define and allocate C, v and a
	const int rowC = 1;
	const int colC = 3;
	double** C = new double* [rowC];
	C[0] = new double[colC];
	C[0][0] = 8;
	C[0][1] = 5;
	C[0][2] = 1;

	const int rowV = 3;
	double* v = new double[rowV];
	v[0] = 1;
	v[1] = -5;
	v[2] = 0;

	double a = 2;

	// multiplication: M2 = v * C
	double** M2 = Multiply(v, rowV, C, rowC, colC);
	// show M 
	std::cout << "\n\nM2 = v * C";
	for (int i = 0; i < rowV; ++i)
		for (int j = 0; j < colC; ++j)
		{
			if (j == 0) { std::cout << '\n'; }
			std::cout << M2[i][j] << '\t';
		}

	// deallocate memory of M2
	for (int i = 0; i < rowV; ++i)
		delete[] M2[i];
	delete[] M2;


	// multiplication: w = C * v
	double* w = Multiply(C, rowC, colC, v, rowV);
	// show w 
	std::cout << "\n\nw = C * v\n";
	for (int i = 0; i < rowC; ++i)
		std::cout << w[i] << '\n';

	// deallocate memory of w
	delete[] w;


	// multiplication: M3 = a * B
	double** M3 = Multiply(a, B, rowB, colB);
	// show M3
	std::cout << "\n\nM3 = a * B";
	for (int i = 0; i < rowB; ++i)
		for (int j = 0; j < colB; ++j)
		{
			if (j == 0) { std::cout << '\n'; }
			std::cout << M3[i][j] << '\t';
		}
	// deallocate memory of M3
	for (int i = 0; i < rowB; ++i)
		delete[] M3[i];
	delete[] M3;


	// multiplication: M4 = B * a
	double** M4 = Multiply(B, rowB, colB, a);
	// show M4
	std::cout << "\n\nM4 = B * a";
	for (int i = 0; i < rowB; ++i)
		for (int j = 0; j < colB; ++j)
		{
			if (j == 0) { std::cout << '\n'; }
			std::cout << M4[i][j] << '\t';
		}
	// deallocate memory of M4
	for (int i = 0; i < rowB; ++i)
		delete[] M4[i];
	delete[] M4;

	//=============================================
	// deallocate memory of A
	for (int i = 0; i < rowA; ++i)
		delete[] A[i];
	delete[] A;
	// deallocate memory of B
	for (int i = 0; i < rowB; ++i)
		delete[] B[i];
	delete[] B;
	// deallocate memory of C
	for (int i = 0; i < rowC; ++i)
		delete[] C[i];
	delete[] C;
	// deallocate memory of v
	delete[] v;

	
	std::cin.get();
	return 0;
}

double** Multiply(double** A, int rowA, int colA, double** B, int rowB, int colB)
{
	assert(colA == rowB); // matrix dimension check

	// memory allocation for C
	double** C = new double* [rowA];
	for (int i = 0; i < rowA; ++i)
		C[i] = new double[colB];

	// set C to zero matrix
	for (int i = 0; i < rowA; ++i)
		for (int j = 0; j < colB; ++j)
			C[i][j] = 0;

	// matrix multiplication: C = A*B
	for (int i = 0; i < rowA; ++i)
		for (int j = 0; j < colB; ++j)
			for (int k = 0; k < colA; ++k)
				C[i][j] += A[i][k] * B[k][j];

	// return C pointer
	return C;
}

double** Multiply(double* v, int rowV, double** A, int rowA, int colA) // vector * matrix (1.)
{
	assert(rowA==1); // matrix dimension check

	// memory allocation for C
	double** C = new double* [rowV];
	for (int i = 0; i < rowV; ++i)
		C[i] = new double[colA];

	// set C to zero matrix
	for (int i = 0; i < rowV; ++i)
		for (int j = 0; j < colA; ++j)
			C[i][j] = 0;

	// matrix multiplication: C = A*B
	for (int i = 0; i < rowV; ++i)
		for (int j = 0; j < colA; ++j)
			C[i][j] += v[i] * A[0][j];

	// return C pointer
	return C;
}

double* Multiply(double** A, int rowA, int colA, double* v, int rowV) // matrix * vector (2.)
{
	assert(colA == rowV); // matrix dimension check

	// memory allocation for w
	double* w = new double [rowA];

	// set w to zero vector
	for (int i = 0; i < rowA; ++i)
		w[i] = 0;

	// multiplication: w = A*v
	for (int i = 0; i < rowA; ++i)
		for (int j = 0; j < rowV; ++j)
				w[i] += A[i][j] * v[j];

	// return w pointer
	return w;
}

double** Multiply(double scalar, double** A, int rowA, int colA) // scalar * matrix (3.)
{
	// memory allocation for C
	double** C = new double* [rowA];
	for (int i = 0; i < rowA; ++i)
		C[i] = new double[colA];

	// multiplication: C = scalar*A
	for (int i = 0; i < rowA; ++i)
		for (int j = 0; j < colA; ++j)
			C[i][j] = scalar * A[i][j];

	// return C pointer
	return C;
}

double** Multiply(double** A, int rowA, int colA, double scalar) // matrix * scalar (4.)
{
	return Multiply(scalar, A, rowA, colA); // multiplication is commutative
}