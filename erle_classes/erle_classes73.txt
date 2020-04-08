#include <iostream>

class student
{
    public:
    std::string name;
    float marks1, marks2;
    
    void input()
    {
        std::cout<<"Name: ";
        std::cin>>name;
        std::cout<<"Marks1: ";
        std::cin>>marks1;
        std::cout<<"Marks2: ";
        std::cin>>marks2;
    }
    
    float calc_media()
    {
        float totalMarks = (marks1+marks2)/2;
        return totalMarks;
    }
    
    void disp()
    {
        std::cout<<"Name: "<<name<<std::endl;;
        std::cout<<"Total marks: "<<calc_media()<<std::endl;;
    }
    
};

int main()
{
    student s1;
    s1.input();
    s1.disp();
}