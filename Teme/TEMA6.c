/*Aplicația 6.2: Să se scrie o funcție float *allocVec(int n,...) care primește pe prima poziție un număr de elemente
iar apoi n elemente reale. Funcția va aloca dinamic un vector de tip float în care va depune toate elementele.
Exemplu: allocVec(3,7.2,-1,0) => {7.2, -1, 0}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*float *allocVec(int n, ...)
{
    float *v;
    v = malloc(n * sizeof(float));
    va_list va;
    va_start(va, n);
    for (int i = 0; i < n; i++)
    {
        v[i] = (float)va_arg(va, double);
    }
    va_end(va);
    return v;
}
int main()
{
    float *x;
    x = allocVec(5, 1.2, 2.0, 3.4, 4.0, 5.0);
    for (int i = 0; i < 5; i++)
    {
        printf("%g ", x[i]);
    }
}*/

/*Aplicația 6.3: Să se scrie o funcție absN(int n,...) care primește un număr n de adrese de tip float și setează la
fiecare dintre aceste adrese valoarea absolută de la acea locație.
Exemplu: absN(2,&x,&y); // echivalent cu x=fabs(x); y=fabs(y);*/
/*void absN(int n,...){
    va_list va;
    va_start(va,n);
    for(int i=0;i<n;i++){
        float *nr=va_arg(va, float *);
        if(*nr<0){
            *nr=-(*nr);
        }
    }
    va_end(va);
}
int main(){
    float x=-10, y=-4;
    absN(2, &x, &y);
    printf("%g %g", x, y);
}*/

/*Aplicația 6.4: Să se scrie o funcție crescator(int n,char tip,...) care primește un număr n de valori și returnează 1
dacă ele sunt în ordine strict crescătoare, altfel 0. Caracterul tip indică tipul valorilor și poate fi ‘d’ - int, ‘f’ - double.
Exemplu: printf(“%d”,crescator(3,’d’,-1,7,9));*/

/*int crescator(int n, char tip, ...)
{
    va_list va;

    // Soluție: copie locală a lui `tip` într-un int
    int safe_tip = tip;

    va_start(va, safe_tip);  // Acum folosim un int în va_start
    int i, result = 1;

    switch (tip)
    {
    case 'd': {
        int prev = va_arg(va, int);
        for (i = 1; i < n; ++i) {
            int curr = va_arg(va, int);
            if (curr <= prev) {
                result = 0;
                break;
            }
            prev = curr;
        }
        break;
    }
    case 'f': {
        double prev = va_arg(va, double);
        for (i = 1; i < n; ++i) {
            double curr = va_arg(va, double);
            if (curr <= prev) {
                result = 0;
                break;
            }
            prev = curr;
        }
        break;
    }
    default:
        result = 0;
    }

    va_end(va);
    return result;
}
int main(){
    printf("%d", crescator(5, 'f', 1.2, 2.3, 3.4, 5.6, 5.8));
}*/

/*Aplicația 6.10: Să se scrie un program denumit criptare, care criptează/decriptează un text primit în linia de
comandă. Programul va fi apelat în felul următor: ./criptare operatie cheie cuvant1 cuvant2 ...
Operația poate fi enc pentru criptare sau dec decriptare. Cheia este un număr întreg. Algoritmul de criptare este
următorul: pentru fiecare literă din cuvinte se consideră codul său ASCII, la care se adună cheia specificată,
rezultând un nou cod ASCII, cel al literei criptate. Adunarea este circulară, adică ‘z’ incrementat cu 1 devine ‘a’.
Decriptarea este inversă: din cuvintele criptate se scade circular cheia specificată. Literele mari se transformă la
început în litere mici.
Exemple:
./criptare enc 1 zaraza -> absbab
./criptare dec 1 bcfdfebs -> abecedar
./criptare enc 10 vine VINE primavara PRImaVAra -> fsxo fsxo zbswkfkbk zbswkfkbk*/

char cript_litera(char c, int cheie, int enc)
{
    if (!isalpha(c))
        return c;

    c = tolower(c);
    int offset = c - 'a';

    if (enc)
        offset = (offset + cheie) % 26;
    else
        offset = (offset - cheie + 26) % 26;

    return 'a' + offset;
}

void proceseaza(char *cuvant, int cheie, int enc)
{
    for (int i = 0; cuvant[i]; i++)
    {
        printf("%c", cript_litera(cuvant[i], cheie, enc));
    }
    printf(" ");
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Utilizare: %s enc|dec cheie cuvant1 [cuvant2 ...]\n", argv[0]);
        return 1;
    }

    int enc;
    if (strcmp(argv[1], "enc") == 0)
        enc = 1;
    else if (strcmp(argv[1], "dec") == 0)
        enc = 0;
    else
    {
        printf("Operatie necunoscuta: %s\n", argv[1]);
        return 1;
    }

    int cheie = atoi(argv[2]) % 26;

    for (int i = 3; i < argc; i++)
    {
        proceseaza(argv[i], cheie, enc);
    }

    printf("\n");
    return 0;
}
