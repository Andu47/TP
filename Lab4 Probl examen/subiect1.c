#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHUNK 10

typedef struct
{
    unsigned int cod : 14;   // 1-9000
    unsigned int locuri : 4; // 1-9
    unsigned int CP : 9;     // cai putere
    char *marca, *culoare;
    // culoarea putea fi scrisa si in cod Hex
    unsigned int an : 8; // an+1800 pt afisare
} masina;

// static pentru a fi vizibile doar in acest file
static masina *parc; // vom folosi un parc declarat global (sir de masini)
static int lenPark = 0;
static int currentLen = 0;
void eliberareMemorie()
{
    for (int i = 0; i < currentLen; i++)
    {
        free(parc[i].marca);
        free(parc[i].culoare);
    }
    free(parc);
}
void copiereMasina(masina *parc, int poz, unsigned int cod, unsigned int locuri, unsigned int CP, char *marca, char *culoare, unsigned int an)
{
    parc[poz].cod = cod;
    parc[poz].locuri = locuri;
    parc[poz].CP = CP;
    parc[poz].an = an - 1800;
    parc[poz].marca = malloc((strlen(marca) + 1) * sizeof(char));
    parc[poz].culoare = malloc((strlen(culoare) + 1) * sizeof(char));
    if (!parc[poz].marca || !parc[poz].culoare)
    {
        eliberareMemorie();
        perror("Nu s a putut face alocarea");
        exit(EXIT_FAILURE);
    }
    strcpy(parc[poz].marca, marca);
    strcpy(parc[poz].culoare, culoare);
}

void introducereMasina(unsigned int cod, unsigned int locuri, unsigned int CP, char *marca, char *culoare, unsigned int an)
{
    if (lenPark == 0)
    {
        lenPark = CHUNK;
        parc = malloc(lenPark * sizeof(masina));
        if (!parc)
        {
            eliberareMemorie();
            perror("Nu s a putut face realocarea parcului");
            exit(EXIT_FAILURE);
        }
    }
    if (currentLen >= lenPark)
    {
        lenPark += CHUNK;
        masina *aux = realloc(parc, lenPark * sizeof(masina));
        if (!aux)
        {
            eliberareMemorie();
            perror("Nu s a putut face realocarea parcului");
            exit(EXIT_FAILURE);
        }
        parc = aux;
    }

    //! Copierea lui x in vector nu se poate face deoarece marca si culoare sunt alocate dinamic
    // parc[currentLen] = x;

    //*Varianta corecta:
    copiereMasina(parc, currentLen, cod, locuri, CP, marca, culoare, an);

    currentLen++;
}
int stergereMasina(unsigned int cod) // returneaza 1 daca sterge o masina si 0 daca nu
{
    for (int i = 0; i < currentLen; i++)
    {
        if (parc[i].cod == cod)
        {
            for (int j = i; j < currentLen - 1; j++)
            {
                free(parc[j].marca);
                free(parc[j].culoare);
                copiereMasina(parc, j, parc[j + 1].cod, parc[j + 1].locuri, parc[j + 1].CP, parc[j + 1].marca, parc[j + 1].culoare, parc[j + 1].an + 1800);
            }
            free(parc[currentLen - 1].marca);
            free(parc[currentLen - 1].culoare);
            currentLen--;
            return 1;
        }
    }
    return 0;
}

void afisareParc()
{
    //*Facem realocarea pentru spatiul minim de fiecare data cand afisam masinile din parc
    masina *aux = realloc(parc, currentLen * sizeof(masina));
    if (!aux)
    {
        perror("Nu s a putut face alocarea");
        exit(EXIT_FAILURE);
    }
    parc = aux;
    for (int i = 0; i < currentLen; i++)
    {
        printf("Cod: %5d; Locuri: %1d; Putere: %3d; marca: %15s; culoare: %15s; an: %d\n", parc[i].cod, parc[i].locuri, parc[i].CP, parc[i].marca, parc[i].culoare, parc[i].an + 1800);
    }
}

void afisareLocuri(unsigned int locuri)
{
    int ok = 0;
    for (int i = 0; i < currentLen; i++)
    {
        if (parc[i].locuri == locuri)
        {
            printf("Cod: %5d; Locuri: %1d; Putere: %3d; marca: %15s; culoare: %15s; an: %d\n", parc[i].cod, parc[i].locuri, parc[i].CP, parc[i].marca, parc[i].culoare, parc[i].an + 1800);
            ok = 1;
        }
    }
    if (!ok)
        printf("Nu s au gasit masini cu %d locuri!\n", locuri);
}
int comparare(const void *a, const void *b) //de la cea mai noua masina la cea mai veche
{
    masina *x = (masina *)a;
    masina *y = (masina *)b;
    if (x->an < y->an)
        return 1;
    if (x->an > y->an)
        return -1;
    return 0;
}
void ordonareAn()
{
    qsort(parc, currentLen, sizeof(masina), comparare);
}
int main()
{
    introducereMasina(1234, 2, 230, "Ferrari", "rosu", 2004);
    introducereMasina(2001, 4, 100, "Audi", "albastru", 2000);
    introducereMasina(1245, 4, 200, "Ford", "gri", 2001);
    introducereMasina(3220, 2, 123, "BMW", "roz", 1999);
    afisareParc();
    printf("\n");
    if (!stergereMasina(1234))
        printf("Nu s a sters nicio masina");
    afisareParc();
    printf("\n");
    afisareLocuri(4);
    printf("\n");
    ordonareAn();
    afisareParc();
}