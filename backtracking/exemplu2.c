/*Se dă un număr natural n. Determinați, în ordine lexicografică, toate modalitățile de a-l scrie pe n ca sumă de numere naturale impare distincte.*/

#include <stdio.h>
#include <stdlib.h>

int n = 3;
int v[100];
int nSolutii = 0;

void afisare(int k)
{
    nSolutii++;
    for (int i = 0; i <= k; i++)
    {
        printf("%d ", v[i]);
    }
    putchar('\n');
}

int solutie(int k)
{
    if (k < 1)
        return 0;
    int sum = 0;
    for (int i = 0; i <= k; i++)
    {
        sum += v[i];
    }
    return sum == n;
}

int valid(int k)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j <= k; j++)
        {
            if (v[i] == v[j] || v[j] < v[i])
                return 0;
        }
        if (v[i] % 2 == 0)
            return 0;
    }
    return 1;
}
void back(int k)
{
    for (int i = 1; i <= n; i += 2)
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
    if (nSolutii == 0)
    {
        printf("imposibil");
    }
}