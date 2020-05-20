//Write code that sends the address of an integer to a function 
//that prints out the value of the integer.

#include <iostream>

void printInt(const int& x);

int main(int argc, char* argv[])
{
	int number = 3;

	printInt(number);


	std::cin.get();
	return 0;
}

void printInt(const int& x)
{
	std::cout << "value: " << x << '\n';
}