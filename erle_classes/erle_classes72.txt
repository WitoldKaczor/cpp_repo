#include <iostream>
/*Write a program and input two integers in main and 
pass them to default constructor of the class. 
Show the result of the additon of two numbers.*/

class data {
    public:
    int n1, n2;
    
    //Constructor
    data(int num1, int num2)
    {
        n1 = num1;
        n2 = num2;
    }
    
    int sum_num()
    {
        return n1+n2;
    }
};

int main()
{
    int x, y;
    
    std::cout<<"Input first number: ";
    std::cin>>x;
    std::cout<<"Input second number: ";
    std::cin>>y;
    
    data data1(x, y);
    
    std::cout<<data1.sum_num()<<std::endl;
}
