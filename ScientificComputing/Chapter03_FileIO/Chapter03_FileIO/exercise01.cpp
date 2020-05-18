//1. Extend the code to print the arrays x and y to a file called x_and_y.dat
//so that the data file has the four elements of x on the top line, and the four elements
//of y on the next line.
//2. Extend the code so that the output stream is flushed immediately after each line
//of the file is written.
//3. Extend the code so that the precision is set to 10 significant figures, the output is
//in scientific notation, and plus signs are shown for positive numbers.
//4. Amend the program so that it does not automatically create a fresh file
//x_and_y.dat every time it is run. Have the program first attempt to open
//the file x_and_y.dat as an ifstream for reading. If the file can be successfully
//opened then, after closing the ifstream, warn the user. Have the program
//prompt the user as to whether it should erase the existing file or append to the
//existing file.

#include <iostream>
#include <fstream>
#include <cassert>

int main(int argc, char* argv[])
{
	double x[4] = { 0.0, 1.0, 1.0, 0.0 };
	double y[4] = { 0.0, 0.0, 1.0, 1.0 };
	bool bSwitchVar = 0;
	int nSwitchVar = 0;

	std::ifstream readFromxydat("x_and_y.dat");
	if (readFromxydat.is_open())
	{
		readFromxydat.close();
		std::cout << "x_and_y.dat exists!\n"; 
		std::cout << "To overwrite the existing file input 0\n";
		std::cout << "To append to the existing file input 1\n";
		
		while (true)
		{
			std::cin >> nSwitchVar;
			if (nSwitchVar == 0) 
			{ 
				bSwitchVar = false;
				break;
			}
			else if (nSwitchVar == 1) 
			{ 
				bSwitchVar = true;
				break;
			}
			else
			{
				std::cout << "Wrong input. Input 0 or 1: ";
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
		}
	}
	
	std::ofstream saveToxydat;
	
	if (!bSwitchVar)
		saveToxydat.open("x_and_y.dat");
	else
		saveToxydat.open("x_and_y.dat", std::ofstream::app);

	assert(saveToxydat.is_open());

	saveToxydat.setf(std::ios::scientific);
	saveToxydat.setf(std::ios::showpos);
	saveToxydat.precision(10);

	for (int i = 0; i < 4; ++i)
		saveToxydat << x[i] << '\t';

	saveToxydat << '\n';
	saveToxydat.flush();

	for (int i = 0; i < 4; ++i)
		saveToxydat << y[i] << '\t';

	saveToxydat << '\n';
	saveToxydat.flush();
	
	return 0;
}