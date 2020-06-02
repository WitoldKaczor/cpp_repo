#ifndef LINEARSYSTEMHEADERDEF
#define LINEARSYSTEMHEADERDEF

#include "Vector.hpp"
#include "Matrix.hpp"

class LinearSystem
{
private:
	int mSize = 0;
	const Matrix* mpA = 0;
	const Vector* mpb = 0;
public:
	LinearSystem(const Matrix& A, const Vector& b);
	Vector Solve();
private:
	LinearSystem(const LinearSystem& LinSys);
};

#endif