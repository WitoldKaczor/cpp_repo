#include <iostream>
/*Write a program that asks a name say hello. Use your own function, 
that recives a string of characters (name) and prints on screen the hello message.*/

std::string getname()
{
    std::string name;
    std::cin>>name;
    return name;
}

void printgreet(std::string name)
{
    std::cout<<"Hello, "<<name<<std::endl;
}

int main()
{
    printgreet(getname());
}