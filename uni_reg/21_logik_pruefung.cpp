extern "C" {
    #include <stdio.h>
}
//physik.uni.regensburg
//Aufgabe 21

int main()
{
    int a=0, b=0, c=0, d=0;
    
    for (a=0; a<=1; a++)
    {
        for (b=0; b<=1; b++)
        {
            for (c=0; c<=1; c++)
            {
                for (d=0; d<=1; d++)
                {
                    if (a+b+c+d>0) //Mindestens ein Familienmitglied geht zu der Feier.
                    {
                        if (a!=d | a==0) //Anton geht auf keinen Fall zusammen mit Doris.
                        {
                            if (b==c | b==0) //Wenn Berta geht, dann geht Claus mit.
                            {
                                if (a==1 & c==1 & b==0 | a!=c) //Wenn Anton und Claus gehen, dann bleibt Berta zu Hause.
                                {
                                    if (c!=d | a==1) //Wenn Anton zu Hause bleibt, dann geht entweder Doris oder Claus.
                                    {
                                        printf("a = %d, b = %d, c = %d, d = %d\n",a,b,c,d);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}