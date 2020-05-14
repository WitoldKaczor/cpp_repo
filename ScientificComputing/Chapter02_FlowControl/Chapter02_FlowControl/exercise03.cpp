#include <iostream>

//In this exercise you are asked to writeand test a program which sums a list of
//numbers which are provided by a user via std::cin(see Sect. 1.5.2).
//1. Write a program that calculates the sum of a collection of positive integers that
//are entered by the user from the keyboard.Your program should prompt the user
//to enter each integer followed by the return key, and to enter '-1' at the end
//of the list of integers to be added. Note that there is no need to store the list of
//integers : you can keep track of the sum as the user is entering the values.
//2. Modify your code so that the code terminates if the sum of integers entered up to
//that point exceeds 100.
//3. Modify your code so that, if the user has entered an incorrect integer, they may
//enter '-2' to reset the sum to zero and begin entering integers again.

int main(int argc, char* argv[])
{
	int num = 0, sum = 0;
	std::cout << "Input positive integers to add.\nTo end inserting and add the numbers input -1\n";
	
	while (num >= 0 && sum <= 100)
	{
		std::cin >> num;
		if (num == -1) { break; }
		if (std::cin.fail() || num < -1)
		{
			std::cout << "Wrong input. Reset\n";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			num = 0;
			sum = 0;
		}
		sum += num;	
	}

	std::cout << "Sum of the numbers is " << sum;

	std::cin.get(); std::cin.get();
	return 0;
}