#include <iostream>
/*Perform addition operation on complex data using class and object.
The program should ask for real and imaginary part of two complex numbers, 
and display the real and imaginary parts of their sum.*/

class imaginary
{
    public:
    float real, imag;
    
    imaginary(float r, float i)
    {
        real = r;
        imag = i;
    }
    
    void dispNum()
    {
        std::cout<<real<<"+"<<imag<<"i"<<std::endl;
    }
    
    public:
    void sum(imaginary number)
    {
        float sumReal = real + number.real;
        float sumImag = imag + number.imag;
        std::cout<<sumReal<<"+"<<sumImag<<"i"<<std::endl;
    }
};

int main()
{
    imaginary num1(1, 2);
    imaginary num2(3, 2);
    
    num1.dispNum();
    num2.dispNum();
    
    num1.sum(num2);
}