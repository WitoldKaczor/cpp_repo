#include <iostream>
/*Write a program that asks for an index and a number. 
Then it includes the number at the indicated index of the array ={1,2,3,4,5,6} 
and moves a position forward (from u to u+1) each element after the selected index.*/

int main()
{
    int array[] ={1,2,3,4,5,6};
    int idx=7, num;
    
    while (idx<0 || idx>6)
    {
        std::cout<<"Index: "; std::cin>>idx;
    }
        
    std::cout<<"Number: "; std::cin>>num;
    
    for (int ctr=6; ctr>idx; ctr--)
    {
        array[ctr]=array[ctr-1];
    }
    array[idx] = num;

    for (int i=0; i<7; i++)
    {
        std::cout<<array[i]<<"  ";
    }
}