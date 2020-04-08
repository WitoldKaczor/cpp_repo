#include <iostream>
/*Given the string "A string." Print on one line the letter on the index 0, 
the pointer position and the letter t. undate the pointer to pointer +2. 
Then, in another line print the pointer and the letters r and g of the string (using the pointer).*/

int main() {
   char str[] = "A string.";
   char *pc = str;

   std::cout << str[0] <<' '<< *pc <<' '<<pc[3]<<"\n";
   pc += 2;
   std::cout <<*pc<<' '<< pc[2] <<' '<< pc[5];
}