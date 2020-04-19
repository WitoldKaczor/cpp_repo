#include <iostream>
//using namespace std;

class ComplexNum
{
public:
	ComplexNum(double real, double imag=0) : real(real), imag(imag) {}; //Konstruktor

	ComplexNum(const ComplexNum& obj) : real(obj.real), imag(obj.imag) {}; //Copy-Konstruktor

	void set(double realInput, double imagInput = 0)
	{
		real = realInput;
		imag = imagInput;
	}

	void print()
	{
		if (imag == 0)
			std::cout << real << std::endl;
		else if (real == 0)
			std::cout << imag << "i" << std::endl;
		else
			std::cout << real << " + " << imag << "i" << std::endl;
	}

	ComplexNum operator + (const ComplexNum& obj) //Addition
	{
		ComplexNum result(0,0);
		result.real = real + obj.real;
		result.imag = imag + obj.imag;
		return result;
	}

	ComplexNum operator - (const ComplexNum& obj) //Substraktion
	{
		ComplexNum result(0, 0);
		result.real = real - obj.real;
		result.imag = imag - obj.imag;
		return result;
	}

	ComplexNum operator * (const ComplexNum& obj) //Multiplikation
	{
		ComplexNum result(0, 0);
		result.real = real*obj.real - imag*obj.imag;
		result.imag = real * obj.imag + imag * obj.real;
		return result;
	}

	ComplexNum operator / (const ComplexNum& obj) //Division
	{
		ComplexNum result(0, 0);
		result.real = (real * obj.real + imag * obj.imag) / (obj.real * obj.real + obj.imag * obj.imag);
		result.imag = (-real * obj.imag + imag * obj.real) / (obj.real * obj.real + obj.imag * obj.imag);
		return result;
	}

	ComplexNum operator - () //Minus
	{
		ComplexNum obj(-real, -imag);
		return obj;
	}

	friend std::ostream& operator << (std::ostream& os, const ComplexNum& obj);
	
private:
	double real, imag;
};

std::ostream& operator << (std::ostream& os, const ComplexNum& obj)
{
	if (obj.imag == 0)
		os << obj.real;
	else if (obj.real == 0)
		os << obj.imag << 'i';
	else
		os << obj.real << " + " << obj.imag << 'i';

	return os;
}


int main()
{
ComplexNum z1(5.8, 7.6);
std::cout << "z1 = "; z1.print();

z1.set(1);
//std::cout << "z1 = "; z1.print();
std::cout << "z1 = " << z1 << std::endl;

ComplexNum z2(3, 5);
std::cout << "z2 = "; z2.print();

ComplexNum z3 = z1 + z2;
std::cout << "z1 + z2 = "; z3.print();

ComplexNum z4 = z1 - z2;
std::cout << "z1 - z2 = "; z4.print();

ComplexNum z5 = z1 * z2;
std::cout << "z1 * z2 = "; z5.print();

ComplexNum z6 = z2 * z1;
std::cout << "z2 * z1 = "; z6.print();

ComplexNum z7 = z1 / z2;
std::cout << "z1 / z2 = "; z7.print();

ComplexNum z8 = z2 / z1;
std::cout << "z2 / z1 = "; z8.print();

ComplexNum z8a = z2.operator / (z1);
std::cout << "z2 / z1 = "; z8a.print();

ComplexNum z9(-z2);
std::cout << "z9 = "; z9.print();


std::cin.get();
}