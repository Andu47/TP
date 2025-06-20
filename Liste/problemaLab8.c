#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cuvant
{
    char text[16];
    struct Cuvant *pred;
    struct Cuvant *urm;
} Cuvant;

Cuvant *Cuvant_nou(const char *text)
{
    Cuvant *c = (Cuvant *)malloc(sizeof(Cuvant));
    if (!c)
    {
        printf("NU");
        exit(EXIT_FAILURE);
    }
    strcpy(c->text, text);
    return c;
}

typedef struct Propozitie
{
    Cuvant *prim;
    Cuvant *ultim;
} Propozitie;

void init_Propozitie(Propozitie *p)
{
    p->prim = NULL;
    p->ultim = NULL;
}

void adaugaIn_Propozitie(Propozitie *p, Cuvant *c)
{
    if (p->prim == NULL)
    {
        c->pred = NULL;
        c->urm = NULL;
        p->prim = c;
        p->ultim = c;
    }
    else
    {
        c->pred = p->ultim;
        c->urm = NULL;
        p->ultim = c;
    }
}

Cuvant *cautaIn_Propozitie(Propozitie *p, const char *text)
{
    Cuvant *c;
    c = p->prim;
    while (c)
    {
        if (strcmp(c->text, text) == 0)
            return c;
        c = c->urm;
    }
    return NULL;
}

// stergem un cuvant care stim ca este in propozitie
void stergeIn_Propozitie(Propozitie *p, Cuvant *c)
{
    //prim -> A <-> B <-> C <-ultim
    //!Vom avea 4 cauzri: stergem PRIMUL, ULTIMUL, MIJLOC, SINGURUL
    //pentru a sterge B (MIJLOC): 
    if(c->pred && c->urm){
        c->pred->urm=c->urm;
        c->urm->pred=c->pred;
        free(c);
        return;
    }
    //pentru a sterge A (PRIMUL):
    if(!c->pred && c->urm){
        p->prim=c->urm;
        c->urm->pred=NULL;
        free(c);
        return;
    }
    //pentru a sterge C (ULTIMUL):
    if(c->pred && !c->urm){
        p->ultim=c->pred;
        c->pred->urm=NULL;
        free(c);
        return;
    }
    //pentru a sterge (SINGURUL):
    p->prim=NULL;
    p->ultim=NULL;
    free(c);
}



int main()
{
}