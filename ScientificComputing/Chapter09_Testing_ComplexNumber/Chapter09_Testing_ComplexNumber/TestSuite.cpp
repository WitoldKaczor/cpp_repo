#include "ComplexNumber.hpp"
#include <iostream>
#include <cmath>
#include <cassert>
#include <complex>
//#define M_PI_4     0.785398163397448309616  // pi/4

class ComplexNumberTestSuite
{
public:
	ComplexNumberTestSuite()
	{
		// the default constructor call all the tests methods
		TestDefaultConstructor();
		TestCustomisedConstructor();
		TestCalculatePower();
		TestAgainstStdLibrary();
		TestOperatorEqual();
		TestOperatorMinusUnary();
		TestOperatorPlus();
		TestOperatorMinus();
		TestMultiplcationByComplNum();
		TestMultiplcationByDouble();
		TestCalculateConjugate();
		TestSetToConjugate();
		
		// inform the user when the tests are passed
		std::cout << "All tests passed\n";
	}

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

// test methods
public: 
	void TestDefaultConstructor()
	{
		// Test default constructor sets complex number to zero
		ComplexNumber z;
		double mod_z = z.CalculateModulus();
		TS_ASSERT_DELTA(mod_z, 0.0, 1.0e-16);
		double arg_z = z.CalculateArgument();
		TS_ASSERT_DELTA(arg_z, 0.0, 1.0e-16);
	}

	void TestCustomisedConstructor()
	{
		// Use constructor that allows us to specify
		// real and imaginary parts of a complex number
		double real = 4.0;
		double imaginary = -3.0;
		ComplexNumber z(real, imaginary);

		// Test that modulus is correct
		double modulus = z.CalculateModulus();
		double true_modulus = 5.0; // (3,4,5) triangle
		TS_ASSERT_DELTA(modulus, true_modulus, 1.0e-8);

		// Test argument is correct via different function
		double argument = z.CalculateArgument();
		double true_argument = -asin(3.0 / 5.0);
		TS_ASSERT_DELTA(argument, true_argument, 1.0e-8);
	}

	void TestCalculatePower()
	{
		// Specify a complex number, z, and calculate the
		// modulus and argument
		double real = 4.0;
		double imaginary = -3.0;
		ComplexNumber z(real, imaginary);
		double modulus_z = z.CalculateModulus();
		double argument_z = z.CalculateArgument();

		// Calculate z*z and calculate the modulus and
		// argument of z*z
		ComplexNumber z_squared = z.CalculatePower(2.0);
		double mod_z_squared = z_squared.CalculateModulus();
		double arg_z_squared = z_squared.CalculateArgument();

		// Test that:
		// modulus of z*z = (modulus of z)*(modulus of z)
		TS_ASSERT_DELTA(mod_z_squared, modulus_z * modulus_z, 1.0e-8);

		// Test that:
		// argument of z*z = 2*(argument of z)
		TS_ASSERT_DELTA(arg_z_squared, 2.0 * argument_z, 1.0e-8);
	}

	void TestAgainstStdLibrary()
	{
		ComplexNumber z(4.0, -3.0);
		std::complex<double> std_z(4.0, -3.0);
		TS_ASSERT_DELTA(z.CalculateArgument(), arg(std_z), 1e-8);
		TS_ASSERT_DELTA(z.CalculateModulus(), abs(std_z), 1e-8);
		// Raise both numbers to power 5
		ComplexNumber z_5 = z.CalculatePower(5.0);
		std::complex<double> std_z_5 = pow(std_z, 5.0);
		// Check they are the same
		TS_ASSERT_DELTA(z_5.CalculateArgument(), arg(std_z_5), 1e-8);
		TS_ASSERT_DELTA(z_5.CalculateModulus(), abs(std_z_5), 1e-8);
	}

	void TestOperatorEqual()
	{
		ComplexNumber z1(-1.0, 2.0);
		ComplexNumber z2 = z1;
		TS_ASSERT_DELTA(z2.GetRealPart(), -1.0, 1e-8);
		TS_ASSERT_DELTA(z2.GetImaginaryPart(), 2.0, 1e-8);
	}

	void TestOperatorMinusUnary()
	{
		ComplexNumber z1(-1.0, 0.0);
		ComplexNumber z2 = -z1;
		TS_ASSERT_DELTA(z2.GetRealPart(), 1.0, 1e-8);
		TS_ASSERT_DELTA(z2.GetImaginaryPart(), 0.0, 1e-8);
	}
	
	void TestOperatorPlus()
	{
		ComplexNumber z1(3.5, -1.0);
		ComplexNumber z2(-3.5, -2.0);
		ComplexNumber z3 = z1 + z2;
		TS_ASSERT_DELTA(z3.GetRealPart(), 0.0, 1e-8);
		TS_ASSERT_DELTA(z3.GetImaginaryPart(), -3.0, 1e-8);
	}

	void TestOperatorMinus()
	{
		ComplexNumber z1(3.5, -1.0);
		ComplexNumber z2(-3.5, -2.0);
		ComplexNumber z3 = z1 - z2;
		TS_ASSERT_DELTA(z3.GetRealPart(), 7.0, 1e-8);
		TS_ASSERT_DELTA(z3.GetImaginaryPart(), 1.0, 1e-8);
	}
	
	void TestMultiplcationByComplNum()
	{
		ComplexNumber z1(3.5, -1.0);
		ComplexNumber z2(1.0, 0.5);
		ComplexNumber z3 = z1 * z2;
		TS_ASSERT_DELTA(RealPart(z3), 4.0, 1e-8);
		TS_ASSERT_DELTA(ImaginaryPart(z3), 0.75, 1e-8);
		ComplexNumber z4 = z2 * z1;
		TS_ASSERT_DELTA(RealPart(z4), 4.0, 1e-8);
		TS_ASSERT_DELTA(ImaginaryPart(z4), 0.75, 1e-8);
	}

	void TestMultiplcationByDouble()
	{
		ComplexNumber z1(4.0, -1.0);
		double x = 3.0;
		ComplexNumber z2 = z1 * x;
		TS_ASSERT_DELTA(RealPart(z2), 12.0, 1e-8);
		TS_ASSERT_DELTA(ImaginaryPart(z2), -3.0, 1e-8);
		ComplexNumber z3 = (ComplexNumber)x * z1;
		TS_ASSERT_DELTA(RealPart(z3), 12.0, 1e-8);
		TS_ASSERT_DELTA(ImaginaryPart(z3), -3.0, 1e-8);
	}
	
	void TestCalculateConjugate()
	{
		ComplexNumber z1(4.0, -1.0);
		ComplexNumber z2 = z1.CalculateConjugate();
		TS_ASSERT_DELTA(RealPart(z2), 4.0, 1e-8);
		TS_ASSERT_DELTA(ImaginaryPart(z2), 1.0, 1e-8);
	}

	void TestSetToConjugate()
	{
		ComplexNumber z1(4.0, -1.0);
		z1.SetToConjugate();
		TS_ASSERT_DELTA(RealPart(z1), 4.0, 1e-8);
		TS_ASSERT_DELTA(ImaginaryPart(z1), 1.0, 1e-8);
	}
};

int main(int argc, char* argv[])
{
	std::cout << "test suite\n\n";

	// all tests made within default constructor
	ComplexNumberTestSuite testSuite01;

	std::cin.get();
	return 0;
}