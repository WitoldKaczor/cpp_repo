#ifndef FILENOTOPENEXCEPTIONDEF
#define FILENOTOPENEXCEPTIONDEF

#include "Exception.hpp"

class FileNotOpenException : public Exception
{
public: //constructors
	FileNotOpenException(std::string probString);
};

#endif