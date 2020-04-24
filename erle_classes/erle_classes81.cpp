#include <iostream>
/*Write a program that defines a shape class with a constructor that gives value to width and height.
The define two sub-classes triangle and rectangle, that calculate the area of the shape area (). 
In the main, define two variables a triangle and a rectangle and then call the area() function 
in this two varibles.*/

class Shape 
{
    protected:
    float m_width, m_height;
    
    public:
    Shape()
        : m_width(0), m_height(0) {}
    Shape(float width, float height)
        : m_width(width), m_height(height) {}
};

class Triangle : public Shape 
{
    public:
    using Shape::Shape;
    float area()
    {
        return (m_width*m_height/2);
    }
};

class Rectangle : public Shape 
{
    public:
    using Shape::Shape;
    float area()
    {
        return (m_width*m_height);
    }
};

int main()
{
    float width = 7, heigth = 9;
    
    Triangle triangle1;
    Triangle triangle2(width, heigth);
    Rectangle rectangle1(width, heigth);
    
    std::cout<<"area triangle1: "<< triangle1.area() <<std::endl;
    std::cout<<"area triangle2: "<< triangle2.area() <<std::endl;
    std::cout<<"area rectangle1: "<< rectangle1.area() <<std::endl;
}