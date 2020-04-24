extern "C" {
#include <stdio.h>
}
//physik.uni.regensburg
//Aufgabe 17

/*Lesen Sie eine Integerzahl ein und geben Sie deren Bitmuster aus 
(z.B.: 23 ! 00010111).*/

int main()
{
    int num;
    int bit_array[8];
    printf("Zahl dezimal: ");
    scanf("%d", &num);
    
    int ctr=0;
    while (num>=1)
    {
        bit_array[ctr] = num%2;
        num -= num%2;
        num /= 2;
        ++ctr;
    }
    //printf("ctr = %d\n", ctr);
    
    for (int i=ctr-1; i>=0; --i)
    {
        printf("%d", bit_array[i]);
    }
    
    return 0;
}

