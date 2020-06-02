#include <iostream>
#include "Vector.hpp"
#include "Matrix.hpp"
#include "LinearSystem.hpp"
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
	for (int iter = 2; iter <= 4; ++iter)
	{
		int nSystemSize = iter;

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
		std::cout << LinSys.Solve() << '\n';
	}

	std::cin.get();
	return 0;
}