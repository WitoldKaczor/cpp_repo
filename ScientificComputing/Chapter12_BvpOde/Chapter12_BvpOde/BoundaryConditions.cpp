#include "BoundaryConditions.hpp"

BoundaryConditions::BoundaryConditions()
{
	mLhsBcIsDirichlet = false;
	mRhsBcIsDirichlet = false;
	mLhsBcIsNeumann = false;
	mRhsBcIsNeumann = false;
	mLhsBcValue = 0;
	mRhsBcValue = 0;
}

void BoundaryConditions::SetLhsDirichletBc(double lhsValue)
{
	mLhsBcIsDirichlet = true;
	mLhsBcIsNeumann = false;
	mLhsBcValue = lhsValue;
}

void BoundaryConditions::SetRhsDirichletBc(double rhsValue)
{
	mRhsBcIsDirichlet = true;
	mRhsBcIsNeumann = false;
	mRhsBcValue = rhsValue;
}

void BoundaryConditions::SetLhsNeumannBc(double lhsDerivValue)
{
	mLhsBcIsDirichlet = false;
	mLhsBcIsNeumann = true;
	mLhsBcValue = lhsDerivValue;
}

void BoundaryConditions::SetRhsNeumannBc(double rhsDerivValue)
{
	mRhsBcIsDirichlet = false;
	mRhsBcIsNeumann = true;
	mRhsBcValue = rhsDerivValue;
}