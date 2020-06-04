#include "Vector.hpp"
#include "Matrix.hpp"
#include "LinearSystem.hpp"
# include "PosDefSymmLinearSystem.hpp"
#include <fstream>
#include <string>

class TestSuiteAsserts
{//based on CxxTest
public:
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
};

class TestSuiteVector : private TestSuiteAsserts
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
		std::cout << "All tests on the class Vector passed\n";
	}

private:
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

class TestSuiteMatrix : private TestSuiteAsserts
{
public:
	TestSuiteMatrix()
	{
		// all the test methods are called 
		// in the default constructor
		TestSizeConstructor();
		TestCopyConstructor();
		TestAssigment();
		TestUnaryMinus();
		TestAddition();
		TestSubtraction();
		TestScalarMultiplication();
		TestMatrixMultiplication();
		TestVectorMultiplication();
		TestDeterminant();

		// inform the user when the tests are passed
		std::cout << "All tests on the class Matrix passed\n";
	}

private:
	void TestSizeConstructor()
	{
		Matrix A1(3, 2);
		TS_ASSERT_EQUALS(A1.GetNumRows(), 3);
		TS_ASSERT_EQUALS(A1.GetNumCols(), 2);
	}

	void TestCopyConstructor()
	{
		int numRow = 3;
		int numCol = 2;
		Matrix A1(numRow, numCol);
		for (int i = 1; i <= numRow; ++i)
			for (int j = 1; j <= numCol; ++j)
				A1(i,j) = 1 - (double)i * (double)j;

		Matrix A2 = A1;
		for (int i = 1; i <= numRow; ++i)
			for (int j = 1; j <= numCol; ++j)
				A1(i,j) = 0.0;
		for (int i = 1; i <= numRow; ++i)
			for (int j = 1; j <= numCol; ++j)
				TS_ASSERT_DELTA(A2(i,j), 1 - (double)i * (double)j, 1e-16);
	}

	void TestAssigment()
	{
		int numRow = 3;
		int numCol = 2;
		Matrix A1(numRow, numCol);
		for (int i = 1; i <= numRow; ++i)
			for (int j = 1; j <= numCol; ++j)
				A1(i, j) = 1 - (double)i * (double)j;
		
		Matrix A2(numRow, numCol);
		A2 = A1;
		for (int i = 1; i <= numRow; ++i)
			for (int j = 1; j <= numCol; ++j)
				A1(i, j) = 0.0;
		for (int i = 1; i <= numRow; ++i)
			for (int j = 1; j <= numCol; ++j)
				TS_ASSERT_DELTA(A2(i, j), 1 - (double)i * (double)j, 1e-16);
	}

	void TestUnaryMinus()
	{
		int numRow = 3;
		int numCol = 2;
		Matrix A1(numRow, numCol);
		for (int i = 1; i <= numRow; ++i)
			for (int j = 1; j <= numCol; ++j)
				A1(i, j) = 1 - (double)i * (double)j;

		Matrix A2(numRow, numCol);
		A2 = -A1;
		for (int i = 1; i <= numRow; ++i)
			for (int j = 1; j <= numCol; ++j)
				TS_ASSERT_DELTA(A2(i, j), -(1 - (double)i * (double)j), 1e-16);
	}
	
	void TestAddition()
	{
		int numRow = 3;
		int numCol = 2;
		Matrix A1(numRow, numCol);
		for (int i = 1; i <= numRow; ++i)
			for (int j = 1; j <= numCol; ++j)
				A1(i, j) = 1 - (double)i * (double)j;

		Matrix A2(numRow, numCol);
		A2 = A1 + A1;
		for (int i = 1; i <= numRow; ++i)
			for (int j = 1; j <= numCol; ++j)
				A1(i, j) = 0.0;
		for (int i = 1; i <= numRow; ++i)
			for (int j = 1; j <= numCol; ++j)
				TS_ASSERT_DELTA(A2(i, j), 2 * (1 - (double)i * (double)j), 1e-16);
	}

	void TestSubtraction()
	{
		int numRow = 3;
		int numCol = 2;
		Matrix A1(numRow, numCol);
		for (int i = 1; i <= numRow; ++i)
			for (int j = 1; j <= numCol; ++j)
				A1(i, j) = 1 - (double)i * (double)j;
		Matrix A2(numRow, numCol);
		for (int i = 1; i <= numRow; ++i)
			for (int j = 1; j <= numCol; ++j)
				A2(i, j) = 4 * (double)j + 3 * (double)i;

		Matrix A3(numRow, numCol);
		A3 = A1 - A2;
		for (int i = 1; i <= numRow; ++i)
			for (int j = 1; j <= numCol; ++j)
			{
				A1(i, j) = 0.0;
				A2(i, j) = 0.0;
			}
		for (int i = 1; i <= numRow; ++i)
			for (int j = 1; j <= numCol; ++j)
				TS_ASSERT_DELTA(A3(i, j), (1 - (double)i * (double)j - 4 * (double)j - 3 * (double)i), 1e-16);
	}

	void TestScalarMultiplication()
	{
		double scalar = 5.5;
		int numRow = 3;
		int numCol = 2;
		Matrix A1(numRow, numCol);
		for (int i = 1; i <= numRow; ++i)
			for (int j = 1; j <= numCol; ++j)
				A1(i, j) = 1 - (double)i * (double)j;

		A1 * scalar;
		for (int i = 1; i <= numRow; ++i)
			for (int j = 1; j <= numCol; ++j)
				TS_ASSERT_DELTA(A1(i, j), (1 - (double)i * (double)j) * scalar, 1e-16);
	}
	
	void TestMatrixMultiplication()
	{
		int numRow = 3;
		int numCol = 2;
		Matrix A1(numRow, numCol);
		for (int i = 1; i <= numRow; ++i)
			for (int j = 1; j <= numCol; ++j)
				A1(i, j) = 1 - (double)i * (double)j;

		Matrix A2(2, 2);
		for (int i = 1; i <= 2; ++i)
			for (int j = 1; j <= 2; ++j)
			{
				if (i == j) { A2(i, j) = 1.0; }
				else { A2(i, j) = 0.0; }
			}
		A1 = A1 * A2;
		for (int i = 1; i <= numRow; ++i)
			for (int j = 1; j <= numCol; ++j)
				TS_ASSERT_DELTA(A1(i, j), (1 - (double)i * (double)j), 1e-16);

		Matrix A3(3, 2);
		A3(1, 1) = 1;	A3(1, 2) = -2;
		A3(2, 1) = -3;	A3(2, 2) = 6;
		A3(3, 1) = 0;	A3(3, 2) = 1;
		Matrix A4(2, 2);
		A4(1, 1) = 2;	A4(1, 2) = -1;
		A4(2, 1) = 0;	A4(2, 2) = 3;

		A1 = A3 * A4;
		TS_ASSERT_DELTA(A1(1, 1), 2, 1e-16);
		TS_ASSERT_DELTA(A1(1, 2), -7, 1e-16);
		TS_ASSERT_DELTA(A1(2, 1), -6, 1e-16);
		TS_ASSERT_DELTA(A1(2, 2), 21, 1e-16);
		TS_ASSERT_DELTA(A1(3, 1), 0, 1e-16);
		TS_ASSERT_DELTA(A1(3, 2), 3, 1e-16);

		Matrix A5(2, 2);
		for (int i = 1; i <= 2; ++i)
			for (int j = 1; j <= 2; ++j)
				A5(i, j) = 0.0;
		A1 = A1 * A5;
		for (int i = 1; i <= numRow; ++i)
			for (int j = 1; j <= numCol; ++j)
				TS_ASSERT_DELTA(A1(i, j), 0.0, 1e-16);
	}

	void TestVectorMultiplication()
	{
		Matrix A1(3, 2);
		for (int i = 1; i <= 3; ++i)
			for (int j = 1; j <= 2; ++j)
			{
				if (i == j) { A1(i, j) = 1.0; }
				else { A1(i, j) = 0.0; }
			}
		Vector v1(2);
		v1(1) = 3;
		v1(2) = 5;
		Vector v2(3);
		v2 = A1 * v1;
		TS_ASSERT_DELTA(v2(1), 3, 1e-16);
		TS_ASSERT_DELTA(v2(2), 5, 1e-16);
		TS_ASSERT_DELTA(v2(3), 0, 1e-16);

		Matrix A3(3, 2);
		A3(1, 1) =  1;	A3(1, 2) = -2;
		A3(2, 1) = -3;	A3(2, 2) =  6;
		A3(3, 1) =  0;	A3(3, 2) =  1;
		v2 = A3 * v1;
		TS_ASSERT_DELTA(v2(1), -7, 1e-16);
		TS_ASSERT_DELTA(v2(2), 21, 1e-16);
		TS_ASSERT_DELTA(v2(3),  5, 1e-16);

		Matrix A4(3, 2);
		for (int i = 1; i <= 3; ++i)
			for (int j = 1; j <= 2; ++j)
				A4(i, j) = 0.0;
		v2 = A4 * v1;
		TS_ASSERT_DELTA(v2(1), 0, 1e-16);
		TS_ASSERT_DELTA(v2(2), 0, 1e-16);
		TS_ASSERT_DELTA(v2(3), 0, 1e-16);
	}

	void TestDeterminant()
	{
		//1x1 Matrix
		Matrix A0(1, 1);
		A0(1, 1) = 5;
		TS_ASSERT_DELTA(A0.determinant(), 5, 1e-16);

		//2x2 Matrix
		Matrix A1(2, 2);
		A1(1, 1) =  3;	A1(1, 2) =  1;
		A1(2, 1) = -1;	A1(2, 2) =  2;
		TS_ASSERT_DELTA(A1.determinant(), 7, 1e-16);
		
		//3x3 Matrix
		Matrix A2(3, 3);
		A2(1, 1) = -1;	A2(1, 2) =  2;	A2(1, 3) = 10;
		A2(2, 1) =  0;	A2(2, 2) = -2;	A2(2, 3) =  1;
		A2(3, 1) =  1;	A2(3, 2) =  3;	A2(3, 3) =  4;
		TS_ASSERT_DELTA(A2.determinant(), 33, 1e-16);

		//4x4 Matrix
		Matrix A3(4, 4);
		A3(1, 1) =  7;	A3(1, 2) = 12;	A3(1, 3) =  5;	A3(1, 4) = 1;
		A3(2, 1) = -1;	A3(2, 2) =  0;	A3(2, 3) = -1;	A3(2, 4) = 2;
		A3(3, 1) =  2;	A3(3, 2) = -3;	A3(3, 3) = -2;	A3(3, 4) = 0;
		A3(4, 1) =  1;	A3(4, 2) = -3;	A3(4, 3) =  2;	A3(4, 4) = 3;
		TS_ASSERT_DELTA(A3.determinant(), -519, 1e-16);
	}
};

class TestSuiteLinearSystem : public TestSuiteAsserts
{
public:
	TestSuiteLinearSystem()
	{
		// all the test methods are called 
		// in the default constructor
		TestCalcLinSys2x2();
		TestCalcLinSys3x3();
		TestCalcLinSys4x4();

		// inform the user when the tests are passed
		std::cout << "All tests on the class LinearSystem passed\n";
	}

private:
	Vector TestCalculationOfLinSys(int nSystemSize)
	{
		// define system, read from file
		std::ifstream readMatrixA;
		std::ifstream readVectorb;

		// define file name and open file
		std::string MatrixFileName = "systemsData/matrixA_dim" + std::to_string(nSystemSize) + ".dat";
		std::string VectorFileName = "systemsData/vectorb_dim" + std::to_string(nSystemSize) + ".dat";
		readMatrixA.open(MatrixFileName);
		readVectorb.open(VectorFileName);

		// define matrix and vector of the system
		Matrix A(nSystemSize, nSystemSize);
		Vector b(nSystemSize);

		// read matrix from the file
		assert(readMatrixA.is_open());
		for (int i = 1; i <= nSystemSize; ++i)
			for (int j = 1; j <= nSystemSize; ++j)
				readMatrixA >> A(i, j);
		readMatrixA.close();

		// read vector from the file
		assert(readVectorb.is_open());
		for (int i = 1; i <= nSystemSize; ++i)
			readVectorb >> b(i);
		readVectorb.close();

		// solve the linear system 
		// and print solution vector to the console
		LinearSystem LinSys(A, b);

		// return the solution vector
		return LinSys.Solve();
	}

	void TestCalcLinSys2x2()
	{
		Vector u = TestCalculationOfLinSys(2);
		TS_ASSERT_DELTA(u(1),  3, 1e-16);
		TS_ASSERT_DELTA(u(2), -1, 1e-16);
	}
	
	void TestCalcLinSys3x3()
	{
		Vector u = TestCalculationOfLinSys(3);
		TS_ASSERT_DELTA(u(1), (6.0 / 19.0), 1e-16);
		TS_ASSERT_DELTA(u(2), (5.0 / 19.0), 1e-16);
		TS_ASSERT_DELTA(u(3), (2.0 / 19.0), 1e-16);
	}

	void TestCalcLinSys4x4()
	{
		Vector u = TestCalculationOfLinSys(4);
		TS_ASSERT_DELTA(u(1), -(164.0 / 75.0), 1e-14);
		TS_ASSERT_DELTA(u(2),  ( 23.0 / 15.0), 1e-14);
		TS_ASSERT_DELTA(u(3),  (184.0 / 75.0), 1e-14);
		TS_ASSERT_DELTA(u(4),  (188.0 / 75.0), 1e-14);
	}
};

class TestSuitePosDefSymmLinearSystem : public TestSuiteAsserts
{
public:
	TestSuitePosDefSymmLinearSystem()
	{
		// all the test methods are called 
		// in the default constructor
		TestCalcPosDefSymmLinSys2x2();
		TestCalcPosDefSymmLinSys3x3();
		TestCalcPosDefSymmLinSys4x4();

		// inform the user when the tests are passed
		std::cout << "All tests on the class TestSuitePosDefSymmLinearSystem passed\n";
	}

private:
	double TestTolerance = 1e-14;
private:
	Vector TestCalcOfPosDefSymmLinSys(int nSystemSize)
	{
		// define system, read from file
		std::ifstream readMatrixA;
		std::ifstream readVectorb;

		// define file name and open file
		std::string MatrixFileName = "systemsDataSym/matrixA_dim" + std::to_string(nSystemSize) + ".dat";
		std::string VectorFileName = "systemsDataSym/vectorb_dim" + std::to_string(nSystemSize) + ".dat";
		readMatrixA.open(MatrixFileName);
		readVectorb.open(VectorFileName);

		// define matrix and vector of the system
		Matrix A(nSystemSize, nSystemSize);
		Vector b(nSystemSize);

		// read matrix from the file
		assert(readMatrixA.is_open());
		for (int i = 1; i <= nSystemSize; ++i)
			for (int j = 1; j <= nSystemSize; ++j)
				readMatrixA >> A(i, j);
		readMatrixA.close();

		// read vector from the file
		assert(readVectorb.is_open());
		for (int i = 1; i <= nSystemSize; ++i)
			readVectorb >> b(i);
		readVectorb.close();

		// solve the linear system 
		// and print solution vector to the console
		PosDefSymmLinearSystem SymLinSys(A, b);

		// return the solution vector
		return SymLinSys.Solve(TestTolerance);
	}

	void TestCalcPosDefSymmLinSys2x2()
	{
		Vector u = TestCalcOfPosDefSymmLinSys(2);
		TS_ASSERT_DELTA(u(1), 0.8, TestTolerance);
		TS_ASSERT_DELTA(u(2), 0.4, TestTolerance);
	}

	void TestCalcPosDefSymmLinSys3x3()
	{
		Vector u = TestCalcOfPosDefSymmLinSys(3);
		TS_ASSERT_DELTA(u(1),  5.0, TestTolerance);
		TS_ASSERT_DELTA(u(2),  4.0, TestTolerance);
		TS_ASSERT_DELTA(u(3), -2.0, TestTolerance);
	}

	void TestCalcPosDefSymmLinSys4x4()
	{
		Vector u = TestCalcOfPosDefSymmLinSys(4);
		TS_ASSERT_DELTA(u(1), -(138.0 / 169.0), TestTolerance);
		TS_ASSERT_DELTA(u(2),  (249.0 / 169.0), TestTolerance);
		TS_ASSERT_DELTA(u(3), -(133.0 / 169.0), TestTolerance);
		TS_ASSERT_DELTA(u(4),  (124.0 / 169.0), TestTolerance);
	}
};

int main(int argc, char* argv[])
{
	std::cout << "TestSuite\n";

	TestSuiteVector TestObjVector;
	TestSuiteMatrix TestObjMatrix;
	TestSuiteLinearSystem TestObjLinSys;
	TestSuitePosDefSymmLinearSystem TestObjPosDefSymmLinSys;


	std::cin.get();
	return 0;
}