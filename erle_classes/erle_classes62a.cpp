#include <iostream>
/*Write a C++ program to find the max of an integral data set. 
The program will ask the user to input the number of data values in the set and each value. 
The program prints on screen a pointer that points to the max value.*/

int maxIdxFcn(int* arr, int arrSize)
{
    int max = arr[0], maxIdx = 0;
    for (;arrSize>0;)
    {
        arrSize--;
        if (arr[arrSize]>max){
            max = arr[arrSize];
            maxIdx = arrSize;
        }
    }
    return maxIdx;
}

int main()
{
    int setSize;
    std::cout<<"size of data set: "; std::cin>>setSize;
    
    int array[setSize], size=setSize, arrSize=setSize;
    std::cout<<"numbers: "<<std::endl;
    for (;size>0;)
    {
        size--;
        std::cin>>array[size];
    }
    
    std::cout<< "max Idx: " << maxIdxFcn(array, arrSize) <<std::endl;
    std::cout<< "max: " << array[maxIdxFcn(array, arrSize)] <<std::endl;
    std::cout<< "max: " << *(array+maxIdxFcn(array, arrSize)) <<std::endl;
    std::cout<< "max ptr: " << array+maxIdxFcn(array, arrSize) <<std::endl;
}