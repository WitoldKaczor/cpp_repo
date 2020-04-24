#include <iostream>
/*Write a C++ program to find the max of an integral data set. 
The program will ask the user to input the number of data values in the set and each value. 
The program prints on screen a pointer that points to the max value.*/

int main()
{
    int setSize;
    std::cout<<"size of data set: "; std::cin>>setSize;
    
    int array[setSize], size=setSize;
    std::cout<<"numbers: "<<std::endl;
    for (;size>0;)
    {
        size--;
        std::cin>>array[size];
    }
    
    //maxFcn(){}
    int max = array[0], maxIdx = 0;
    for (;setSize>0;)
    {
        setSize--;
        if (array[setSize]>max){
            max = array[setSize];
            maxIdx = setSize;
        }
        //std::cout<<max<<std::endl;
        //std::cout<<maxIdx<<std::endl;
    }
    
    std::cout<< "max: " << *(array+maxIdx) <<std::endl;
    std::cout<< "max ptr: " << (array+maxIdx) <<std::endl;
}