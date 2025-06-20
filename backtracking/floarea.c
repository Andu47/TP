/*#include <stdio.h>
#include <stdlib.h>
// toate permutarile de n cifre, cu prima jum cresc si a doua descresc
int v[100];
int n = 6;

void afisare(int k)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    putchar('\n');
}

int valid(int k)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j <= k; j++)
            if (v[i] == v[j])
                return 0;
    }
    return 1;
}

int solutie(int k)
{
    if (k != n - 1)
        return 0;
    for (int i = 0; i < k / 2; i++)
    {
        if (v[i] > v[i + 1])
            return 0;
    }
    for (int i = k / 2 + 1; i < k; i++)
    {
        if (v[i] < v[i + 1])
            return 0;
    }
    return 1;
}

void back(int k)
{
    for (int i = 1; i <= n; i++)
    {
        v[k] = i;
        if (valid(k))
        {
            if (solutie(k))
            {
                afisare(k);
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

#include <stdio.h>
#include <stdlib.h>

int main(){
    
}