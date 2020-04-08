#include <iostream>
#include <math.h> 

double fun(double x)
{
    //function f(x)
    return exp(-(x*x));
}

double integral(double a, double b, int n)
{
    double L = (b-a)/n;
    double sum = 0;
    
    for (int i=0; i<n; i++)
    {
       sum += fun(a+(i*L)) * L;
    }
    return sum;
}


int main()
{
    //std::cout<<fun(3)<<std::endl;
    std::cout<<integral(0, 1, 1e3)<<std::endl;

}