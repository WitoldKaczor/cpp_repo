#include <iostream>
#include <cmath>
#include <iomanip> // setprecision

//In this exercise, we will apply the Newton–Raphson algorithm to the function
//f(x) = e^x + x^3 - 5, with initial guess x0 = 0.
//1. Write down(on paper) the Newton–Raphson iteration for this choice of f(x).
//2. By using a for loop, and an array for the iterates xi, write a program that implements
//the Newton–Raphson iteration for i = 1, 2, 3, ..., 100. Print out the value of
//xi on each iteration, and confirm that the iteration does converge as i increases.
//At this stage, do not worry about terminating the iteration when epsilon is sufficiently
//small.
//3. Think of a check that can be performed on the iterates xi, as i becomes larger,
//that allows you to have confidence that your solution is correct. Implement this
//check in your program.
//4. It is not necessary to store the value of xi on each iteration to implement the
//Newton-Raphson algorithm. All that is needed is the previous iterate, xi-1, and
//the current iterate, xi.Modify your code so that the array representing xi, i =
//1, 2, ..., 100 is replaced by two scalar variables, x_prev and x_next.
//5. Modify your code so that, by use of a while statement, the iteration terminates
//when | x_next - x_prev | < epsilon. Investigate the use of different values of epsilon.


int main(int argc, char* argv[])
{
	//f(x) = e^x + x^3 - 5
	//f'(x) = e^x + 3*x^2
	
	//parts 4..5
	double epsilon = 1e-7;
	double xPrev, xNext;
	bool cond = true;
	double x0 = 0;

	xPrev = x0 - (exp(x0) + pow(x0, 3) - 5) / (exp(x0) + 3 * pow(x0, 2));
	std::cout << std::setprecision(10) << "x: " << xPrev << '\n';

	while (cond)
	{
		xNext = xPrev - (exp(xPrev) + pow(xPrev, 3) - 5) / (exp(xPrev) + 3 * pow(xPrev, 2));
		std::cout << "x: " << xNext << "\t\tf(x): " << (exp(xNext) + pow(xNext, 3) - 5) << '\n';
		cond = abs(xNext - xPrev) >= epsilon;
		xPrev = xNext;
	}



	//parts 1..3
	/*const int idx = 100;
	double x[idx];
	double x0 = 0;

	x[0] = x0 - (exp(x0) + pow(x0, 3) - 5) / (exp(x0) + 3 * pow(x0, 2));
	std::cout << std::setprecision(10) << x[0] << '\n';
	for (int i = 1; i < idx; ++i)
	{
		x[i] = x[i-1] - (exp(x[i - 1]) + pow(x[i - 1], 3) - 5) / (exp(x[i - 1]) + 3 * pow(x[i - 1], 2));
		std::cout << "x: " << x[i] << "\t\tf(x): " << (exp(x[i]) + pow(x[i], 3) - 5) << '\n';
	}*/

	std::cin.get();
	return 0;
}