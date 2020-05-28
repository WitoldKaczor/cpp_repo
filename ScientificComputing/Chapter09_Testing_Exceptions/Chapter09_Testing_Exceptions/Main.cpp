#include <iostream>
#include "Exception.hpp"
#include "OutOfRangeException.hpp"
#include "FileNotOpenException.hpp"

int main(int argc, char* argv[])
{
	// inheritance test
	/*Exception obj01("TEST", "This is a generally exception");
	obj01.PrintDebug();

	OutOfRangeException obj02("This is an OutOfRange exception");
	obj02.PrintDebug();

	FileNotOpenException obj03("This is a FileNotOpen exception");
	obj03.PrintDebug();*/

	int SwitchVar = 2;

	try
	{
		if (SwitchVar == 0)
			throw (Exception("Test Error", "This is a generally exception"));

		if (SwitchVar == 1)
			throw (OutOfRangeException("This is an OutOfRange exception"));

		if (SwitchVar == 2)
			throw (FileNotOpenException("This is a FileNotOpen exception"));

		std::cout << "OK\n";
	}
	catch (Exception& error)
	{
		error.PrintDebug();
	}

	std::cin.get();
	return 0;
}