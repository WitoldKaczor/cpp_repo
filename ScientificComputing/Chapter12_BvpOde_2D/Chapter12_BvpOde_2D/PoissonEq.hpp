#ifndef POISSONEQHEADERDEF
#define POISSONEQHEADERDEF

class PoissonEq
{
	friend class BvpOde;
private:
	// Function on RHS of PoissonEq
	double (*mpRhsFunc)(double x, double y);

	// Interval for domain
	double mXmin;
	double mXmax;
	double mYmin;
	double mYmax;
public:
	PoissonEq(double (*righthandSide)(double, double),
		double xMinimum, double xMaximum,
		double yMinimum, double yMaximum)
	{
		mpRhsFunc = righthandSide;
		mXmin = xMinimum;
		mXmax = xMaximum;
		mYmin = yMinimum;
		mYmax = yMaximum;
	}
};

#endif