#include <stdio.h>
#include <stdlib.h>

/*Aplicația 5.5: Să se scrie un program similar cu hexdump, care primește un nume de fișier în linia de comandă, citește câte 16 octeți din el și îi afișează pe câte o linie. Fiecare linie începe cu offsetul
 ei în fișier, afișat în hexazecimal pe 8 cifre cu 0 în față, după care valorile hexa ale celor 16 octeți pe câte 2 cifre și în final caracterele.
 Dacă codul unui caracter este în intervalul 32-255 se va afișa ca atare, altfel se va afișa un punct în locul său. Dacă ultima linie este incompletă, se va completa cu octeți de 0.
*/
/*
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Utilizare: %s <fisier>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "rb");
    if (!f) {
        perror("Eroare la deschiderea fisierului");
        return 1;
    }

    unsigned char buffer[16];
    unsigned int offset = 0;
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, 16, f)) > 0) {
        printf("%08X  ", offset);

        for (size_t i = 0; i < 16; i++) {
            if (i < bytes_read)
                printf("%02X ", buffer[i]);
            else
                printf("00 ");
        }

        printf(" ");

        for (size_t i = 0; i < 16; i++) {
            unsigned char c = (i < bytes_read) ? buffer[i] : 0;
            if (c >= 32 && c <= 255)
                printf("%c", c);
            else
                printf(".");
        }

        printf("\n");
        offset += 16;
    }

    fclose(f);
    return 0;
}*/


/*Aplicația 5.6: Să se scrie un program care primește 2 fișiere în linia de comandă și le compară între ele. Pentru fiecare octet diferit găsit, se afișează offsetul acestuia și valorile sale din fiecare fișier, în hexazecimal, pe câte 2 cifre. Dacă fișierele sunt de dimensiuni diferite, în final se vor afișa toți octeții din fișierul mai mare. Dacă fișierele sunt identice, programul nu va afișa nimic.
*/
/*
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Utilizare: %s <fisier1> <fisier2>\n", argv[0]);
        return 1;
    }

    FILE *f1 = fopen(argv[1], "rb");
    FILE *f2 = fopen(argv[2], "rb");

    if (!f1 || !f2) {
        perror("Eroare la deschiderea fisierelor");
        return 1;
    }

    int b1, b2;
    unsigned int offset = 0;
    int diferit = 0;

    while (1) {
        b1 = fgetc(f1);
        b2 = fgetc(f2);

        if (b1 == EOF && b2 == EOF)
            break;

        if (b1 != b2) {
            diferit = 1;
            printf("%08X: %02X %02X\n", offset,
                   b1 == EOF ? 0x00 : b1,
                   b2 == EOF ? 0x00 : b2);
        }

        offset++;
    }

    fclose(f1);
    fclose(f2);
    return 0;
}
*/