#include <iostream>

template<typename T> T AbsoluteValue(T x)
{
	return (x >= (T)0) ? x : -x;
}

int main(int argc, char* argv[])
{
	double x = 1.5, y = -4.6;
	int z = 3, w = -7;

	std::cout << AbsoluteValue<double>(x) << '\n';
	std::cout << AbsoluteValue<double>(y) << '\n';
	std::cout << AbsoluteValue<int>(z) << '\n';
	std::cout << AbsoluteValue<int>(w) << '\n';
	

	std::cin.get();
	return 0;
}