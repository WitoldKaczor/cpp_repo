#include <iostream>

int main()
{
short int a;
short int b;
std::cout << sizeof(a) << sizeof(b) << std::endl;

a = 5;
b = a++;
std::cout << "a: " << a << std::endl;
std::cout << "b: " << b << std::endl;

b = ~a;
std::cout << "b: " << b << std::endl;

short unsigned int c = 5;
short unsigned int d = ~c;
std::cout << "d: " << d << std::endl;

b = !a;
std::cout << "b: " << b << std::endl;

b = a << 3;
std::cout << "b: " << b << std::endl;

b = a >> 2;
std::cout << "b: " << b << std::endl;

a = 6; b = 5;
std::cout << "a == b " << (a == b) << std::endl;
std::cout << "a & b  " << (a & b) << std::endl;
std::cout << "a ^ b  " << (a ^ b) << std::endl;
std::cout << "a | b  " << (a | b) << std::endl;
std::cout << "a && b " << (a && b) << std::endl;
std::cout << "a || b " << (a || b) << std::endl;

std::cout << "a-- != b ? a : b " << (a != b ? a : b) << std::endl;

a = 6, b = a, b++;
std::cout << "b: " << b << std::endl;

b = 5, b = a += b, b == a;
std::cout << "b: " << b << std::endl;

a = 6, b = 5, b = (a += b, b == a);
std::cout << "b: " << b << std::endl;


std::cin.get();
}