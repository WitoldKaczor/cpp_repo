//This question uses the data file x_and_y.dat that was written in the previous
//exercise.The code below assumes that we know that the data file has 4 columns and
//that we want to count the number of rows. Modify the code so that it gives the correct answer.

#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
	std::ifstream read_file("x_and_y.dat");
	if (!read_file.is_open())
	{
		return 1;
	}

	int number_of_rows = 0;

	while (!read_file.eof())
	{
		double dummy1, dummy2, dummy3, dummy4;
		read_file >> dummy1 >> dummy2;
		read_file >> dummy3 >> dummy4;
		if (read_file.fail()) { break; }
		number_of_rows++;
	}

	std::cout << "Number of rows = " << number_of_rows << "\n";

	read_file.close();

	std::cin.get();
	return 0;
}