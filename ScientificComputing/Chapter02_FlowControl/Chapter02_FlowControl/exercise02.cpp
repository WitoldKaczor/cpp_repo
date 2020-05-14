#include <iostream>

//1.Set the variable x to the value 5 if either p is greater than or equal to q, or the
//variable j is not equal to 10.
//2. Set the variable x to the value 5 if both y is greater than or equal to q, and the
//variable j is equal to 20. If this compound condition is not met, set x to take the
//same value as p.
//3. Set the variable x according to the following rule.
//x =
//0, p > q,
//1, p <= q, and j = 10,
//2, otherwise.

int main(int argc, char* argv[])
{
	double p = 3.6, q = 5.1, x, y = 18;
	int j = 1;

	//1.
	if (p >= q || j != 10)
		x = 5;

	//2.
	if (y >= q && j == 20)
		x = 5;
	else
		x = p;

	//equivalent to 2. with ternary operator
	x = (y >= q && j == 20) ? x : p;

	//3.
	if (p > q)
		x = 0;
	else if (p <= q && j == 10)
		x = 1;
	else
		x = 2;


	return 0;
}