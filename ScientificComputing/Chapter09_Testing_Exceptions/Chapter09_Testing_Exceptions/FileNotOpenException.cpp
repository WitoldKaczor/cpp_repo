#include "FileNotOpenException.hpp"

FileNotOpenException::FileNotOpenException(std::string probString)
	: Exception("File not open", probString) {}