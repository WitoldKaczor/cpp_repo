#ifndef OUTOFRANGEEXCEPTIONDEF
#define OUTOFRANGEEXCEPTIONDEF

#include "Exception.hpp"

class OutOfRangeException : public Exception
{
public: //constructors
	OutOfRangeException(std::string probString);
};

#endif