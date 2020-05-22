#ifndef MATRIX2X2CLASSDEFINITION
#define MATRIX2X2CLASSDEFINITION

class Matrix2x2
{
public:
	Matrix2x2();
	Matrix2x2(const Matrix2x2& matrix);
	Matrix2x2(double a, double b, double c, double d);

	double Determinant();
	Matrix2x2 InvMatrix();
	void Show();
	Matrix2x2 operator-() const;
	Matrix2x2 operator+(const Matrix2x2& matrix) const;
	Matrix2x2 operator-(const Matrix2x2& matrix) const;
	Matrix2x2 MultByScalar(double x) const;

private:
	double field00, field01, field10, field11;
	//matrix form:
	// | field00  field01 |
	// | field10  field11 |
};

#endif