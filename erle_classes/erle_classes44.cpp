#include <iostream>
/*Write a program that asks the user for an integer number and 
find the sum of all natural numbers upto that number.*/

int cumsum_rek(int x)
{
    if (x==1)
        return 1;
    else
        return x + cumsum_rek(x-1);
}

int cumsum(int x)
{
    int sum = 0;
    for (int i=1; i<=x; i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    int x;
    std::cout<<"x: ";
    std::cin>>x;
    std::cout<<"cum sum rek: "<<cumsum_rek(x)<<std::endl;
    std::cout<<"cum sum: "<<cumsum(x)<<std::endl;
}