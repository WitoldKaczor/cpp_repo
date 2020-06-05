#ifndef SECONDORDERODEHEADERDEF
#define SECONDORDERODEHEADERDEF

class SecondOrderOde
{
	// The boundary value class is able to
	// access the coefficients etc. of this equation
	friend class BvpOde;
private:
	// Coefficients on LHS of ODE
	double mCoeffOfUxx;
	double mCoeffOfUx;
	double mCoeffOfU;

	// Function on RHS of ODE
	double (*mpRhsFunc)(double x);

	// Interval for domain
	double mXmin;
	double mXmax;

	// Bool variables for set check
	bool mCoeffOfUxxIsSet;
	bool mCoeffOfUxIsSet;
	bool mCoeffOfUIsSet;
	bool mpRhsFuncIsSet;
	bool mXminIsSet;
	bool mXmaxIsSet;
public:
	SecondOrderOde();
	SecondOrderOde(double coeffUxx, double coeffUx, double coeffU,
		double (*righthandSide)(double), double xMinimum, double xMaximum);
	
	void SetCoeffOfUxx(double coeffUxx);
	void SetCoeffOfUx(double coeffUx);
	void SetCoeffOfU(double coeffU);
	void SetRhsFunc(double (*righthandSide)(double));
	void SetXmin(double xMinimum);
	void SetXmax(double xMaximum);
};

#endif