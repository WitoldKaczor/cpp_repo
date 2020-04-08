/*Write a program that asks the user to enter integers as inputs to be stored 
in the variables 'a' and 'b' respectively. There are also two integer pointers 
named ptrA and ptrB. Assign the values of 'a' and 'b' to ptrA and ptrB respectively, 
and display them.*/

int main()
{
    int a, b, *ptrA, *ptrB;
    
    std::cout<<"a: "; std::cin>>a;
    std::cout<<"b: "; std::cin>>b;
    
    ptrA = &a;
    ptrB = &b;
    
    std::cout<< *ptrA <<" in address "<< ptrA <<std::endl;
    std::cout<< *ptrB <<" in address "<< ptrB <<std::endl;
}