#include "ComplexNumber_Chapter06.hpp"
#include "ComplexNumber_Chapter06.cpp"
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
	std::vector<ComplexNumber> complexVec;
	complexVec.reserve(5);

	complexVec.push_back(ComplexNumber(3.5, 4));
	complexVec.push_back(ComplexNumber(0, 6.3));
	complexVec.push_back(ComplexNumber(5.8));
	for (ComplexNumber complexNum : complexVec)
		std::cout << complexNum << '\n';

	complexVec.insert(complexVec.begin() + 1, ComplexNumber(1, 1));
	std::cout << '\n';
	for (std::vector<ComplexNumber>::const_iterator i = complexVec.begin(); i != complexVec.end(); ++i)
		std::cout << *i << '\n';
	
	complexVec.erase(complexVec.end() - 1, complexVec.end());
	std::cout << '\n';
	for (auto i = complexVec.begin(); i != complexVec.end(); ++i)
		std::cout << *i << '\n';


	std::cin.get();
	return 0;
}


