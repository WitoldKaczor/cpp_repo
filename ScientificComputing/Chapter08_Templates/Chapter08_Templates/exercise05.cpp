#include <iostream>
#include <map>
#include <string>
#include <algorithm> // for_each
#include <vector>
#include <set>
#include <tuple>

int main(int argc, char* argv[])
{
	//mapping from string to unsigned int
	std::map<std::string, unsigned int> PhoneBook =
		{ {"Abc", 112}, {"Xyz", 114}, {"Ghi", 115},
		  {"Jkl", 112}, {"Mno", 42} };
	std::cout << (PhoneBook.find("Xyz"))->second;

	// printing pairs with for loop
	std::cout << '\n';
	for (auto element : PhoneBook)
		std::cout << element.first << '\t' << element.second << '\n';
	
	// printing pairs with lambda expression and for_each
	std::cout << '\n';
	auto PrintPair = [](std::pair<std::string, unsigned int> element)
		{std::cout << element.first << '\t' << element.second << '\n'; };
	std::for_each(PhoneBook.begin(), PhoneBook.end(), PrintPair);

	// get all names from the map and store them in a vector
	std::vector<std::string> NamesVec;
	NamesVec.reserve(PhoneBook.size());
	std::for_each(PhoneBook.begin(), PhoneBook.end(), 
		[&NamesVec](std::pair<std::string, unsigned int> element)
		{ NamesVec.push_back(element.first); });
	std::cout << '\n';
	for (std::string names : NamesVec)
		std::cout << names << '\n';

	// get all numbers from the map and store them in a vector
	std::vector<unsigned int> NumbersVec;
	NumbersVec.reserve(PhoneBook.size());
	std::for_each(PhoneBook.begin(), PhoneBook.end(),
		[&NumbersVec](std::pair<std::string, unsigned int> element)
		{ NumbersVec.push_back(element.second); });
	std::cout << '\n';
	for (unsigned int numbers : NumbersVec)
		std::cout << numbers << '\n';

	// store the numbers in a set for checking if the numbers are unique
	std::set<unsigned int> NumbersSet;
	std::for_each(NumbersVec.begin(), NumbersVec.end(),
		[&NumbersSet](unsigned int element)
		{ NumbersSet.insert(element); });
	std::cout << '\n';
	if (NumbersVec.size() != NumbersSet.size())
		std::cout << "Not all phone numbers are unique\n\n";
	else 
		std::cout << "All phone numbers are unique\n\n";

	// reverse phone book
	std::multimap<unsigned int, std::string> PhoneBookReverse = 
		{ { 112, "Abc" }, { 114, "Xyz" }, { 115, "Ghi" },
		  { 112, "Jkl" }, { 42, "Mno" } };
	auto range = PhoneBookReverse.equal_range(112);
	for (auto i = range.first; i != range.second; ++i)
	{
		std::cout << i->first << '\t' << i->second << '\n';
	}

	// enhancement of the map with tuples including phone number and email
	std::map<std::string, std::tuple<unsigned int, std::string>> PhoneBookEnhanced =
		{ {"Abc", std::make_tuple(115, "txa@asd")}, 
		  {"Xyz", std::make_tuple(112, "vgavs@jhg")},
		  {"Mno", std::make_tuple(42, "zte2@tzui")} };
	std::cout << '\n';
	std::cout << (PhoneBookEnhanced.find("Mno"))->first << '\t' 
			  << std::get<0>((PhoneBookEnhanced.find("Mno"))->second) << '\t'
			  << std::get<1>((PhoneBookEnhanced.find("Mno"))->second) << '\n';
	


	std::cin.get();
	return 0;
}