//Write a function that swaps the values of two double precision floating point
//numbers, so that these changes are visible in the code that has called this function.
//1. Write this function using pointers.
//2. Write this function using references.

#include <iostream>

void swapPointers(double* pa, double* pb);
void swapReferences(double& a, double& b);

int main()
{
	double x = 5, y = 13;
	std::cout << "x = " << x << "\ty = " << y << '\n';

	std::cout << "\nSwap\n";
	swapReferences(x, y);
	std::cout << "x = " << x << "\ty = " << y << '\n';

	std::cout << "\nSwap\n";
	swapPointers(&x, &y);
	std::cout << "x = " << x << "\ty = " << y << '\n';


	std::cin.get();
	return 0;
}

void swapPointers(double* pa, double* pb)
{
	double tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void swapReferences(double& a, double& b)
{
	double tmp = a;
	a = b;
	b = tmp;
}