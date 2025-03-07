/*Aplicația 2.1: Se cere un număr n și apoi un vector de n rezultate ale studenților la un examen. Fiecare rezultat
este definit prin (nume,nota). Se cere să se sorteze folosind qsort vectorul în ordinea notelor, notele cele mai mari
fiind primele. Dacă două note sunt identice, rezultatele respective se vor sorta în ordinea alfabetică a numelor.*/
#include <stdio.h>
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
}