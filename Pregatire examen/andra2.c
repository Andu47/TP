/*intoarcerea unei liste simplu dubla*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nod
{
    int info;
    struct Nod *pred;
    struct Nod *urm;
} Nod;

typedef struct Lista
{
    Nod *prim;
    Nod *ultim;
} Lista;

Lista *lista;

Lista *init_Lista(Lista *lista)
{
    lista->prim = NULL;
    lista->ultim = NULL;
    return lista;
}

Nod *creare_element(int x)
{
    Nod *elem = malloc(sizeof(Nod));
    if (!elem)
        return 0;
    elem->info = x;
    elem->pred = NULL;
    elem->urm = NULL;
    return elem;
}

Lista *adaugare_Final(Lista *lista, int x)
{
    Nod *elem = creare_element(x);
    if (lista->prim == NULL)
        lista->prim = elem;
    else
    {
        lista->ultim->urm = elem;
        elem->pred = lista->ultim;
    }
    lista->ultim = elem;
    return lista;
}

void afisare_Lista(Lista *lista)
{
    Nod *aux = lista->prim;
    while (aux)
    {
        printf("%d ", aux->info);
        aux = aux->urm;
    }
    printf("\n");
}


int main()
{
    lista = malloc(sizeof(Lista));
    lista = init_Lista(lista);
    lista = adaugare_Final(lista, 1);
    lista = adaugare_Final(lista, 2);
    lista = adaugare_Final(lista, 3);
    lista = adaugare_Final(lista, 4);
    afisare_Lista(lista);

    
}