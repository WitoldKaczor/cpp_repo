#include <iostream>
/*Write a program with a mother class animal. 
Inside it define a name and an age variables, and set_value() function.
Then create two bases variables Zebra and Dolphin which write a message 
telling the age, the name and giving some extra information (e.g. place of origin).*/

class Animal
{
    protected:
    std::string m_name;
    int m_age;
    
    public:
    void set_value(std::string name, int age)
    {
        m_name = name;
        m_age = age;
    }
};

class Zebra : public Animal
{
    public:
    void getInfo()
    {
        std::cout<<"age: "<< m_age <<std::endl;
        std::cout<<"name: Zebra "<< m_name <<std::endl;
        std::cout<<"info xxx"<<std::endl;
    }
};

class Dolphin : public Animal
{
    public:
    void getInfo()
    {
        std::cout<<"age: "<< m_age <<std::endl;
        std::cout<<"name: Dolphin "<< m_name <<std::endl;
        std::cout<<"info yyy"<<std::endl;
    }
};

int main()
{
    Zebra zebra1;
    zebra1.set_value("Zdzichu", 13);
    zebra1.getInfo();
    
    Dolphin dolphin1;
    dolphin1.set_value("Marian", 69);
    dolphin1.getInfo();
}