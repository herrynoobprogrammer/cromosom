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
int save_2[10];
int new_croscrom[10][3];
float mutation_rate = 0.1;
float total_mutation;
int mutation_kro[10];
int mutation_gen[4];
float mutation_value[40];
float rata_fobj;
float F_obj[10];

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
        printf("{%d, %d, %d, %d} \n", a[ab], b[ab], c[ab], d[ab]);
    }
    //Akhir Shortir random

    //Random parent
    printf("\n");
    for (int pr = 0; pr <= 9; pr++)
    {
        parent[pr] = (float)(rand() % 1000) / 1000;
        printf("parent [%d] : %f \n", pr, parent[pr]);
    }
    //Selesai random parent
    printf("\n");
    //memfilter parent
    int pf = 0;
    int sv = 0;
    for (pf = 0; pf <= 9; pf++)
    {
        if (parent[pf] <= cross)
        {
            save_1[pf] = pf;
            save_2[sv] = pf;
            save[loop] = parent[pf];
            printf("parent new[%d] : %f {%d, %d, %d, %d}\n", pf, save[loop], a[pf], b[pf], c[pf], d[pf]);
            loop++;
            sv++;
        }
    }
    //akhir filter parent
    printf("\n");
    //Crossover
    for (int cr = 0; cr < sv; cr++)
    {
        if (cr < (sv - 1))
        {
            printf("Cromoson[%d] = Cromosom[%d] >< Cromosom[%d] \n", save_2[cr], save_2[cr], save_2[cr + 1]);
            printf("{%d, %d, %d, %d}", a[save_2[cr]], b[save_2[cr]], c[save_2[cr]], d[save_2[cr]]);
            printf(" >< ");
            printf("{%d, %d, %d, %d} ", a[save_2[cr + 1]], b[save_2[cr + 1]], c[save_2[cr + 1]], d[save_2[cr + 1]]);

            new_croscrom[cr][0] = a[save_2[cr]];
            new_croscrom[cr][1] = b[save_2[cr + 1]];
            new_croscrom[cr][2] = c[save_2[cr + 1]];
            new_croscrom[cr][3] = d[save_2[cr]];
            printf(" ==> ");
            printf("{ %d, %d, %d, %d}\n", new_croscrom[cr][0], new_croscrom[cr][1], new_croscrom[cr][2], new_croscrom[cr][3]);
        }
        else
        {
            printf("Cromoson[%d] = Cromosom[%d] >< Cromosom[%d] \n", save_2[cr], save_2[cr], save_2[0]);
            printf("{%d, %d, %d, %d}", a[save_2[cr]], b[save_2[cr]], c[save_2[cr]], d[save_2[cr]]);
            printf(" >< ");
            printf("{%d, %d, %d, %d}", a[save_2[0]], b[save_2[0]], c[save_2[0]], d[save_2[0]]);
            new_croscrom[cr][0] = a[save_2[cr]];
            new_croscrom[cr][1] = b[save_2[0]];
            new_croscrom[cr][2] = c[save_2[0]];
            new_croscrom[cr][3] = d[save_2[cr]];
            printf(" ==> ");
            printf(" {%d, %d, %d, %d}\n", new_croscrom[cr][0], new_croscrom[cr][1], new_croscrom[cr][2], new_croscrom[cr][3]);
        }
    }
    //End of Crossover

    //Mutation
    total_mutation = 40 * mutation_rate;
    printf("\nMutation = %f\n", total_mutation);
    printf("\nPosisi Mutasi Kromosom \t\t|| Nilai Mutasi");
    for (int o = 0; o <= total_mutation - 1; o++)
    {
        mutation_kro[o] = (rand() % 10);
        mutation_gen[o] = (rand() % 4);
        mutation_value[o] = (float)(rand() % 30);
        new_croscrom[(mutation_kro[o])][(mutation_gen[o])] = mutation_value[o];
        printf("\nKromosom[%i]gen[%i] \t\t|| %f\n", mutation_kro[o], mutation_gen[o], mutation_value[o]);
        for (int m = 0; m <= 3; m++)
        {
            printf("%d ,", new_croscrom[(mutation_kro[o])][m]);
        }
        printf("\n");
    }
    //End of Mutation

    //New Cromosom
    printf("\nHasil Chromosom baru \n");
    for (int i = 0; i <= 8; i++)
    {
        printf("Chromosom [%i]\n \t==> ", i);
        for (int j = 0; j <= 3; j++)
        {
            printf("%d; ", new_croscrom[i][j]);
        }
        printf("\n");
    }
    //End

    //Evaluation
    printf("\nHasil Objective Function : \n");
    for (int i = 0; i <= 8; i++)
    {
        F_obj[i] = abs((new_croscrom[i][0] + 2 * new_croscrom[i][1] + 3 * new_croscrom[i][2] + 4 * new_croscrom[i][3]) - 30);
        printf("F_obj [%i] = %f\n", i, F_obj[i]);
    }
    //End of evaluation

    //Rata2
    for (int y = 0; y <= 8; y++)
    {
        rata_fobj = rata_fobj + F_obj[y];
    }
    printf("Rata-rata F Objek = %f\n", rata_fobj / 10.0);
    rata_fobj = 0;
}

main()
{
    cromosom();
}