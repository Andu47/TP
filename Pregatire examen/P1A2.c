/*1.⁠ ⁠Sa se implementeze o functie în C care primeste un numar natural n, construieste si afiseaza o listă dublu înlănțuită formată din primele 2𝑛 numere naturale, dispuse astfel:
se pleacă de la lista 1 2
exact la mijlocul acestei liste se inserează elementele 3 4 și se obține 1 3 4 2
exact la mijlocul acestei liste se inserează elementele 5 6 7 8 și se obține 1 3 5 6 7 8 4 2
în general, la mijlocul șirului format din primele 2𝑘 numere naturale se inserează șirul ordonat format din următoarele 2𝑘 numere naturale.
Se va implemente o functie main() adecvata si orice alte functii necesare. Să se afișeze toate listele intermediare obținute*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nod
{
    int nr;
    struct Nod *pred;
    struct Nod *urm;
} Nod;

typedef struct Lista
{
    struct Nod *prim;
    struct Nod *ultim;
} Lista;

Lista *lista = NULL;
Lista *listaIntrodusa = NULL;

Lista *init_Lista(Lista *lista)
{
    lista = malloc(sizeof(Lista));
    if (!lista)
        exit(EXIT_FAILURE);
    lista->prim = NULL;
    lista->ultim = NULL;
    return lista;
}

Nod *creare_elem(int info)
{
    Nod *elem = malloc(sizeof(Nod));
    if (!elem)
        exit(EXIT_FAILURE);
    elem->pred = NULL;
    elem->urm = NULL;
    elem->nr = info;
    return elem;
}

void adaugare_Final(Lista *lista, Nod *elem)
{
    if (lista->prim == NULL)
    {
        lista->prim = elem;
    }
    else
    {
        lista->ultim->urm = elem;
        elem->pred = lista->ultim;
    }
    lista->ultim = elem;
    elem->urm = NULL;
}

void adaugare_Interior(Lista *listaFinala, Lista *listaIntrodusa, int pozitie)
{
    if (pozitie == 1)
    {
        listaFinala->ultim->pred = listaIntrodusa->ultim;
        listaIntrodusa->ultim->urm = listaFinala->ultim;

        listaFinala->prim->urm = listaIntrodusa->prim;
        listaIntrodusa->prim->pred = listaFinala->prim;
    }
    else
    {
        //! Pentru a gasi pozitia pe care vrem sa introducem lista
        Nod *lFstanga = listaFinala->prim;
        for (int i = 1; i < pozitie; i++)
        {
            lFstanga = lFstanga->urm;
        }
        Nod *lFdreapta = lFstanga->urm;
        // Ne-am ales elementele conform:
        // 1 2 3 ... lFstanga listaIntrodusa->prim ... listaIntrodusa->utlim lFdreapta ... 7 8 9

        //! Urmeaza sa schimbam legaturile dintre elemente (doar elemente de mijloc)
        lFstanga->urm = listaIntrodusa->prim;
        listaIntrodusa->prim->pred = lFstanga;

        listaIntrodusa->ultim->urm = lFdreapta;
        lFdreapta->pred = listaIntrodusa->ultim;

        //! listaFinala este lista completa
        return;
    }
}

void afisare(Lista *lista)
{
    Nod *elem = lista->prim;
    while (elem)
    {
        printf("%d ", elem->nr);
        elem = elem->urm;
    }
    printf("\n");
}

int power(int x, int pow)
{
    int aux = 1;
    while (pow != 0)
    {
        aux *= x;
        pow--;
    }
    return aux;
}

void problema(unsigned int n)
{
    int nr = 3;                // tinem minte ce numar trebuie afisat
    lista = init_Lista(lista); // declarata global
    Nod *elem1 = creare_elem(1);
    Nod *elem2 = creare_elem(2);
    adaugare_Final(lista, elem1);
    adaugare_Final(lista, elem2);

    int biggestPower = 0; // va memora cati pasi putem face
    int x = 2;
    while (x < n)
    {
        biggestPower++;
        x *= 2;
    }
    biggestPower++;

    for (int aux = 2; aux <= biggestPower; aux++)
    {
        // creez listaIntrodusa
        listaIntrodusa = init_Lista(listaIntrodusa);
        for (; nr <= power(2, aux) && nr <= 2 * n; nr++)
        {
            Nod *elem;
            elem = creare_elem(nr);
            adaugare_Final(listaIntrodusa, elem);
        }
        // adaug la mijloc:
        adaugare_Interior(lista, listaIntrodusa, power(2, aux - 1));
    }
    afisare(lista);
}
int main()
{
    problema(4);
}