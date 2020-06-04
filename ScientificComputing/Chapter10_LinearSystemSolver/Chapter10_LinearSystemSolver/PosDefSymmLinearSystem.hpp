#ifndef POSDEFSYMMLINEARSYSTEMHEADERDEF
#define POSDEFSYMMLINEARSYSTEMHEADERDEF

#include "LinearSystem.hpp"

class PosDefSymmLinearSystem : public LinearSystem
{// for solving of positive definite symmetric linear systems
public:
	PosDefSymmLinearSystem(const Matrix& A, const Vector& b);
	Vector Solve(double tolerance = 1e-6);
private:
	PosDefSymmLinearSystem(const PosDefSymmLinearSystem& LinSys);
};

#endif