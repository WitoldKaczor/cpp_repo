#include "ComplexNumber.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	std::cout << "main\n\n";

	ComplexNumber z1(0.0, 3.0);
	std::cout << "z1 = " << z1 << '\n';

	std::cin.get();
	return 0;
}