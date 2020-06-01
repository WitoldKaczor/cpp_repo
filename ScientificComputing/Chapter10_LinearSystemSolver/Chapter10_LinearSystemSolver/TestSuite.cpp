#include "Vector.hpp"
#include <iostream>
#include <cassert>

class TestSuiteVector
{
public:
	TestSuiteVector()
	{
		// all the test methods are called 
		// in the default constructor
		TestSizeConstructor(); 
		TestCopyConstructor();
		TestGetSize();
		TestReadFunction();
		TestParenthesesOperator();
		TestAssignment();
		TestUnaryPlus();
		TestUnaryMinus();
		TestAddition();
		TestSubtraction();
		TestMulitplicationByScalar();
		TestCalculateNorm();
		TestLengthFunction();

		// inform the user when the tests are passed
		std::cout << "All tests passed\n";
	}

private:
	void TS_ASSERT(bool expression)
	{
		assert(expression);
	}
	void TS_ASSERT_DELTA(double var1, double var2, double tolerance)
	{
		assert(fabs(var1 - var2) <= tolerance);
	}
	void TS_ASSERT_DIFFERS(int var1, int var2)
	{
		assert(var1 != var2);
	}
	void TS_ASSERT_EQUALS(int var1, int var2)
	{
		assert(var1 == var2);
	}
	void TS_ASSERT_LESS_THAN_EQUALS(double var1, double var2)
	{
		assert(var1 <= var2);
	}
	
	//-----------------------------------------
	void TestSizeConstructor()
	{//Vector(int size);
		const int N = 5;
		Vector v1(N);
		for (int i = 0; i < N; ++i)
			TS_ASSERT_DELTA(v1[i], 0.0, 1e-16);
	}
	
	void TestCopyConstructor()
	{//Vector(const Vector& otherVector);
		const int N = 5;
		Vector v1(N);
		for (int i = 0; i < N; ++i)
			v1[i] = i;
		Vector v2 = v1;
		for (int i = 0; i < N; ++i)
			v1[i] = 0.0;
		for (int i = 0; i < N; ++i)
			TS_ASSERT_DELTA(v2[i], (double)i, 1e-16);
	}

	void TestGetSize()
	{//int GetSize() const;
		const int N = 5;
		Vector v1(N);
		TS_ASSERT_EQUALS(v1.GetSize(), N);
	}
	
	void TestReadFunction()
	{//double Read(int i) const; // read-only zero-based indexing 
		const int N = 5;
		Vector v1(N);
		for (int i = 0; i < N; ++i)
			TS_ASSERT_DELTA(v1.Read(i), 0.0, 1e-16);
	}

	void TestParenthesesOperator()
	{//double& operator()(int i); // one-based indexing
		const int N = 5;
		Vector v1(N);
		for (int i = 0; i < N; ++i)
			v1[i] = i;
		for (int i = 1; i <= N; ++i)
			TS_ASSERT_DELTA(v1(i), (double)i-1.0, 1e-16);
	}

	void TestAssignment()
	{//Vector& operator=(const Vector& otherVector);
		const int N = 5;
		Vector v1(N);
		for (int i = 0; i < N; ++i)
			v1[i] = i;
		Vector v2(N);
		v2 = v1;
		for (int i = 0; i < N; ++i)
			v1[i] = 0.0;
		for (int i = 0; i < N; ++i)
			TS_ASSERT_DELTA(v2[i], (double)i, 1e-16);
	}

	void TestUnaryPlus()
	{//Vector operator+() const; // unary +
		const int N = 5;
		Vector v1(N);
		for (int i = 0; i < N; ++i)
			v1[i] = i;
		Vector v2(N);
		v2 = +v1;
		for (int i = 0; i < N; ++i)
			v1[i] = 0.0;
		for (int i = 0; i < N; ++i)
			TS_ASSERT_DELTA(v2[i], (double)i, 1e-16);
	}

	void TestUnaryMinus()
	{//Vector operator-() const; // unary -
		const int N = 5;
		Vector v1(N);
		for (int i = 0; i < N; ++i)
			v1[i] = i;
		Vector v2(N);
		v2 = -v1;
		for (int i = 0; i < N; ++i)
			v1[i] = 0.0;
		for (int i = 0; i < N; ++i)
			TS_ASSERT_DELTA(v2[i], -(double)i, 1e-16);
	}
	
	void TestAddition()
	{//Vector operator+(const Vector& v1) const; // binary +
		const int N = 5;
		Vector v1(N);
		Vector v2(N);
		Vector v3(N);
		Vector v4(N);
		for (int i = 0; i < N; ++i)
		{
			v1[i] = (double)i;
			v2[i] = 3 * (double)i;
			v3[i] = 4 * (double)i;
		}
		v4 = v1 + v2;
		for (int i = 0; i < N; ++i)
			TS_ASSERT_DELTA(v3[i], v4[i], 1e-16);
	}
	
	void TestSubtraction()
	{//Vector operator-(const Vector& v1) const; // binary -
		const int N = 5;
		Vector v1(N);
		Vector v2(N);
		Vector v3(N);
		Vector v4(N);
		for (int i = 0; i < N; ++i)
		{
			v1[i] = 4 * (double)i;
			v2[i] = (double)i;
			v3[i] = 3 * (double)i;
		}
		v4 = v1 - v2;
		for (int i = 0; i < N; ++i)
			TS_ASSERT_DELTA(v3[i], v4[i], 1e-16);
	}

	void TestMulitplicationByScalar()
	{//Vector operator*(double a) const; // scalar multiplication
		const int N = 5;
		Vector v1(N);
		Vector v2(N);
		Vector v3(N);
		for (int i = 0; i < N; ++i)
		{
			v1[i] = (double)i;
			v2[i] = 3 * (double)i;
		}
		v3 = v1 * 3;
		for (int i = 0; i < N; ++i)
			TS_ASSERT_DELTA(v2[i], v3[i], 1e-16);
	}

	void TestCalculateNorm()
	{//double CalculateNorm(int p = 2) const;// p-norm method
		const int p = 2;
		const int N = 5;
		Vector v1(N);
		double sum = 0.0, norm;
		for (int i = 0; i < N; ++i)
		{
			v1[i] = (double)i;
			sum += pow(fabs(i), p);
		}
		norm = pow(sum, 1.0 / ((double)(p)));

		TS_ASSERT_DELTA(v1.CalculateNorm(p), norm, 1e-16);
	}
	
	void TestLengthFunction()
	{//friend int length(const Vector& v);// declare length function as a friend
		const int N = 5;
		Vector v1(N);
		TS_ASSERT_EQUALS(length(v1), N);
	}
};

int main(int argc, char* argv[])
{
	std::cout << "TestSuite: ";

	TestSuiteVector obj01;


	std::cin.get();
	return 0;
}