#ifndef PHDSTUDENTCLASSHEADERDEF
#define PHDSTUDENTCLASSHEADERDEF

#include "GraduateStudent.hpp"

class PhDStudent : public GraduateStudent
{
// constructors
public:
	// inherit all constructors from GraduateStudent
	using GraduateStudent::GraduateStudent;

// methods
public:
	double TotallyOwed();
};

#endif