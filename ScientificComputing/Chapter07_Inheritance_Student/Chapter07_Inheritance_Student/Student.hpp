#ifndef STUDENTCLASSHEADERDEF
#define STUDENTCLASSHEADERDEF

#include <string>

class Student
{
// constructors
public: 
	Student();
	Student(std::string Name);
	Student(std::string Name, double LibraryFines, double TuitionFees);

// member variables
public:
	std::string Name;
	double TuitionFees;
private:
	double LibraryFines;

// methods
public: 
	virtual double TotallyOwed();
	void SetLibraryFines(double x);
	double GetLibraryFines() const;
};

#endif