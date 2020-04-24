#include <iostream>
/*Create an array that can hold ten integers, and get input from user. 
Display those values on the screen, and then prompt the user for an integer. 
Search through the array, and count the number of times the item is found.*/

int main()
{
    int arr[5];
    
    int num;
    for (int i=0; i<5; i++)
    {
        std::cin>>num;
        arr[i]=num;
    }
    
    std::cout<<"int: ";
    std::cin>>num;
    
    int ctr=0;
    for (int i=0; i<5; i++)
    {
        if (arr[i]==num)
        {
            ctr++;
        }
    }
    std::cout<<"ctr: "<<ctr;
}