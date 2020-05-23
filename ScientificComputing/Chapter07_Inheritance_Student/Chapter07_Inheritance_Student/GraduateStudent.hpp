#ifndef GRADUATESTUDENTCLASSHEADERDEF
#define GRADUATESTUDENTCLASSHEADERDEF

#include <string>
#include "Student.hpp"

class GraduateStudent : public Student
{
// constructors
public:
	// inherit all constructors from Student
	using Student::Student; 

// member variables
public: 
	std::string StudyForm = "full-time"; // full- or part-time

// methods
public:
	double TotallyOwed();
};

#endif