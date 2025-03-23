#include "Avion.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

void maxLocuriAvion(Avion_t *a, int total1, int total2) // functie care transmite nr maxim de locuri pt fiecare categorie
{
    a->disp1 = total1;
    a->disp2 = total2;
    a->total1 = total1;
    a->total2 = total2;
}

Avion_t *adaugare(Avion_t *a, char *nume, float gr_b, unsigned int nr_cat)
{
    if (!nr_cat && a->disp1 == 0)
    {
        printf("Nu mai sunt locuri disponibile la categoria 1\n");
        return a;
    }
    if (nr_cat && a->disp2 == 0)
    {
        printf("Nu mai sunt locuri disponibile la categoria 2\n");
        return a;
    }
    if (!nr_cat && a->disp1 > 0) // pt categoria 1
    {
        // creem aux cu datele unui pasager
        Pasager_t aux;
        strcpy(aux.nume, nume);
        aux.greutate = gr_b;
        aux.categorie = nr_cat;

        (a->v1)[a->total1 - a->disp1] = aux;
        a->disp1--;
    }
    if (nr_cat && a->disp2 > 0) // pt categoria 2
    {
        // creem aux cu datele unui pasager
        Pasager_t aux;
        strcpy(aux.nume, nume);
        aux.greutate = gr_b;
        aux.categorie = nr_cat;

        (a->v2)[a->total2 - a->disp2] = aux;

        a->disp2--;
    }
    return a;
}

int comparare(const void *p1, const void *p2)
{
    Pasager_t *a = (Pasager_t *)p1;
    Pasager_t *b = (Pasager_t *)p2;
    return strcmp(a->nume, b->nume);
}
void afisarePasageri(Avion_t *a, float g) // O(n*(log(n)+1))
{
    // vom pune toti pasagerii in acelasi vector aux
    Pasager_t aux[400]; // folosind aux nu schimbam ordinea pasagerilor in avion

    memcpy(aux, a->v1, a->total1 * sizeof(Pasager_t));
    memcpy(aux + a->total1, a->v2, a->total2 * sizeof(Pasager_t));

    int total = a->total1 + a->total2;

    // sortam elementele
    qsort(aux, total, sizeof(Pasager_t), comparare); // O(n*logn)

    for (int i = 0; i < total; i++)
    {
        if (aux[i].greutate > g) // afisam doar pasagerii cu bagajele mai grele ca g
        {
            if (aux[i].categorie)
            {
                printf("%40s; %.2fkg; categoria 2\n", aux[i].nume, aux[i].greutate);
            }
            else
            {
                printf("%40s; %.2fkg; categoria 1\n", aux[i].nume, aux[i].greutate);
            }
        }
    } // O(n)
}

int mutarePasageri(Avion_t *a, int x, unsigned int nr_cat)
{
    if (!nr_cat) // vom muta din cat1 in cat2
    {
        int nrPasMutati = min(x, a->total1 - a->disp1); // mutam maxim nr de pasageri din cat1
        nrPasMutati = min(nrPasMutati, a->disp2);       // mutam maxim br de pasageri ce au loc in cat2
        if (nrPasMutati != 0)
        {
            int current1 = a->total1 - a->disp1; // prima pozitie goala de la cat1
            int current2 = a->total2 - a->disp2; // prima pozitie goala de la cat2
            for (int i = 0; i < nrPasMutati; i++)
            {
                a->v2[current2 + i] = a->v1[current1 - nrPasMutati + i];
                a->v2[current2 + i].categorie = 0;
                a->disp1++;
                a->disp2--;
            }
        }
        return nrPasMutati;
    }
    else
    {
        int nrPasMutati = min(x, a->total2 - a->disp2); // mutam maxim nr de pasageri din cat2
        nrPasMutati = min(nrPasMutati, a->disp1);       // mutam maxim br de pasageri ce au loc in cat1
        if (nrPasMutati != 0)
        {
            int current1 = a->total1 - a->disp1; // prima pozitie goala de la cat1
            int current2 = a->total2 - a->disp2; // prima pozitie goala de la cat2
            for (int i = 0; i < nrPasMutati; i++)
            {
                a->v1[current1 + i] = a->v2[current2 - nrPasMutati + i];
                a->v1[current1 + i].categorie = 1;
                a->disp1--;
                a->disp2++;
            }
        }
        return nrPasMutati;
    }
}