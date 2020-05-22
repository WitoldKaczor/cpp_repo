#include "Matrix2x2.hpp"
#include <iostream>
#include <cassert>

// default constructor that initialises all entries of the matrix to zero
Matrix2x2::Matrix2x2()
{
	field00 = field01 = field10 = field11 = 0;
}

// copy constructor
Matrix2x2::Matrix2x2(const Matrix2x2& matrix)
{
	field00 = matrix.field00;
	field01 = matrix.field01;
	field10 = matrix.field10;
	field11 = matrix.field11;
}

// constructor that specifies the four entries of the matrix 
// and allocates these entries appropriately
Matrix2x2::Matrix2x2(double a, double b, double c, double d)
{
	field00 = a;
	field01 = b;
	field10 = c;
	field11 = d;
}

// method returning the determinant of the matrix
double Matrix2x2::Determinant()
{
	return ((field00 * field11) - (field01 * field10));
}

// method returning the inverse of the matrix, if it exists
Matrix2x2 Matrix2x2::InvMatrix()
{
	double det = this->Determinant();
	assert(det != 0);

	double field00New =  field11/det;
	double field01New = -field01/det;
	double field10New = -field10/det;
	double field11New =  field00/det;

	return Matrix2x2(field00New, field01New, field10New, field11New);
}

// method printing the matrix to the console
void Matrix2x2::Show()
{
	std::cout << field00 << '\t' << field01 << '\n';
	std::cout << field10 << '\t' << field11 << '\n';
}

// override unary operator -
Matrix2x2 Matrix2x2::operator-() const
{
	return Matrix2x2(-field00, -field01, -field10, -field11);
}

// override binary operator +
Matrix2x2 Matrix2x2::operator+(const Matrix2x2& matrix) const
{
	return Matrix2x2(field00 + matrix.field00, 
					 field01 + matrix.field01, 
					 field10 + matrix.field10,
					 field11 + matrix.field11);
}

// override binary operator -
Matrix2x2 Matrix2x2::operator-(const Matrix2x2& matrix) const
{
	return Matrix2x2(field00 - matrix.field00,
					 field01 - matrix.field01,
					 field10 - matrix.field10,
					 field11 - matrix.field11);
}

Matrix2x2 Matrix2x2::MultByScalar(double x) const
{
	return Matrix2x2(field00 * x, field01 * x, field10 * x, field11 * x);
}