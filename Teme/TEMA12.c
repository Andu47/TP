/*#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/*Se citesc doua numere naturale n si k. Generati si afisati toate toate numerele naturale formate din
n cifre care contin exact k cifre de 1.*/
/*int n = 3, x = 2;
int v[100];

int valid(int k)
{
    if ((v[0] == 0 && n > 1) || k > n)
        return 0;
    return 1;
}

int solutie(int k)
{
    if (k != n - 1)
        return 0;
    int cfr = 0;
    for (int i = 0; i < n; i++)
        if (v[i] == 1)
            cfr++;
    if (cfr != x)
        return 0;
    return 1;
}

void afisare()
{
    for (int i = 0; i < n; i++)
        printf("%d", v[i]);
    printf("\n");
}

void back(int k)
{
    for (int i = 0; i <= 9; i++)
    {
        v[k] = i;
        if (valid(k))
        {
            if (solutie(k))
            {
                afisare();
            }
            else
            {
                back(k + 1);
            }
        }
    }
}

int main()
{
    back(0);
}*/

/*Aplicația 12.4: Se dau urmatoarele 6 culori: alb, galben, rosu, verde, albastru si negru.
Costruiti toate steagurile formate din 3 culori care indeplinesc urmatoarele conditii:
- orice steag trebuie sa contina culoarea verde sau culoarea galben la mijloc.
- culorile din fiecare steag trebuie sa fie distincte.*/
#include <stdio.h>
#include <stdlib.h>
// alb-1 galben-2 rosu-3 verde-4 albastru-5 negru-6
int v[3], n;

int valid(int k)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j <= k; j++)
        {
            if (v[i] == v[j])
                return 0;
        }
    }
    return 1;
}

int solutie(int k)
{
    if (k != 2)
        return 0;
    if (v[1] != 2 && v[1] != 4)
        return 0;
    return 1;
}

void afisare()
{
    for (int i = 0; i <= 2; i++)
    {
        printf("%d ", v[i]);
    }
    putchar('\n');
}

void back(int k)
{
    for (int i = 1; i <= 6; i++)
    {
        v[k] = i;
        if (valid(k))
        {
            if (solutie(k))
            {
                afisare();
            }
            else
            {
                back(k + 1);
            }
        }
    }
}

int main()
{
    back(0);
}