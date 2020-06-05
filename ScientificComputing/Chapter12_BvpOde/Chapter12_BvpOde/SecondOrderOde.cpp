#include "SecondOrderOde.hpp"

SecondOrderOde::SecondOrderOde()
{
	mCoeffOfUxxIsSet = false;
	mCoeffOfUxIsSet = false;
	mCoeffOfUIsSet = false;
	mpRhsFuncIsSet = false;
	mXminIsSet = false;
	mXmaxIsSet = false;
}

SecondOrderOde::SecondOrderOde(double coeffUxx, double coeffUx, double coeffU,
	double (*righthandSide)(double), double xMinimum, double xMaximum)
{
	mCoeffOfUxxIsSet = true;
	mCoeffOfUxIsSet = true;
	mCoeffOfUIsSet = true;
	mpRhsFuncIsSet = true;
	mXminIsSet = true;
	mXmaxIsSet = true;

	mCoeffOfUxx = coeffUxx;
	mCoeffOfUx = coeffUx;
	mCoeffOfU = coeffU;
	mpRhsFunc = righthandSide;
	mXmin = xMinimum;
	mXmax = xMaximum;
}

void SecondOrderOde::SetCoeffOfUxx(double coeffUxx)
{
	mCoeffOfUxxIsSet = true;
	mCoeffOfUxx = coeffUxx;
	
}

void SecondOrderOde::SetCoeffOfUx(double coeffUx)
{
	mCoeffOfUxIsSet = true;
	mCoeffOfUx = coeffUx;
}

void SecondOrderOde::SetCoeffOfU(double coeffU)
{
	mCoeffOfUIsSet = true;
	mCoeffOfU = coeffU;
}

void SecondOrderOde::SetRhsFunc(double (*righthandSide)(double))
{
	mpRhsFuncIsSet = true;
	mpRhsFunc = righthandSide;
}

void SecondOrderOde::SetXmin(double xMinimum)
{
	mXminIsSet = true;
	mXmin = xMinimum;
}

void SecondOrderOde::SetXmax(double xMaximum)
{
	mXmaxIsSet = true;
	mXmax = xMaximum;
}
