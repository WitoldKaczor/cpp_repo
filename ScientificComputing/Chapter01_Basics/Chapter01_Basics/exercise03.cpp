#include <iostream>
#include <cmath>

//Write code that declares two vectors as arrays of double precision floating point
//numbers of length 3 and assigns values to each of the entries. Extend this code so that
//it calculates the scalar(dot) product of these vectors and prints it to screen.Finally,
//extend the code so that it prints the Euclidean norm of both vectors to screen.

int main(int argc, char* argv[])
{
	double vec1[3] = { -1, 1, 1 };
	double vec2[3] = { 2, -2, -2 };

	double scalarProduct = 0;
	double scalarProduct1 = 0;
	double scalarProduct2 = 0;
	 	
	for (int i = 0; i < 3; ++i)
	{
		scalarProduct += vec1[i] * vec2[i];
		scalarProduct1 += vec1[i] * vec1[i];
		scalarProduct2 += vec2[i] * vec2[i];
	}
	
	double euclideanNormVec1 = std::sqrt(scalarProduct1);
	double euclideanNormVec2 = std::sqrt(scalarProduct2);

	std::cout << "Scalar Product: " << scalarProduct << '\n';
	std::cout << "Euclidean norm of vec1: " << euclideanNormVec1 << '\n';
	std::cout << "Euclidean norm of vec2: " << euclideanNormVec2 << '\n';

	std::cin.get();
	return 0;
}