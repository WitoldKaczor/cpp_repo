#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

#include <cmath>
#include <iostream>
#include <cassert>

class Vector
{
private:
   double* mData; // data stored in vector
   int mSize; // size of vector
public:
   Vector(const Vector& otherVector);
   Vector(int size);
   ~Vector();
   int GetSize() const;
   double& operator[](int i); // zero-based indexing
   double Read(int i) const; // read-only zero-based indexing 
   double& operator()(int i); // one-based indexing
   double& operator()(int i) const; // const one-based indexing
   Vector& operator=(const Vector& otherVector); // assignment
   Vector operator+() const; // unary +
   Vector operator-() const; // unary -
   Vector operator+(const Vector& v1) const; // binary +
   Vector operator-(const Vector& v1) const; // binary -
   Vector operator*(double a) const; // scalar multiplication
   double CalculateNorm(int p = 2) const; // p-norm method
   friend int length(const Vector& v); // declare length function as a friend
   friend std::ostream& operator<<(std::ostream& output, const Vector& v1);
};

// Prototype signature of length() friend function
int length(const Vector& v);

#endif