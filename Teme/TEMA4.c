#include <stdio.h>

/*Să se codifice cu ajutorul structurilor cu câmpuri pe biți informațiile despre un fișier: nume (șir de
maxim 15 caractere), dimensiunea acestuia (int - număr de octeți, maxim 1024 octeți), tipul acestuia (.txt - 0, .doc
- 1, .xls – 2), tipul fisierului (normal – 0, read-only – 1). Să se citească informația despre un fișier, și să se afișeze
pe ecran.*/

typedef struct
{
    char nume[16];
    int len : 4;
    int format : 2;
    int type : 1;
} fisier;

int main(void)
{
}
