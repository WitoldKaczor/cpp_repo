//Write a module for solving the n × n linear system Au = b using Gaussian
//elimination with pivoting, where A is nonsingular.

#include <iostream>
#include <fstream>
#include <cassert>

void GaussElimWithoutPivoting(double** A, double* b, double* u, int N);

void GaussElimWithPivoting(double** A, double* b, double* u, int N);

int main(int argc, char* argv[])
{
	const int nSystemSize = 4;

	// allocate memory
	double** A = new double*[nSystemSize];
	for (int i = 0; i < nSystemSize; ++i)
		A[i] = new double [nSystemSize];
	double* b = new double[nSystemSize];
	double* u = new double[nSystemSize];
	
	// define system, read from file
	std::ifstream readMatrixA;
	std::ifstream readVectorb;
	switch (nSystemSize)
	{
		case 3: 
		{
			readMatrixA.open("matrixA_dim3.dat");
			readVectorb.open("vectorb_dim3.dat");
			break; 
		}
		case 4: 
		{
			readMatrixA.open("matrixA_dim4.dat");
			readVectorb.open("vectorb_dim4.dat");
			break;
		}
	}
	assert(readMatrixA.is_open());
	for (int i = 0; i < nSystemSize; ++i)
		for (int j = 0; j < nSystemSize; ++j)
			readMatrixA >> A[i][j];
	readMatrixA.close();

	assert(readVectorb.is_open());
	for (int i = 0; i < nSystemSize; ++i)
		readVectorb >> b[i];
	readVectorb.close();


	// solving the system
	GaussElimWithPivoting(A, b, u, nSystemSize);


	// show system and solution 
	std::cout << "A:";
	for (int i = 0; i < nSystemSize; ++i)
		for (int j = 0; j < nSystemSize; ++j)
		{
			if (j == 0) { std::cout << '\n'; }
			std::cout << A[i][j] << '\t';
		}
	std::cout << "\n\nb:\n";
	for (int i = 0; i < nSystemSize; ++i)
		std::cout << b[i] << '\n';
	std::cout << "\n\nu:\n";
	for (int i = 0; i < nSystemSize; ++i)
		std::cout << u[i] << '\n';

	// deallocate memory
	for (int i = 0; i < nSystemSize; ++i)
		delete[] A[i];
	delete[] A;
	delete[] b;
	delete[] u;

	std::cin.get();
	return 0;
}

void GaussElimWithPivoting(double** A, double* b, double* u, int N)
{
	// copy A and b (no overwriting)
	double** Ax = new double* [N];
	for (int i = 0; i < N; ++i)
		Ax[i] = new double[N];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			Ax[i][j] = A[i][j];
	double* bx = new double[N];
	for (int i = 0; i < N; ++i)
		bx[i] = b[i];

	// pivoting
	double x = 0.0;
	int rowPiv;
	double tmpPiv;
	for (int i = 0; i < N; ++i)
	{
		// search for biggest number in column
		rowPiv = i;
		for (int m = i; m < N; ++m)
			if (Ax[m][i] > Ax[i][i]) rowPiv = m;

		// swap the rows of Ax and bx (pivoting)
		if (rowPiv != i)
		{
			tmpPiv = bx[rowPiv];
			bx[rowPiv] = bx[i];
			bx[i] = tmpPiv;
			for (int n = 0; n < N; ++n)
			{
				tmpPiv = Ax[rowPiv][n];
				Ax[rowPiv][n] = Ax[i][n];
				Ax[i][n] = tmpPiv;
			}
		}
	}

	// transform Ax to upper triangular matrix
	for (int i = 0; i < N; ++i)
		for (int k = i + 1; k < N; ++k)
		{
			x = Ax[k][i] / Ax[i][i];
			for (int j = 0; j < N; ++j)
				Ax[k][j] -= x * Ax[i][j];
			bx[k] -= x * bx[i];
		}

	//// show Ax and bx
	//std::cout << "Ax:";
	//for (int i = 0; i < N; ++i)
	//	for (int j = 0; j < N; ++j)
	//	{
	//		if (j == 0) { std::cout << '\n'; }
	//		std::cout << Ax[i][j] << '\t';
	//	}
	//std::cout << "\n\nbx:\n";
	//for (int i = 0; i < N; ++i)
	//	std::cout << bx[i] << '\n';
	//std::cout << "\n\n";

	// solving the system 
	for (int i = N - 1; i >= 0; --i)
	{
		double sum = 0.0;
		for (int k = i + 1; k < N; ++k)
			sum += Ax[i][k] * u[k];

		u[i] = (1 / Ax[i][i]) * (bx[i] - sum);
	}

	//deallocate Ax, bx
	for (int i = 0; i < N; ++i)
		delete[] Ax[i];
	delete[] Ax;
	delete[] bx;
}

void GaussElimWithoutPivoting(double** A, double* b, double* u, int N)
{
	double** Ax = new double* [N];
	for (int i = 0; i < N; ++i)
		Ax[i] = new double[N];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			Ax[i][j] = A[i][j];
	double* bx = new double[N];
	for (int i = 0; i < N; ++i)
		bx[i] = b[i];

	// transform Ax to upper triangular matrix
	double x = 0.0;
	for (int i = 0; i < N; ++i)
		for (int k = i + 1; k < N; ++k)
		{
			x = Ax[k][i] / Ax[i][i];
			for (int j = 0; j < N; ++j)
				Ax[k][j] -= x * Ax[i][j];
			bx[k] -= x * bx[i];
		}

	// show Ax and bx
	/*std::cout << "Ax:";
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			if (j == 0) { std::cout << '\n'; }
			std::cout << Ax[i][j] << '\t';
		}
	std::cout << "\n\nbx:\n";
	for (int i = 0; i < N; ++i)
		std::cout << bx[i] << '\n';
	std::cout << "\n\n";*/

	// solving the system 
	for (int i = N - 1; i >= 0; --i)
	{
		double sum = 0.0;
		for (int k = i + 1; k < N; ++k)
			sum += Ax[i][k] * u[k];

		u[i] = (1 / Ax[i][i]) * (bx[i] - sum);
	}

	//deallocate Ax, bx
	for (int i = 0; i < N; ++i)
		delete[] Ax[i];
	delete[] Ax;
	delete[] bx;
}