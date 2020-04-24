#include <iostream>
/*Write a class having two private variables and 
one member function which will return the area of the rectangle.*/

class AreaRectangle {
    private:
    float a;
    float b;
    public:
    float areaCalc(float a, float b)
    {
        return a*b;
    }
};

int main()
{
    float x, y;
    
    std::cout<<"Input first number: ";
    std::cin>>x;
    std::cout<<"Input second number: ";
    std::cin>>y;
    
    AreaRectangle area1;
    
    std::cout<<"Area: "<<area1.areaCalc(x, y)<<std::endl;
}
