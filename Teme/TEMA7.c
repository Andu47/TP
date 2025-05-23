#include <stdio.h>


/*Aplicația 7.6: Să se scrie o funcție care primește ca parametri o listă (posibil vidă) de elemente sortate și un
element. Funcția va insera în listă noul element, astfel încât lista să rămână sortată. Folosind aceasta funcție, să
se scrie o funcție de sortare a unei liste, care primește ca parametru o listă nesortată și returnează una sortată.
Programul nu va folosi niciun vector.*/

typedef struct{
    int info;
    Nod* urm;
}Nod;

void inserareSortata(Nod **lista, Nod elem){
    //Creem un nod nou pentru elem
    Nod *nou=(Nod*)malloc(sizeof(Nod));
    *nou=elem;
    nou->urm=NULL;

    Nod *current=*lista;
    while(current!=NULL || current->urm->info > nou->info){
        current=current->urm;
    }
    nou->urm=current->urm;
    current->urm=nou;
}
int main(){

}