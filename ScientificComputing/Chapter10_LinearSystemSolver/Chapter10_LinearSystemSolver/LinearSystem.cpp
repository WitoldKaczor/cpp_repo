#include "LinearSystem.hpp"
#include <cassert>

LinearSystem::LinearSystem(const Matrix& A, const Vector& b)
{
	// check of the system dimensions
	assert(A.GetNumRows() == A.GetNumCols()); //matrix is square
	assert(A.GetNumRows() == b.GetSize()); //matrix and vector

	// check of nonsingularity
	assert(fabs(A.determinant()) >= 1e-16);

	// set the size of the system
	mSize = b.GetSize();

	// set matrix and vector
	mpA = &A;
	mpb = &b;
}

LinearSystem::LinearSystem(const LinearSystem& LinSys)
{
	// private dummy copy constructor, not for use
}

Vector LinearSystem::Solve()
{//Gaussian elimination with pivoting
	
	// copy matrix A and vector b
	Matrix Ax = *mpA;
	Vector bx = *mpb;

	// pivoting
	double x = 0.0;
	int rowPiv;
	double tmpPiv;
	for (int i = 1; i <= mSize; ++i)
	{
		// search for biggest number in column
		rowPiv = i;
		for (int m = i; m <= mSize; ++m)
			if (Ax(m,i) > Ax(i,i)) rowPiv = m;

		// swap the rows of Ax and bx (pivoting)
		if (rowPiv != i)
		{
			tmpPiv = bx(rowPiv);
			bx(rowPiv) = bx(i);
			bx(i) = tmpPiv;
			for (int n = 1; n <= mSize; ++n)
			{
				tmpPiv = Ax(rowPiv,n);
				Ax(rowPiv,n) = Ax(i,n);
				Ax(i,n) = tmpPiv;
			}
		}
	}

	// transform Ax to upper triangular matrix
	for (int i = 1; i <= mSize; ++i)
		for (int k = i + 1; k <= mSize; ++k)
		{
			x = Ax(k,i) / Ax(i,i);
			for (int j = 1; j <= mSize; ++j)
				Ax(k,j) -= x * Ax(i,j);
			bx(k) -= x * bx(i);
		}

	// solving the system 
	Vector u(mSize);
	for (int i = mSize; i >= 1; --i)
	{
		double sum = 0.0;
		for (int k = i + 1; k <= mSize; ++k)
			sum += Ax(i,k) * u(k);

		u(i) = (1 / Ax(i,i)) * (bx(i) - sum);
	}

	return u;
}