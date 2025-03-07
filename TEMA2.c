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
}
