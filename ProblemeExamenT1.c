/*Se citesc de la tastatură un număr n și o matrice pătratică de dimensiune n conținând litere din alfabet.
Pe urmă se citește de la tastatură un cuvânt. Verificați dacă respectivul cuvânt se poate construi parcurgând
literele matricii pe verticală în sus sau în jos sau pe orizontală spre stânga sau spre dreapta. Afișați toate
 pozițiile de unde trebuie începută parcurgerea, precum și sensul de parcurgere necesar pentru a construi
 cuvântul.*/

// vom citi din fisier pentru a fi mai simplu de verificat

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define LEN_MAX 100

int mallocMatrix(char ***v, int n)
{
    if ((*v = (char **)malloc(n * sizeof(char *))) == NULL)
    {
        free(*v);
        perror("Nu s-a putut aloca spatiu pentru matrice");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (((*v)[i] = (char *)malloc(n * sizeof(char))) == NULL)
        {
            for (i--; i >= 0; i--)
                free((*v)[i]);
            free(*v);
            perror("memorie insuficienta\n");
            return 0;
        }
    }
    return 1;
}

void readMatrix(char ***v, int size, FILE *in)
{
    fgetc(in);
    fgetc(in);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            (*v)[i][j] = fgetc(in);
            fgetc(in);
        }
    }
    fgetc(in);
}

void showMatrix(char ***v, int size, FILE *in)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%c ", (*v)[i][j]);
        }
        printf("\n");
    }
}

int isWordOriz(char ***v, int lenWord, char *word, int currPosX, int currPosY)
{
    for (int i = 0; i < lenWord; i++)
    {
        if (word[i] != (*v)[currPosX][currPosY + i])
            return 0;
    }
    return 1;
}

int isWordVert(char ***v, int lenWord, char *word, int currPosX, int currPosY)
{
    for (int i = 0; i < lenWord; i++)
    {
        if (word[i] != (*v)[currPosX + i][currPosY])
            return 0;
    }
    return 1;
}
void Find(char ***v, int size, int lenWord, char *word, char *revWord)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= size - lenWord; j++)
        {
            if (isWordOriz(v, lenWord, word, i, j))
            {
                printf("Orizontala, spre dreapta, pozitia (%d, %d)\n", i, j);
            }
            if (isWordOriz(v, lenWord, revWord, i, j))
            {
                printf("Orizontala, spre stanga, pozitia (%d, %d)\n", i, j + lenWord-1);
            }
        }
    }
    for (int i = 0; i <= size - lenWord; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (isWordVert(v, lenWord, word, i, j))
            {
                printf("Verticala, in jos, pozitia (%d, %d)\n", i, j);
            }
            if (isWordVert(v, lenWord, revWord, i , j))
            {
                printf("Verticala, in sus, pozitia (%d, %d)\n", i+ lenWord-1, j);
            }
        }
    }
}

int main(int argc, char **argv)
{
    //! FISIERE
    if (argc != 3)
    {
        perror("Nu ati introdus fisierele corespunzatoare: ./executabil fisier_intrare fisier_iesire");
        exit(EXIT_FAILURE);
    }
    FILE *in, *out;
    if ((in = fopen(argv[1], "r")) == NULL)
        perror("Nu s a putut deschide fisierul de intrare");
    if ((out = fopen(argv[2], "w")) == NULL)
        perror("Nu s a putut deschide fisierul de iesire");

    //! MATRICE
    int n;
    fscanf(in, "%d", &n);
    char **v = NULL;
    if (!mallocMatrix(&v, n))
    {
        exit(EXIT_FAILURE);
    }
    readMatrix(&v, n, in);

    //! CUVANTUL SI INVERSUL LUI (MERE, EREM)
    char word[LEN_MAX];
    fgets(word, LEN_MAX, in);
    word[strcspn(word, "\n")] = '\0';
    char revWord[LEN_MAX];
    int lenWord = strlen(word);
    for (int i = lenWord - 1; i >= 0; i--)
    {
        revWord[lenWord - i - 1] = word[i];
    }
    revWord[lenWord] = '\0';

    Find(&v, n, lenWord, word, revWord);

    return 0;
}