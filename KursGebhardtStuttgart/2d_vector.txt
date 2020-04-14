#include <iostream>
#include <math.h>

class Vec2D
{
    public:
    Vec2D() {}; //Konstruktor
    Vec2D(double x, double y) : x(x), y(y) {}; //Konstruktor
    Vec2D(const Vec2D& vec) : x(vec.x), y(vec.y) {}; //Konstruktor
    
    void print() { std::cout << "{ " << x << "  " << y << " }"; }
    
    double getX() const { return x; }
    double getY() const { return y; }
    
    void setX(double number) { x = number; }
    void setY(double number) { y = number; }
    
    double betrag() const
    {
        return sqrt(x*x + y*y);
    }
    
    double skalarProdukt (const Vec2D& anotherVec2D) const
    {
        return x*anotherVec2D.x + y*anotherVec2D.y ;
    }
    
    Vec2D operator + (const Vec2D& anotherVec2D) 
    {
        Vec2D ergebnis;
        ergebnis.x = x + anotherVec2D.x;
        ergebnis.y = y + anotherVec2D.y;
        return ergebnis;
    }
    
    Vec2D operator - (const Vec2D& anotherVec2D)
    {
        Vec2D erg;
        erg.x = x - anotherVec2D.x;
        erg.y = y - anotherVec2D.y;
        return erg;
    }
    
    
    private:
    double x=0, y=0;
};


int main()
{
    Vec2D a(8.5,11);
    
    std::cout << "a = "; a.print(); std::cout << "\n";
    
    a.setX(4);
    a.setY(3);
    
    std::cout << "x: " << a.getX() <<std::endl;
    std::cout << "y: " << a.getY() <<std::endl;
    
    std::cout << "betrag " << a.betrag() <<std::endl;
    
    Vec2D b(2.5,10);
    std::cout << "b = "; b.print(); std::cout << "\n";
    
    std::cout << "Skalarprodukt von ";
        a.print();
        std::cout << " und ";
        b.print(); 
        std::cout << " ist gleich " << a.skalarProdukt(b) << std::endl;
        
    Vec2D c(b);
    std::cout << "c = "; c.print(); std::cout << "\n";
    
    Vec2D sum = b + c;
    std::cout << "b + c = "; sum.print(); std::cout << "\n";
    
    Vec2D diff = a - b;
    std::cout << "a - b = "; diff.print(); std::cout << "\n";
}
