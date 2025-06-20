#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int n = 3, m = 6;
FILE *out;
int sol[MAX];

void crearefisier()
{
    FILE *f = fopen("SESIUNE.IN", "wb");
    int n = 3;
    int m = 6;
    fwrite(&n, sizeof(int), 1, f);
    fwrite(&m, sizeof(int), 1, f);
    fclose(f);
}

int valid(int poz)
{
    if (poz > m)
        return 0;
    if (sol[poz] == 0)
        return 1;

    for (int i = 0; i < poz; i++)
    {
        if (sol[poz] <= sol[i] && sol[i] != 0)
            return 0;
    }

    if (poz == 0 || sol[poz - 1] == 0)
        return 1;

    return 0;
}

int solutie(int poz)
{
    if (poz != m - 1)
        return 0;

    int frec[MAX] = {0};
    for (int i = 0; i < m; i++)
    {
        if (sol[i] != 0)
            frec[sol[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (frec[i] == 0)
            return 0;
    }
    return 1;
}

void back(int poz)
{
    for (int i = 0; i <= n; i++)
    {
        sol[poz] = i;
        if (valid(poz))
        {
            if (solutie(poz))
            {
                for (int j = 0; j < m; j++)
                {
                    fprintf(out, "%d ", sol[j]);
                    // printf("%d ", sol[j]);
                }
                fprintf(out, "\n");
                // printf("\n");
            }
            else
                back(poz + 1);
        }
    }
}

int main()
{
    crearefisier();
    FILE *in = fopen("SESIUNE.IN", "rb");
    out = fopen("CALENDAR.TXT", "w");

    fread(&n, sizeof(int), 1, in);
    fread(&m, sizeof(int), 1, in);

    back(0);

    fclose(in);
    fclose(out);
    return 0;
}
