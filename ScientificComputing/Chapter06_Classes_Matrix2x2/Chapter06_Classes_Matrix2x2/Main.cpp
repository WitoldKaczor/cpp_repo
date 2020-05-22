#include "Matrix2x2.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	Matrix2x2 A(1.0, -5.0, 3.0, 6.5);
	std::cout << "A = \n";
	A.Show();
	std::cout << "det(A) = " << A.Determinant() << '\n';

	Matrix2x2 B;
	B = A + A;
	std::cout << "\nB = A + A =\n";
	B.Show();

	Matrix2x2 C;
	C = -B;
	std::cout << "\nC = -B =\n";
	C.Show();

	Matrix2x2 D;
	D = A.InvMatrix();
	std::cout << "\nD = inv(A) = \n";
	D.Show();

	Matrix2x2 E;
	std::cout << "\nE = \n";
	E.Show();

	Matrix2x2 F;
	F = A - C;
	std::cout << "\nF = A - C =\n";
	F.Show();

	Matrix2x2 G;
	G = F.MultByScalar(0.5);
	std::cout << "\nG = F * 0.5 =\n";
	G.Show();



	std::cin.get();
	return 0;
}