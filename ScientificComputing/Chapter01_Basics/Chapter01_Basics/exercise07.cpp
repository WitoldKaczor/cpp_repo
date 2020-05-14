#include <iostream>

//Investigate the use of the compiler error warning flags discussed in Sect. 1.3.3.
//For example : (i)declare an integer as a constant variable and then attempt to change
//this value later in the code; and (ii)attempt to set an integer variable to the value 3.2.

int main(int argc, char* argv[])
{

	/*const int a = 1;
	a = 2;*/


	int b;
	b = 3.2;
	std::cout << b;

	std::cin.get();
	return 0;
}