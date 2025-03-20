/*Aplicația 2.1: Se cere un număr n și apoi un vector de n rezultate ale studenților la un examen. Fiecare rezultat
este definit prin (nume,nota). Se cere să se sorteze folosind qsort vectorul în ordinea notelor, notele cele mai mari
fiind primele. Dacă două note sunt identice, rezultatele respective se vor sorta în ordinea alfabetică a numelor.*/
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nume[50];
    float nota;
} student;

int sortareNote(const void *a, const void *b)
{
    const student *st1= (const student *)a;
    const student *st2= (const student *)b;
    if (st1->nota > st2->nota)
        return -1;
    if (st1->nota < st2->nota)
        return 1;
    else
    {
        if (strcmp(st1->nume, st2->nume) > 0)
        {
            return -1;
        }
        if (strcmp(st1->nume, st2->nume) < 0)
        {
            return 1;
        }
        else
            return 0;
    }
}
int main()
{
    int n;
    printf("Introduceti numarul de studenti: ");
    scanf("%d", &n);
    getchar();
    student *v;
    v = (student *)malloc(n * sizeof(student));
    printf("Introduceti datele studentilor (de tipul:NUME NOTA)\n");
    for (int i = 0; i < n; i++)
    {
        char aux[60];
        fgets(aux, 60, stdin);
        strtok(aux, " ");
        strcpy(v[i].nume, aux);
        v[i].nota = strtof(aux + strlen(aux) + 1, NULL);
        v[i].nume[strcspn(v[i].nume, "\n")] = '\0';
    }
    qsort(v, n, sizeof(student), sortareNote);
    for (int i = 0; i < n; i++)
    {
        printf("%f %s\n", v[i].nota, v[i].nume);
    }
}*/

/*Aplicația 2.2: Să se implementeze o funcție care primește ca parametri un vector de întregi, numărul elementelor
din vector transmis prin adresă și un predicat care testează dacă un întreg îndeplinește o anumită condiție. Funcția
va sterge din vector toate elementele care nu îndeplinesc condiția dată și va actualiza numărul elementelor cu
numărul de elemente rămas în vector. Să se testeze funcția cu un predicat care testează dacă un număr este
negativ și să se afișeze vectorul rezultat.*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void elimElem(int *v, int size, int pozitie)
{
    for (int i = pozitie; i < size; i++)
    {
        v[i] = v[i + 1];
    }
}
void Functie(int *v, int *size, int (*conditie)(int))
{
    for (int i = 0; i < *size; i++)
    {
        if (conditie(v[i]) == 0)
        {
            elimElem(v, *size, i);
            (*size)--;
            i--;
        }
    }
}
int negativ(int x)
{
    if (x < 0)
        return 1;
    else
        return 0;
}
void afisare(int *v,int size)
{
    for(int i=0;i<size;i++)
    printf("%d ", v[i]);
}
int main()
{
    int len, *v;
    scanf("%d", &len);
    if((v=malloc(len*sizeof(int)))==NULL){
        perror("Nu s a putut aloca memoria");
    }
    for(int i=0; i<len; i++){
        scanf("%d", &v[i]);
    }
    Functie(v, &len, negativ);
    afisare(v, len);
}*/

/*Aplicația 2.3: Se introduce un număr întreg n<10 și apoi n numere de tip float. Să se folosească funcția qsort
pentru a sorta aceste numere în mod crescător. Se va introduce apoi un număr x de tip float. Folosind funcția
bsearch, să se determine dacă x există în vectorul sortat. Se pot consulta paginile de manual pentru funcțiile qsort
și bsearch.*/

/*#include <stdio.h>
#include <stdlib.h>
#define LEN_MAX 10

int crescator(const void *a, const void *b)
{
    const float *nr1 = (const float *)a;
    const float *nr2 = (const float *)b;
    if (*nr1>*nr2)
        return 1;
    if(*nr1<*nr2)
        return -1;
    return 0;
}
int comparare(const void *a, const void *b){
    float *x=(float *)a;
    float *y=(float *)b;
    return (*x)-(*y);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    if (n >= LEN_MAX)
    {
        printf("n e prea mare");
        return 1;
    }

    float v[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &v[i]);

    qsort(v, n, sizeof(float), crescator);

    printf("Introduceti un numar de tip float:\n");
    float x;
    scanf("%f", &x);

    if(bsearch(&x, v, n, sizeof(float), comparare)!=NULL){
        printf("%.2f exista in sir\n", x);
    }
    else{
        printf("%.2f nu exista in sir\n", x);
    }
    for (int i = 0; i < n; i++)
        printf("%.2f ", v[i]);

}*/

/*Aplicația 2.4: Să se implementeze o funcție care tabelează o funcție matematică de un parametru, primită ca
argument. Funcția tabelată primește un parametru de tip double și returnează o valoare tot de tip double. Funcția
de tabelare va primi ca parametri: a și b - capetele de tip double ale intervalului închis de tabelat, n - un număr
întreg care arată în câte segmente egale se împarte intervalul [a,b], incluzând capetele acestuia și f - funcția de
tabelat. Să se testeze funcția de tabelare cu valori a,b și n citite de la tastatură, tabelând funcțiile cos, sqrt și fabs
din math.h*/

#include <stdio.h>
#include <math.h>
#include <stdint.h>

double cosinus(double x)
{
    return cos(x);
}
double radical(double x)
{
    return sqrt(x);
}
double modul(double x)
{
    return fabs(x);
}
void tabelare(double a, double b, int n, double (*f)(double))
{
    double step = (b - a) / n;
    for (double i = a; i <= b; i += step)
    {
        double g = f(i);
        printf("f(%.2lf)=%.2lf ", i, g);
    }
    printf("\n");
}
int main(void)
{
    double a = 0.0, b = 0.0;
    int n = 0;
    scanf("%lf %lf %d", &a, &b, &n);

    tabelare(a, b, n, cosinus);
    tabelare(a, b, n, radical);
    tabelare(a, b, n, modul);
}


