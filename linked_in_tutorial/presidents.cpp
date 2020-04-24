#include <iostream>
//George Washington, April 30, 1789
//Thomas Jefferson, March 4, 1801
//Abraham Lincoln, March 4, 1861
//Theodore Roosevelt, September 14, 1901

struct person
{
	std::string name;
	struct tookoffice
	{
		int day, month, year;
	} tookoffice;
};

int main()
{
	person struct_arr[4] = {
		{ "George Washington", {30, 4, 1789} },
		{ "Thomas Jefferson", {4, 3, 1801} },
		{ "Abraham Lincoln", {4, 3, 1861} },
		{ "Theodore Roosevelt", {14, 9, 1901} } };

	for (int i = 0; i < 4; i++)
		std::cout << struct_arr[i].name << " took office on " << struct_arr[i].tookoffice.day << "." << struct_arr[i].tookoffice.month << "." << struct_arr[i].tookoffice.year << std::endl;

	person temp = struct_arr[0];
	struct_arr[0] = struct_arr[2];
	struct_arr[2] = temp;
	std::cout << "SWAP" << std::endl;

	for (int i = 0; i < 4; i++)
		std::cout << struct_arr[i].name << " took office on " << struct_arr[i].tookoffice.day << "." << struct_arr[i].tookoffice.month << "." << struct_arr[i].tookoffice.year << std::endl;

	std::cin.get();
}