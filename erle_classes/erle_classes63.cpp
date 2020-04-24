#include <iostream>
//Take input in variable and display same value by pointer.

int main()
{
    int var;
    std::cin>>var;
    
    int* ptr = &var;
    
    std::cout<<"var "<< *ptr << " in address " << ptr;
}