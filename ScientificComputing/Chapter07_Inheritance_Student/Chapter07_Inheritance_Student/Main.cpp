#include "Student.hpp"
#include "GraduateStudent.hpp"
#include "PhDStudent.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	Student student1;
	std::cout << student1.Name << '\n';

	Student student2("xyz");
	std::cout << student2.Name << '\n';

	Student student3("abc", 0.0, 5.0);
	std::cout << student3.Name << '\n';

	GraduateStudent student4;
	std::cout << student4.Name << '\n';

	GraduateStudent student5("grad xyz");
	std::cout << student5.Name << '\n';

	GraduateStudent student6("grad abc", 0.0, 5.0);
	std::cout << student6.Name << '\n';

	PhDStudent student7;
	std::cout << student7.Name << '\n';

	PhDStudent student8("grad xyz");
	std::cout << student8.Name << '\n';

	PhDStudent student9("grad abc", 0.0, 5.0);
	std::cout << student9.Name << '\n';

	std::cin.get();
	return 0;
}