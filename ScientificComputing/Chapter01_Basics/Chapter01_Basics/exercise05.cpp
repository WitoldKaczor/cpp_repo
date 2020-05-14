#include <iostream>

//Write code that invites the user to input separately strings that store their given
//name and their family name. Print the user’s full name to screen.

int main(int argc, char* argv[])
{
	std::string givenName;
	std::string familyName;

	std::cout << "Please input your given name: ";
	std::cin >> givenName;
	std::cout << "Please input your family name: ";
	std::cin >> familyName;

	//std::cout << "Your whole name is " << givenName << ' ' << familyName;

	std::string wholeName = givenName + ' ' + familyName;
	std::cout << "Your whole name is " << wholeName;
	

	std::cin.get(); std::cin.get();
	return 0;
}