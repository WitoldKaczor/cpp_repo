#include <iostream>
/*Write a program that ask for two numbers, compare them and show the maximun.
Declare a function called max_two that compares the numbers and returns the maximun.*/

float max_two(float a, float b)
{
    if (a>=b)
        return a;
    else
        return b;
}   

int main()
{
    float num1, num2; 
    std::cout<<"num1: "; 
    std::cin>>num1;
    std::cout<<"num2: "; 
    std::cin>>num2;
    std::cout<<"max: "<<max_two(num1,num2)<<std::endl;
}