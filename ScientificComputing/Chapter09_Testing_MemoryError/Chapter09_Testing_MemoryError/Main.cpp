#include <iostream>

int main(int argc, char* argv[])
{
	double* p_x;
	try
	{
		p_x = new (std::nothrow) double[(int)1e8];
	}
	catch (std::bad_alloc)
	{
		delete p_x;
	}

	delete[] p_x;
	
	
	
	std::cin.get();
	return 0;
}