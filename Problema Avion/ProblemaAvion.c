#include "Avion.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    Avion_t a;
    maxLocuriAvion(&a, 10, 10); // cream un avion cu 10 locuri pt fiecare categorie

    char p[10] = "Andu";
    if (adaugare(&a, p, 10.23, 1) == NULL)
        return -1;
    strcpy(p, "Mgeiuhs");
    if (adaugare(&a, p, 20.45, 1) == NULL)
        return -1;
    afisarePasageri(&a, 10);
    mutarePasageri(&a, 1, 1);
    afisarePasageri(&a, 10);
}