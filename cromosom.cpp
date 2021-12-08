#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cstdlib>

int a[10], b[10], c[10], d[10];
float hasil_1[10];
float parent[10];
float cross = 0.7;
float save[10];
int loop = 0;
int save_1[10];

void cromosom()
{
    //Random dan operasi
    //f(x) = a + 2b + 3c + 4d = 30,
    int hasil[10];
    for (int f = 0; f <= 9; f++)
    {
        a[f] = (rand() % 30) + 1;
        b[f] = (rand() % 30) + 1;
        c[f] = (rand() % 30) + 1;
        d[f] = (rand() % 30) + 1;
        printf(" { a : %d b : %d c : %d d : %d } \n", a[f], b[f], c[f], d[f]);
        hasil[f] = a[f] + 2 * b[f] + 3 * c[f] + 4 * d[f] - 30;
        printf("Cromosom ke %d = %d \n", f, hasil[f]);
    }
    //Akhir dari random dan operasi

    //Shortir
    for (int s = 0; s < 9; s++)
    {
        for (int v = 0; v < 9 - s; v++)
        {
            if (hasil[v] > hasil[v + 1])
            {
                int asc = hasil[v];
                hasil[v] = hasil[v + 1];
                hasil[v + 1] = asc;

                int asc1 = a[v];
                a[v] = a[v + 1];
                a[v + 1] = asc1;

                int asc2 = b[v];
                b[v] = b[v + 1];
                b[v + 1] = asc2;

                int asc3 = c[v];
                c[v] = c[v + 1];
                c[v + 1] = asc3;

                int asc4 = d[v];
                d[v] = d[v + 1];
                d[v + 1] = asc4;
            }
        }
    }

    printf("\n");
    for (int ur = 0; ur < 9; ur++)
    {
        printf("Shortir urutan ke %d ", ur);
        printf(" %d \n", hasil[ur]);
    }
    printf("\n");
    for (int ab = 0; ab <= 9; ab++)
    {
        printf("%d %d %d %d \n", a[ab], b[ab], c[ab], d[ab]);
    }
    //Akhir Shortir random

    //Random parent
    printf("\n");
    for (int pr=0;pr<=9;pr++)
    {
        parent[pr] = (float)(rand() % 1000)/1000;
        printf("parent [%d] : %f \n", pr, parent[pr]);
    }
    //Selesai random parent
    printf("\n");
    //memfilter parent
    for(int pf=0; pf<=9; pf++)
    {
        if(parent[pf]<=cross)
        {
            save_1[pf] = pf;
            save[loop] = parent[pf];
            printf("parent new[%d] : %f\n", pf, save[loop]);
            loop++;
        }
    }
    //akhir filter parent
}

main()
{
    cromosom();
}