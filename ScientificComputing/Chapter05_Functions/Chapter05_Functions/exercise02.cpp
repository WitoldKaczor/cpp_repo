//Write code that sends the address of an integer to a function 
//that changes the value of the integer.

#include <iostream>

void incrInt(int& x);

int main(int argc, char* argv[])
{
	int number = 8;
	std::cout << "number = " << number << '\n';
	incrInt(number);
	std::cout << "number = " << number << '\n';

	std::cin.get();
	return 0;
}

void incrInt(int& x)
{
	x++;
}