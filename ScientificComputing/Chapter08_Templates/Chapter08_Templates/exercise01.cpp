#include <iostream>
#include <cassert>
#include <iomanip>      // std::setprecision

template<unsigned int N> class ProbabilityArray
{
public:
	ProbabilityArray()
	{
		for (int i = 0; i < N; ++i)
			mData[i] = 0.0;
	}
private:
	double mData[N];
	double upperLim = 1.0;
	double lowerLim = 0.0;
public:
	double& operator[](int idx)
	{
		if (0 <= mData[idx] && mData[idx] <= 1)
			return mData[idx];
		else if ((-1e-6) <= mData[idx] && mData[idx] <= 0)
			return lowerLim;
		else if (1 <= mData[idx] && mData[idx] <= 1 + 1e-6)
			return upperLim;
		else
			assert(false);
	}
};

int main(int argc, char* argv[])
{
	ProbabilityArray<5> array01;
	array01[0] = 1 + 0.5e-6;
	array01[1] = 0.5;
	array01[2] = 0.64;
	// array01[3] = 1.3;
	array01[4] = -0.5e-6;

	for (int i = 0; i < 5; ++i)
		std::cout << std::setprecision(10) << array01[i] << "\n";


	std::cin.get();
	return 0;
}