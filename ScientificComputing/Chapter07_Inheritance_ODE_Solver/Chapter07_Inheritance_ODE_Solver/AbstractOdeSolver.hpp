#ifndef ABSTRACTODESOLVERDEF
#define ABSTRACTODESOLVERDEF

class AbstractOdeSolver
{
// member variables
protected:
	double stepSize;
	double initialTime;
	double finalTime;
	double initialValue;

// methods
public:
	void SetStepSize(double h);
	void SetTimeInterval(double t0, double t1);
	void SetInitialValue(double y0);
	virtual void SolveEquation(double (*pRightHandSide) (double, double)) = 0;
};

#endif