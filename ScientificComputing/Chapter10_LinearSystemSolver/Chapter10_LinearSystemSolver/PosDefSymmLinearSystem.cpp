#include "PosDefSymmLinearSystem.hpp"
#include <cassert>

PosDefSymmLinearSystem::PosDefSymmLinearSystem(const Matrix& A, const Vector& b)
	: LinearSystem::LinearSystem(A, b)
{
	// check symmetry of the matrix
	for (int i = 1; i <= mSize; ++i)
		for (int j = 1; j <= mSize; ++j)
			if (i != j)
				assert(A(i, j) == A(j, i));
}

PosDefSymmLinearSystem::PosDefSymmLinearSystem(const PosDefSymmLinearSystem& LinSys)
	: LinearSystem::LinearSystem(LinSys)
{
	// private dummy copy constructor, not for use
}

Vector PosDefSymmLinearSystem::Solve(double tolerance)
{
// conjugate gradient method for solving linear systems

	// copy matrix A and vector b
	Matrix Ax = *mpA;
	Vector bx = *mpb;

	// initialization
	Vector uk(mSize); //initial guess uk = 0
	int k = 0;
	Vector r(mSize);
	r = bx - Ax * uk;
	Vector rprev(mSize);
	Vector p(mSize);
	double beta = 0;
	double alpha;

	auto transpose = [](const Vector& v) 
	{
		Matrix vT(1, v.GetSize());
		for (int i = 1; i <= v.GetSize(); ++i)
			vT(1, i) = v(i);
		return vT;
	};

	// find solution within the given tolerance
	while (r.CalculateNorm() >= tolerance)
	{		
		if (k > 0)
			beta = (transpose(r) * r)(1) / (transpose(rprev) * rprev)(1);

		p = r + p * beta;
		alpha = (transpose(r) * r)(1) / (transpose(p) * (Ax * p))(1);

		uk = uk + p * alpha;
		rprev = r;
		r = bx - Ax * uk;
		++k;
	}
	return uk;
}