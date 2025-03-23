#pragma once

typedef struct
{
    char nume[41];
    float greutate;    // vom retine greutatea in kg
    unsigned int categorie : 1; // 0-categoria 1  1-categoria 2
} Pasager_t;

typedef struct
{
    Pasager_t v1[200];
    int disp1;  // locuri disponibile pentru categoria 1
    int total1; // avem nevoie sa stim numarul total de locuri pt categoria 1

    Pasager_t v2[200];
    int disp2;  // locuri disponibile pentru categoria 2
    int total2; // avem nevoie sa stim numarul total de locuri pt categoria 2
} Avion_t;

void maxLocuriAvion(Avion_t *a, int total1, int total2);
Avion_t *adaugare(Avion_t *a, char *nume, float gr_b, unsigned int nr_cat);
void afisarePasageri(Avion_t *a, float g);
int mutarePasageri(Avion_t *a, int x, unsigned int nr_cat);