//Write a module for solving the 3 × 3 linear system Au = b where A is nonsingular.

#include <iostream>
#include <cassert>

double det3x3Calc(double** A)
{
	double det	= A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1])
				- A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0])
				+ A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
	return det;
}

double det2x2Calc(double** A)
{
	double det	= (A[0][0] * A[1][1]) - (A[0][1] * A[1][0]);
	return det;
}

void mulScalarMatrix(double** A, double scalar)
{
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			A[i][j] = scalar * A[i][j];
}

void mulMatrixVector(double** A, double* vecIn, double* vecOut)
{
	// set vecOut to zero vector
	for (int i = 0; i < 3; ++i)
		vecOut[i] = 0;

	// multiplication: vecOut = A * vecIn
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			vecOut[i] += A[i][j] * vecIn[j];
}

double cofactor(double** A, int detRow, int detCol)
{
	double** tmpMinor = new double* [2];
	for (int i = 0; i < 2; ++i)
		tmpMinor[i] = new double[2];

	int minorRow, minorCol;
	for (int i = 0; i < 3; ++i)
	{
		minorRow = i;
		if (i > detRow)
			--minorRow;

		for (int j = 0; j < 3; j++)
		{
			minorCol = j;
			if (j > detCol)
				--minorCol;
			if (i != detRow && j != detCol)
				tmpMinor[minorRow][minorCol] = A[i][j];
		}
	}
	double det = det2x2Calc(tmpMinor);

	for (int i = 0; i < 2; ++i)
		delete[] tmpMinor[i];
	delete[] tmpMinor;

	if ((detRow + detCol) % 2 == 0)
		return det;
	else 
		return -det;
}

void transpMatrix(double** A, double** transpA)
{
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			transpA[i][j] = A[j][i];
}

void inverseCalc(double** A, double** invA)
{
	double detA = det3x3Calc(A);
	assert(fabs(detA) > 1e-10); //check for nonsingularity

	// cofactor matrix
	double** C = new double* [3];
	for (int i = 0; i < 3; ++i)
		C[i] = new double[3];

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			C[i][j] = cofactor(A, i, j);

	// adjugate matrix
	transpMatrix(C, invA);

	// inverse matrix
	mulScalarMatrix(invA, (1.0 / detA));

	//delete C
	for (int i = 0; i < 3; ++i)
		delete[] C[i];
	delete[] C;
}

void LinSys3x3Solve(double** A, double* u, double* b)
{
	double** invA = new double* [3];
	for (int i = 0; i < 3; ++i)
		invA[i] = new double[3];

	inverseCalc(A, invA);

	mulMatrixVector(invA, b, u);

	for (int i = 0; i < 3; ++i)
		delete[] invA[i];
	delete[] invA;
}

int main(int argc, char* argv[])
{
	// definition A
	const int sizeA = 3;
	double** A = new double* [sizeA];
	for (int i = 0; i < sizeA; ++i)
		A[i] = new double[sizeA];

	A[0][0] = 1;
	A[0][1] = 3;
	A[0][2] = 2;
	A[1][0] = -1;
	A[1][1] = 2;
	A[1][2] = -2;
	A[2][0] = 1;
	A[2][1] = 1;
	A[2][2] = 1;

	//definition b
	double* b = new double[3];
	b[0] = 1;
	b[1] = 0;
	b[2] = 1;

	// show A and b
	std::cout << "A:";
	for (int i = 0; i < sizeA; ++i)
		for (int j = 0; j < sizeA; ++j)
		{
			if (j == 0) { std::cout << '\n'; }
			std::cout << A[i][j] << '\t';
		}
	std::cout << "\n\nb:\n";
	for (int i = 0; i < sizeA; ++i)
		std::cout << b[i] << '\n';


	//allocation u
	double* u = new double[3];

	//solve system
	LinSys3x3Solve(A, u, b);

	//show u 
	std::cout << "\n\nu:\n";
	for (int i = 0; i < sizeA; ++i)
		std::cout << u[i] << '\n';


	// dealloc A, b, u
	for (int i = 0; i < 3; ++i)
		delete[] A[i];
	delete[] A;
	delete[] b;
	delete[] u;

	std::cin.get();
	return 0;
}

