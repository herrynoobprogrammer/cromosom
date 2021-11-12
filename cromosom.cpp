#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cstdlib>

int a,b,c,d;
int _rand[10];

void cromosom()
{
    //f(x) = a + 2b + 3c + 4d = 30,
    int hasil[10];
    for(int f=0;f<=9;f++)
    {
        a = (rand() % 30) + 1;
        b = (rand() % 30) + 1;
        c = (rand() % 30) + 1;
        d = (rand() % 30) + 1;
        printf(" Random a : %d b : %d c : %d d : %d \n", a,b,c,d);
        hasil[f] = a + 2*b + 3*c + 4*d - 30;
        printf("Cromosom ke %d = %d \n",f,hasil[f]);
    }

    for(int s=0;s<9;s++)
    {
        for(int v=0;v<9-s;v++)
        {
            if(hasil[v] > hasil[v+1])
            {
                int asc=hasil[v];
                hasil[v]=hasil[v+1];
                hasil[v+1]=asc;
            }
        }
    }

    for(int ur=0;ur<9;ur++)
    {
        printf("Shortir urutan ke %d ", ur);
        printf(" %d \n",hasil[ur]);
    }
    
}

void shortir(){

}
main(){
    cromosom();
}