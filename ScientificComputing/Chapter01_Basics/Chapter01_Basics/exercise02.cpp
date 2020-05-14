#include <iostream>

//Write code that asks a user to enter two integers from the keyboard  
//and then writes the product of these integers to the screen.

int main(int argc, char* argv[])
{
	int num1, num2;
	do
	{
		std::cout << "Two numbers please:\n";
		std::cin >> num1;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Wrong input!\n\n";
			continue;
		}
			
		std::cin >> num2;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Wrong input!\n\n";
			continue;
		}

		std::cout << "Product of " << num1 << " and " << num2 << " is " << (num1 * num2) << std::endl << std::endl;
	}while (true);

	std::cin.get(); std::cin.get();
	return 0;
}