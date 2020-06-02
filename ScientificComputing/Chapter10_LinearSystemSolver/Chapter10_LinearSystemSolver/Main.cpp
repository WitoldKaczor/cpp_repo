#include <iostream>
#include "Vector.hpp"
#include "Matrix.hpp"

int main(int argc, char* argv[])
{
	Vector v1(5);
	for (int i = 0; i < 5; ++i)
		v1[i] = i;
	std::cout << "v1 = " << v1 << '\n';


	Matrix A1(3, 2);
	std::cout << "A1 = \n" << A1;

	std::cin.get();
	return 0;
}