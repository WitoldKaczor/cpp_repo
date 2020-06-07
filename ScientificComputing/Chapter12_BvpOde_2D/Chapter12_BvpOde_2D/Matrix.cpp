#include "Matrix.hpp"

Matrix::Matrix(const Matrix& M)
{
	// copy the matrix size
	mNumRows = M.mNumRows;
	mNumCols = M.mNumCols;

	// allocate new matrix
	mData = new double* [mNumRows];
	for (int i = 0; i < mNumRows; ++i)
		mData[i] = new double[mNumCols];

	// copy the values
	for (int i = 0; i < mNumRows; ++i)
		for (int j = 0; j < mNumCols; ++j)
			mData[i][j] = M.mData[i][j];
}

Matrix::Matrix(int inputNumRows, int inputNumCols)
{
	// set the matrix size
	mNumRows = inputNumRows;
	mNumCols = inputNumCols;

	// allocate new matrix
	mData = new double* [mNumRows];
	for (int i = 0; i < mNumRows; ++i)
		mData[i] = new double[mNumCols];

	// set all the values to zero
	for (int i = 0; i < mNumRows; ++i)
		for (int j = 0; j < mNumCols; ++j)
			mData[i][j] = 0.0;
}

Matrix::~Matrix()
{
	// deallocate the matrix data
	for (int i = 0; i < mNumRows; ++i)
		delete[] mData[i];
	delete[] mData;
}

int Matrix::GetNumRows() const
{
	return mNumRows;
}

int Matrix::GetNumCols() const
{
	return mNumCols;
}

double& Matrix::operator()(int i, int j)
{
	assert(i > 0 && i < mNumRows + 1);
	assert(j > 0 && j < mNumCols + 1);

	return mData[i - 1][j - 1];
}

double& Matrix::operator()(int i, int j) const
{
	assert(i > 0 && i < mNumRows + 1);
	assert(j > 0 && j < mNumCols + 1);

	return mData[i - 1][j - 1];
}

Matrix& Matrix::operator=(const Matrix& A1)
{
	assert(mNumRows == A1.mNumRows);
	assert(mNumCols == A1.mNumCols);

	// copy the values
	for (int i = 0; i < mNumRows; ++i)
		for (int j = 0; j < mNumCols; ++j)
			mData[i][j] = A1.mData[i][j];

	return *this;
}

Matrix Matrix::operator-() const
{
	for (int i = 0; i < mNumRows; ++i)
		for (int j = 0; j < mNumCols; ++j)
			mData[i][j] = -mData[i][j];
	return *this;
}

Matrix Matrix::operator+(const Matrix& A1) const
{
	assert(mNumRows == A1.mNumRows);
	assert(mNumCols == A1.mNumCols);

	for (int i = 0; i < mNumRows; ++i)
		for (int j = 0; j < mNumCols; ++j)
			mData[i][j] += A1.mData[i][j];

	return *this;
}

Matrix Matrix::operator-(const Matrix& A1) const
{
	assert(mNumRows == A1.mNumRows);
	assert(mNumCols == A1.mNumCols);

	for (int i = 0; i < mNumRows; ++i)
		for (int j = 0; j < mNumCols; ++j)
			mData[i][j] -= A1.mData[i][j];

	return *this;
}

Matrix Matrix::operator*(double a) const
{
	for (int i = 0; i < mNumRows; ++i)
		for (int j = 0; j < mNumCols; ++j)
			mData[i][j] *= a;

	return *this;
}

Matrix Matrix::operator*(const Matrix& A1) const
{
	assert(mNumCols == A1.mNumRows);

	Matrix NewMatrix(mNumRows, A1.mNumCols);
	for (int i = 0; i < mNumRows; ++i)
		for (int j = 0; j < mNumCols; ++j)
			for (int k = 0; k < A1.mNumCols; ++k)
				NewMatrix.mData[i][j] += mData[i][k] * A1.mData[k][j];

	return NewMatrix;
}

Vector Matrix::operator*(const Vector& v1) const
{// matrix * vector only
	assert(mNumCols == v1.GetSize());

	Vector NewVector(mNumRows);
	for (int i = 0; i < mNumRows; ++i)
		for (int j = 0; j < mNumCols; ++j)
			NewVector[i] += mData[i][j] * v1.Read(j);

	return NewVector;
}

std::ostream& operator<<(std::ostream& output, const Matrix& A1)
{
	for (int i = 0; i < A1.mNumRows; ++i)
		for (int j = 0; j < A1.mNumCols; ++j)
		{	
			if (j == 0)
			{
				output << '\n';
			}
			output << A1.mData[i][j] << '\t';
		}
	output << '\n';
	return output;
}

double Matrix::determinant() const
{
	assert(mNumRows == mNumCols);
	int size = mNumRows;

	if (size == 1)
		return mData[0][0];

	double det = 0.0;
	//Laplace expansion along the first row
	for (int i = 0; i < size; ++i)
	{
		int j = 0; // first row fixed
		
		// minorMatrix
		Matrix D(size - 1, size - 1);
		int minorRow, minorCol;
		for (int m = 0; m < size; ++m)
		{
			minorRow = m;
			if (m > i)
				--minorRow;

			for (int n = 0; n < size; n++)
			{
				minorCol = n;
				if (n > j)
					--minorCol;
				if (m != i && n != j)
					D.mData[minorRow][minorCol] = mData[m][n];
			}
		}

		det += mData[i][j] * pow(-1, i + j) * D.determinant();
	}
	return det;
}

void Matrix::WriteMatrixToFile(std::string FileName) const
{
	assert(!FileName.empty());

	std::ofstream writeMatrix(FileName);
	assert(writeMatrix.is_open());
	writeMatrix.setf(std::ios::scientific);
	writeMatrix.setf(std::ios::showpos);
	writeMatrix.precision(3);

	for (int i = 0; i < mNumRows; ++i)
		for (int j = 0; j < mNumCols; ++j)
		{
			if (j == 0 && i != 0)
			{
				writeMatrix << '\n';
			}
			writeMatrix << mData[i][j] << '\t';
		}
	writeMatrix << '\n';
	writeMatrix.close();
}