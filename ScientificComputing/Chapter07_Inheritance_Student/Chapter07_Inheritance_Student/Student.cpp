#include "Student.hpp"
#include <string>
#include <cassert>

Student::Student()
{
	Name = "not defined";
	LibraryFines = 0;
	TuitionFees = 0;
}

Student::Student(std::string inputName)
{
	Name = inputName;
	LibraryFines = 0;
	TuitionFees = 0;
}

Student::Student(std::string inputName, double inputLibraryFines, double inputTuitionFees)
{
	Name = inputName;
	LibraryFines = inputLibraryFines;
	TuitionFees = inputTuitionFees;
}

double Student::TotallyOwed()
{
	return (LibraryFines + TuitionFees);
}

void Student::SetLibraryFines(double x)
{
	assert(x >= 0);
	LibraryFines = x;
}

double Student::GetLibraryFines() const
{
	return LibraryFines;
}