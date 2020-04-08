#include <iostream>
/*Write a program with a mother class and an inherited daugther class.
Both of them should have a method void display () that prints a message 
(different for mother and daugther).
In the main define a daughter and call the display() method on it.*/

class Mother
{
    public:
    void display()
    {
        std::cout<<" M "<<std::endl;
    }
};

class Daughter : public Mother
{
    public:
    void display()
    {
        std::cout<<" D "<<std::endl;
    }
};

int main()
{
    Mother mother;
    mother.display();
    
    Daughter daughter;
    daughter.display();
}