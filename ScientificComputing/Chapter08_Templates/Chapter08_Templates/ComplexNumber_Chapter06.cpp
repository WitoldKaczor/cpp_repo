#ifndef COMPLEXNUMBERCPPDEF
#define COMPLEXNUMBERCPPDEF
#include "ComplexNumber_Chapter06.hpp"
#include <cmath>

// Override default constructor
// Set real and imaginary parts to zero
ComplexNumber::ComplexNumber()
{
    mRealPart = 0.0;
    mImaginaryPart = 0.0;
}

// Constructor that sets complex number z=x+iy
ComplexNumber::ComplexNumber(double x, double y)
{
    mRealPart = x;
    mImaginaryPart = y;
}

// Copy-constructor
ComplexNumber::ComplexNumber(const ComplexNumber& z)
{
    mRealPart = z.mRealPart;
    mImaginaryPart = z.mImaginaryPart;
}

// Method for computing the modulus of a
// complex number
double ComplexNumber::CalculateModulus() const
{
    return sqrt(mRealPart * mRealPart +
        mImaginaryPart * mImaginaryPart);
}

// Method for computing the argument of a
// complex number
double ComplexNumber::CalculateArgument() const
{
    return atan2(mImaginaryPart, mRealPart);
}

// Method for raising complex number to the power n
// using De Moivre's theorem - first complex
// number must be converted to polar form
ComplexNumber ComplexNumber::CalculatePower(double n) const
{
    if (n == 0)
        return ComplexNumber(1);

    if (n == 1)
        return ComplexNumber(mRealPart, mImaginaryPart);

    if (mRealPart == 0 && mImaginaryPart == 0)
        return ComplexNumber(0, 0);

    double modulus = CalculateModulus();
    double argument = CalculateArgument();
    double mod_of_result = pow(modulus, n);
    double arg_of_result = argument * n;
    double real_part = mod_of_result * cos(arg_of_result);
    double imag_part = mod_of_result * sin(arg_of_result);
    return ComplexNumber(real_part, imag_part);
}

// Overloading the = (assignment) operator
ComplexNumber& ComplexNumber::
operator=(const ComplexNumber& z)
{
    mRealPart = z.mRealPart;
    mImaginaryPart = z.mImaginaryPart;
    return *this;
}

// Overloading the unary - operator
ComplexNumber ComplexNumber::operator-() const
{
    ComplexNumber w;
    w.mRealPart = -mRealPart;
    w.mImaginaryPart = -mImaginaryPart;
    return w;
}

// Overloading the binary + operator
ComplexNumber ComplexNumber::
operator+(const ComplexNumber& z) const
{
    ComplexNumber w;
    w.mRealPart = mRealPart + z.mRealPart;
    w.mImaginaryPart = mImaginaryPart + z.mImaginaryPart;
    return w;
}

// Overloading the binary - operator
ComplexNumber ComplexNumber::
operator-(const ComplexNumber& z) const
{
    ComplexNumber w;
    w.mRealPart = mRealPart - z.mRealPart;
    w.mImaginaryPart = mImaginaryPart - z.mImaginaryPart;
    return w;
}

// Overloading the insertion << operator
std::ostream& operator<<(std::ostream& output,
    const ComplexNumber& z)
{
    // Format as "(a + bi)" or as "(a - bi)"
    output << "(" << z.mRealPart << " ";
    if (z.mImaginaryPart >= 0.0)
    {
        output << "+ " << z.mImaginaryPart << "i)";
    }
    else
    {
        // z.mImaginaryPart < 0.0
        // Replace + with minus sign 
        output << "- " << -z.mImaginaryPart << "i)";
    }
    return output;
}

// Method for getting the real part
// of complex number
double ComplexNumber::GetRealPart() const
{
    return mRealPart;
}

// Method for getting the imaginary part
// of complex number
double ComplexNumber::GetImaginaryPart() const
{
    return mImaginaryPart;
}

// Friend function for getting the real part
// of complex number
double RealPart(const ComplexNumber& z)
{
    return z.mRealPart;
}

// Friend function for getting the imaginary part
// of complex number
double ImaginaryPart(const ComplexNumber& z)
{
    return z.mImaginaryPart;
}

// Method returning the complex conjugate
//x - iy of a complex number x + iy
ComplexNumber ComplexNumber::CalculateConjugate() const
{
    return ComplexNumber(mRealPart,-mImaginaryPart);
}

// Method setting the complex number x + iy
// to the complex conjugate x - iy
void ComplexNumber::SetToConjugate()
{
    mImaginaryPart *= -1;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& z) const
{
    double realTmp = mRealPart * z.mRealPart - mImaginaryPart * z.mImaginaryPart;
    double imagTmp = mRealPart * z.mImaginaryPart + mImaginaryPart * z.mRealPart;
    return ComplexNumber(realTmp, imagTmp);
}

ComplexNumber ComplexNumber::operator*(double x) const
{
    double realTmp = mRealPart * x;
    double imagTmp = mImaginaryPart * x;
    return ComplexNumber(realTmp, imagTmp);
}
#endif