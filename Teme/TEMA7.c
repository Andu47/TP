#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*Aplicația 7.6: Să se scrie o funcție care primește ca parametri o listă (posibil vidă) de elemente sortate și un
element. Funcția va insera în listă noul element, astfel încât lista să rămână sortată. Folosind aceasta funcție, să
se scrie o funcție de sortare a unei liste, care primește ca parametru o listă nesortată și returnează una sortată.
Programul nu va folosi niciun vector.*/

/*typedef struct nod {
    int val;
    struct nod *urm;
} Nod;

Nod* inserare_sortata(Nod *cap, int val) {
    Nod *nou = malloc(sizeof(Nod));
    nou->val = val;
    nou->urm = NULL;

    if (!cap || val < cap->val) {
        nou->urm = cap;
        return nou;
    }

    Nod *p = cap;
    while (p->urm && p->urm->val < val)
        p = p->urm;

    nou->urm = p->urm;
    p->urm = nou;

    return cap;
}

Nod* sortare_lista(Nod *lista) {
    Nod *sortata = NULL;
    Nod *p = lista;
    while (p) {
        sortata = inserare_sortata(sortata, p->val);
        p = p->urm;
    }
    return sortata;
}

void afisare(Nod *cap) {
    while (cap) {
        printf("%d ", cap->val);
        cap = cap->urm;
    }
    printf("\n");
}

void eliberare(Nod *cap) {
    while (cap) {
        Nod *tmp = cap;
        cap = cap->urm;
        free(tmp);
    }
}

int main() {
    Nod *lista = NULL;

    // adăugare manuală elemente (neordonate)
    int valori[] = {5, 1, 4, 3, 2};
    for (int i = 0; i < 5; i++) {
        Nod *nou = malloc(sizeof(Nod));
        nou->val = valori[i];
        nou->urm = lista;
        lista = nou;
    }

    printf("Lista initiala:\n");
    afisare(lista);

    Nod *ordonata = sortare_lista(lista);

    printf("Lista sortata:\n");
    afisare(ordonata);

    eliberare(lista);
    eliberare(ordonata);
    return 0;
}*/

/*Aplicația 7.7: Pentru implementarea listei care memorează ultimul element, să se scrie o funcție care primește
două liste sortate și returnează lista sortată care conține toate elementele lor. Pentru lista rezultată se va folosi
doar operația de adăugare la sfârșit de listă.
Exemplu: {1, 2, 7, 8} și {2, 9} -> {1, 2, 2, 7, 8, 9}*/
typedef struct nod
{
    int val;
    struct nod *urm;
} Nod;

typedef struct
{
    Nod *prim;
    Nod *ultim;
} Lista;

void adauga_sfarsit(Lista *l, int val)
{
    Nod *nou = malloc(sizeof(Nod));
    nou->val = val;
    nou->urm = NULL;

    if (!l->prim)
    {
        l->prim = l->ultim = nou;
    }
    else
    {
        l->ultim->urm = nou;
        l->ultim = nou;
    }
}

Lista interclaseaza(Lista a, Lista b)
{
    Lista rezultat = {NULL, NULL};
    Nod *pa = a.prim, *pb = b.prim;

    while (pa && pb)
    {
        if (pa->val <= pb->val)
        {
            adauga_sfarsit(&rezultat, pa->val);
            pa = pa->urm;
        }
        else
        {
            adauga_sfarsit(&rezultat, pb->val);
            pb = pb->urm;
        }
    }

    while (pa)
    {
        adauga_sfarsit(&rezultat, pa->val);
        pa = pa->urm;
    }

    while (pb)
    {
        adauga_sfarsit(&rezultat, pb->val);
        pb = pb->urm;
    }

    return rezultat;
}

void afisare(Lista l)
{
    Nod *p = l.prim;
    while (p)
    {
        printf("%d ", p->val);
        p = p->urm;
    }
    printf("\n");
}

void eliberare(Lista *l)
{
    Nod *p = l->prim;
    while (p)
    {
        Nod *tmp = p;
        p = p->urm;
        free(tmp);
    }
    l->prim = l->ultim = NULL;
}

void construieste(Lista *l, int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        adauga_sfarsit(l, v[i]);
    }
}

int main()
{
    Lista a = {NULL, NULL}, b = {NULL, NULL};

    int va[] = {1, 2, 7, 8}, vb[] = {2, 9};
    construieste(&a, va, 4);
    construieste(&b, vb, 2);

    printf("Lista A: ");
    afisare(a);
    printf("Lista B: ");
    afisare(b);

    Lista rezultat = interclaseaza(a, b);

    printf("Lista interclasata: ");
    afisare(rezultat);

    eliberare(&a);
    eliberare(&b);
    eliberare(&rezultat);

    return 0;
}
