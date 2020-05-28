#ifndef EXCEPTIONDEF
#define EXCEPTIONDEF

#include <string>

class Exception
{
public: //constructors
    Exception(std::string tagString, std::string probString);
public: // methods
    void PrintDebug() const;
private: // member variables
    std::string mTag, mProblem;
};

#endif //EXCEPTIONDEF