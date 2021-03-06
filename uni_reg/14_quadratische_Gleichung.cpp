extern "C" {
#include <stdio.h>
}
#include <math.h>
//physik.uni.regensburg
//Aufgabe 14

/*L¨osen Sie die quadratische Gleichung ax2 + bx + c = 0 fur vom Benutzer eingegebene Para- ¨
meter a, b und c. Falls Ihnen komplexe Zahlen gel¨aufig sind, sollen auch komplexe L¨osungen
ausgegeben werden.
sqrt(float) zur Berechnung der Wurzel einer positiven Zahl ist in math.h*/

int main()
{
    float a, b, c;
    float x1, x2, imag;
    printf("a:\t"); scanf("%f", &a);
    printf("b:\t"); scanf("%f", &b);
    printf("c:\t"); scanf("%f", &c);
    
    if (a==0)
    {
        printf("not a quadratic equation!");
    }
    else
    {
        if (b*b - 4*a*c == 0)
        {
            x1 = -b/(2*a);
            printf("x1 = x2 = %.2f", x1);
        }
        else if (b*b - 4*a*c > 0)
        {
            x1 = (- b + sqrt(b*b - 4*a*c))/(2*a);
            x2 = (- b - sqrt(b*b - 4*a*c))/(2*a);
            printf("x1 = %.2f, x2 = %.2f", x1, x2);
        }
        else 
        {
            imag = sqrt(4*a*c - b*b)/(2*a);
            x1 = -b/(2*a);
            printf("x1 = %.2f+%.2fi, x2 = %.2f-%.2fi", x1, imag, x1, imag);
        }
    }
    
    return 0;
}