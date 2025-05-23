#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 200

Revista_Carte bibl[MAX_LEN]; // o biblioteca cu maxim 200 de carti/reviste
int currentPos = 0;          // prima pozitie libera
typedef union
{
    char ISBN[13];        // carte
    unsigned int an : 11; // revista
} Rev_Carte;
typedef struct
{
    char titlu[20];
    char autor[40];
    int nr; //nr de exemplare
    unsigned int pret : 9, pagini : 10;
    int greutate : 13;        // in grame
    unsigned int isCarte : 1; // 1-carte 0-revista
    Rev_Carte x;
} Revista_Carte;

void adaugare(char *titlu, char *autor, int nr, unsigned int pret, unsigned int pagini, int greutate, unsigned int isCarte, Rev_Carte x)
{
    if (currentPos == MAX_LEN)
        printf("Nu mai este loc in biblioteca!");
    else
    {
        Revista_Carte aux;
        strcpy(aux.titlu, titlu);
        strcpy(aux.autor, autor);
        aux.nr = nr;
        aux.pret = pret;
        aux.pagini = pagini;
        aux.greutate = greutate;
        aux.isCarte = isCarte;
        if (aux.isCarte)
            strcpy(aux.x.ISBN, x.ISBN);
        else
            aux.x.an = x.an;
        bibl[currentPos]=aux;
        currentPos++;
    }
}

void afisareCarti100(){
    for(int i=0; i<currentPos; i++){
        if(bibl[i].isCarte && bibl[i].pret>100)
            printf("Titlu: %20s; Autor: %20s; Nr de exemplare: %d\n", bibl[i].titlu, bibl[i].autor, bibl[i].nr);
    }
}

void afisareALL(){
    for(int i=0; i<currentPos; i++){
        if(bibl[i].isCarte)
            printf("Titlu: %20s; Autor: %20s; Nr de exemplare: %d; Pret: %d; Pagini: %d; Greutate: %d, ISBN: %s\n", bibl[i].titlu, bibl[i].autor, bibl[i].nr, bibl[i].pret, bibl[i].pagini, bibl[i].greutate, bibl[i].ISBN);
        else
            printf("Titlu: %20s; Autor: %20s; Nr de exemplare: %d; Pret: %d; Pagini: %d; Greutate: %d, an: %d\n", bibl[i].titlu, bibl[i].autor, bibl[i].nr, bibl[i].pret, bibl[i].pagini, bibl[i].greutate, bibl[i].an);
    }
}
int main()
{

}