#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF

#include "Vector.hpp"
#include <iostream>
#include <cassert>

class Matrix
{
private:
	int mNumRows;
	int mNumCols;
	double** mData;
public:
	Matrix(const Matrix& M);
	Matrix(int NumRows, int NumCols);
	~Matrix();
public:
	int GetNumRows() const;
	int GetNumCols() const;
	double& operator()(int i, int j);// one-based indexing
	Matrix& operator=(const Matrix& A1); // assignment
	Matrix operator-() const; // unary -
	Matrix operator+(const Matrix& A1) const; // binary +
	Matrix operator-(const Matrix& A1) const; // binary -
	Matrix operator*(double a) const; // matrix*scalar multiplication
	Matrix operator*(const Matrix& A1) const; // matrix*matrix multiplication
	Matrix operator*(const Vector& v1) const; // matrix*vector multiplication
	friend std::ostream& operator<<(std::ostream& output, const Matrix& A1);
	double determinant() const; // determinant of the given square matrix
};

#endif