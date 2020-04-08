#include <iostream>
#include <math.h> 

double wurzel(int n, double x)
{
    if (n!=0)
    {
        return (wurzel(n-1,x) + x/wurzel(n-1,x))/2;
    }
    else
        return 1;
}   

int main()
{
    double zahl = 1986;
    
    std::cout<< sqrt(zahl) <<std::endl;
    std::cout<< wurzel(8, zahl) <<std::endl;
}