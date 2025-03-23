// cautare binara pe biti

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int valid(int *v, int INDEX, int k)
{
    return v[INDEX] < k;
}

int calc_cur_pow(int n)
{
    int cur_pow = 1;
    int pow = 1;
    while ((cur_pow << 1) < n)
    {
        pow = cur_pow;
        cur_pow <<= 1;
    }
    return pow;
}

int BSbiti0(int *v, int n, int k)
{
    int acc = 0, cur_pow_2 = calc_cur_pow(n);
    while (cur_pow_2 > 0)
    {
        if (valid(v, acc + cur_pow_2, k))
        {
            acc += cur_pow_2;
        }
        cur_pow_2 = cur_pow_2 >> 1;
    }
    return acc;
}
int BSbiti1(int *v, int n, int k)
{
    unsigned int acc = 0, cur_pow_2 = calc_cur_pow(n);
    while (cur_pow_2 > 0)
    {
        if (v[acc + cur_pow_2] <= k)
        {
            acc += cur_pow_2;
        }
        cur_pow_2 = cur_pow_2 >> 1;
    }
    return v[acc];
}
int BSbiti2(int *v, int n, int k)
{
    unsigned int acc = 0, max_pow_2 = calc_cur_pow(n);
    int cur_pow = 1;
    while (cur_pow < max_pow_2)
    {
        if (v[acc + cur_pow] > k)
        {
            acc += cur_pow;
        }
        cur_pow = cur_pow << 1;
    }
    return v[acc];
}
int main()
{
    FILE *fin, *fout;
    fin = fopen("cautbin.in", "r");
    if (fin == NULL)
    {
        perror("nu s a citit fisier");
        exit(EXIT_FAILURE);
    }
    fout = fopen("cautbin.out", "w");
    if (fout == NULL)
    {
        perror("nu s a citit fisier");
        exit(EXIT_FAILURE);
    }
    int n;
    fscanf(fin, "%d", &n);
    int v[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(fin, "%d ", &v[i]);
    }
    int m;
    fscanf(fin, "%d", &m);
    for (int rezolvari = 0; rezolvari < m; rezolvari++)
    {
        int mode, number;
        fscanf(fin, "%d %d\n", &mode, &number);
        switch (mode)
        {
        case 0:
        {
            int i;
            i = BSbiti0(v, n, number);
            while ((v[i] <= number))
            {
                i++;
            }
            if (v[i - 1] != number)
                fprintf(fout, "%d\n", -1);
            else
                fprintf(fout, "%d\n", i);
            break;
        }
        case 1:
        {
            fprintf(fout, "%d\n", BSbiti1(v, n, number) + 1);
            break;
        }

        case 2:
        {
            fprintf(fout, "%d\n", BSbiti2(v, n, number) + 1);
            break;
        }

        default:
            break;
        }
    }
}