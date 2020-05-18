//Assign values to two integer variables.
//Swap the values stored by these variables
//using only pointers to integers.

#include <iostream>

int main(int argc, char* argv[])
{
	int x = 11, y = 7;
	std::cout << "x = " << x << "\ny = " << y;
	
	std::cout << "\n\nSwap\n";
	int* p_x = &x;
	int* p_y = &y;
	int* p_tmp = new int;
	*p_tmp = *p_x;
	*p_x = *p_y;
	*p_y = *p_tmp;
	delete p_tmp;

	std::cout << "x = " << x << "\ny = " << y;


	std::cin.get();
	return 0;
}