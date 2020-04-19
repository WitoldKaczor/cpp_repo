#include <iostream>
#include <math.h>
//globale Funktion innerhalb einer Klasse verwenden

class Power 
{
    public:

    void pow(int x, int y)
    {
        int z = ::pow(x,y);
        std::cout << "Power: " << z << std::endl;
    }
    
};

int main()
{
    Power power;
    
    power.pow(2,3);
    std::cout << pow(2,3) << std::endl;
}