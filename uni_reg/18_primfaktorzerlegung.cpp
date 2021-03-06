extern "C" {
    #include <stdio.h>
    #include <stdlib.h>
}

//Bestimmen Sie die Primfaktorzerlegung einer eingegebenen Zahl (z.B.: 200 = 2*2*2*5*5).

int main ()
{   
    int zahl, counter=0;
    int factors[10]; // muss evtl erweitert werden
    
    printf("Zahl:\t"); 
    scanf("%d", &zahl);
    int zahl_to_print = zahl;
    
    while (zahl>1)
    {
        if (zahl%2==0)
        {
            factors[counter]=2;
            zahl /= 2;
        }
        else if (zahl%3==0)
        {
            factors[counter]=3;
            zahl /= 3;
        }
        else if (zahl%5==0)
        {
            factors[counter]=5;
            zahl /= 5;
        }
        else if (zahl%7==0)
        {
            factors[counter]=7;
            zahl /= 7;
        }
        else if (zahl%11==0)
        {
            factors[counter]=11;
            zahl /= 11;
        }
        else if (zahl%13==0)
        {
            factors[counter]=13;
            zahl /= 13;
        }
        else if (zahl%17==0)
        {
            factors[counter]=17;
            zahl /= 17;
        }
        else if (zahl%19==0)
        {
            factors[counter]=19;
            zahl /= 19;
        }
        else if (zahl%23==0)
        {
            factors[counter]=23;
            zahl /= 23;
        }
        else if (zahl%27==0)
        {
            factors[counter]=27;
            zahl /= 27;
        }
        else
        {
            printf("weitere primzahl nötig");
            exit(0);
        }
        ++counter;
    }
    
    printf("%d = ", zahl_to_print);
    for (int i=0; i<counter; ++i)
    {
        printf("%d", factors[i]);
        if (i!=counter-1)
        {
            printf(" * ");
        }
    }
    
    return 0;
}