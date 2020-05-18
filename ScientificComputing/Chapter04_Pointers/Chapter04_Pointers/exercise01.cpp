//Write code that declares an integer i to take the value 5. Declare a pointer to
//an integer p_j, and store the address of i in this pointer.Multiply the value of the
//variable i by 5 by using a line of code that only uses the pointer variable.Declare
//another pointer to an integer p_k and use the new keyword to allocate a location
//in memory that this pointer stores.Then store the contents of the variable i in this
//location.Now change the value pointed to by p_j to 0. Check that your program is
//correct by outputting the value of i and values pointed to by p_j and p_k.

#include <iostream>

int main(int argc, char* argv[])
{
	int i = 5;
	int* p_j = &i;
	*p_j *= 5;

	std::cout << "i \t= " << i << '\n';
	std::cout << "*p_j \t= " << *p_j << "\n\n";

	int* p_k = new int;
	*p_k = i;

	*p_j = 0;

	std::cout << "i \t= " << i << '\n';
	std::cout << "*p_j \t= " << *p_j << '\n';
	std::cout << "*p_k \t= " << *p_k << '\n';

	delete p_k;

	std::cin.get();
	return 0;
}