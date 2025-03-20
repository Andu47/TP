/*Aplicația 8.3: Se citește de la tastatură un număr n<=10 și un număr m<=20. Se cere să se scrie un program care
generează o matrice cu m linii și n coloane în care sunt puse toate numerele de la 1,2,3,...,m*n. Se vor utiliza
pointeri.*/

/*#include <stdlib.h>
#include <stdio.h>
#define MAX_N 10
#define MAX_M 20
int main()
{
    int n, m;
    printf("Introduceti n<=10 si m<=20");
    scanf("%d %d", &n, &m);
    if(n>MAX_N || m>MAX_M || n<0 || m<0){
        printf("Variabilele introduse nu sunt corespunzatoare!");
        return 0;
    }
    int a[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            *(*(a+i*n)+j)=i*n+j;
            printf("%d", *(*(a+i*n)+j));
        }
        printf("\n");
    }
    return 0;
}*/

/*Aplicația 8.4: Se citește de la tastatură o matrice pătratică cu n<=50 linii și coloane. Să se interschimbe elementele
de deasupra diagonalei principale, considerată ca axă de simetrie, cu elementele de sub diagonala principală,
elementele de pe diagonala principală rămânând la fel. De exemplu matricea:
1 2 3
4 5 6
7 8 9
Va deveni:
1 4 7
2 5 8
3 6 9*/
/*#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define MAX_N 50

int main(void)
{
    int n;
    scanf("%d", &n);
    if (n > MAX_N)
        return 0;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int aux = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = aux;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}*/

/*Aplicația 8.5: Se citește de la tastatură o matrice cu n<=20 linii și coloane. Să se memoreze într-un vector suma
tuturor elementelor de pe fiecare linie și într-un alt vector, suma tuturor elementelor de pe fiecare coloană. Să se
afișeze cei doi vectori. Se vor utiliza pointeri atât pentru vectori cât și pentru matrici.*/
/*#include <stdio.h>
#include <stdlib.h>
#define MAX_N 20

int lin[MAX_N], col[MAX_N];
int main(){
    int n;
    scanf("%d", &n);
    if(n>MAX_N)
        return 0;
    int a[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &(*(*(a+i*n)+j)));
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            *(lin+i)+=*(*(a+n*i)+j);
            *(col+j)+=*(*(a+n*i)+j);
        }
    }
    for(int i=0; i<n; i++){
        printf("Suma pe linia %d: %d si coloana %d: %d\n", i, *(lin+i), i, *(col+i));
    }
    return 0;
}*/

/*Aplicația 8.7: Se citește un număr n<=10 de orașe și apoi pentru fiecare 2 orașe se citește distanța directă dintre
ele. Dacă distanța este 0, înseamnă că între acele orașe nu există drum direct. Să se afișeze perechea de orașe
cele mai apropiate între ele în mod direct.*/
/*#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_N 10

// vom  presupune ca nu stim in ce ordine sunt citite orasele
int main()
{
    int a[MAX_N][MAX_N];
    int n;
    int dist, citire1, citire2; // ce vom citi de la tastatura
    int lenMin, oras1, oras2;   // unde vom memora distanta minima
    scanf("%d", &n);
    if(n>MAX_N)
        return -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                a[i][j] = 0;
            }
            else
            {
                scanf("%d %d %d", &dist, &citire1, &citire2);
                if(citire1>=n || citire2>=n){
                    perror("nu aveti valori bune");
                    return 1;
                }
                a[citire1][citire2] = dist;
            }
        }
    }
    lenMin = INT_MAX;
    oras1 = 0;
    oras2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i][j] < lenMin && a[i][j] != 0)
            {
                lenMin = a[i][j];
                oras1 = i;
                oras2 = j;
            }
        }
    }
    if (lenMin == INT_MAX){
        printf("Nu exista drumuri intre orase");
    }
    else{
        printf("Cel mai scurt drum este intre orasele %d si %d (%d km)", oras1, oras2, lenMin);
    }
}*/

/*Aplicația 8.8: Se citesc numerele m,n,p fiecare mai mici decat 10, apoi se citesc matricile a[m][n] și b[n][p]. Se
cere să se calculeze matricea „c” care rezultă din înmulțirea matricilor a cu b și să se afișeze.*/

/*#include <stdlib.h>
#include <stdio.h>
#define MAX_VAL 10

void matrixProduct(int m, int n, int p, int a[m][n], int b[n][p], int c[m][p]){
    for(int i=0; i<m; i++){
        for(int j=0; j<p; j++){
            int sum=0;
            for(int k=0; k<n; k++){
                sum+=(a[i][k] * b[k][j]);
            }
            c[i][j]=sum;
        }
    }
}
int main(){
    int m,n,p;
    scanf("%d %d %d", &m, &n, &p);
    if(m>MAX_VAL || n>MAX_VAL || p>MAX_VAL)
        return -1;
    int a[m][n], b[n][p], c[m][p];

    matrixProduct(m,n,p,a,b,c);

    for(int i=0; i<m; i++){
        for(int j=0; j<p; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}*/

/*Aplicația 8.9: Se citește un număr n<=10. Se cere să se inițializeze o matrice a[n][n] cu 1 pe diagonale și cu 0 în
rest. Să se afișeze matricea.*/

/*#include <stdio.h>
#include <stdlib.h>
#define MAX_N 10

// alocare dinamica
int main()
{
    int n;
    scanf("%d", &n);
    if (n > MAX_N)
        return 1;

    int **a;
    if ((a = (int **)malloc(n * sizeof(int *))) == NULL)
    {
        printf("Memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++)
    {
        if ((a[i] = (int *)malloc(n * sizeof(int))) == NULL)
        {
            printf("memorie insuficienta\n");
            for (i--; i >= 0; i--)
                free(a[i]);
            free(a);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = (int)(i == j);
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}*/

/*Aplicația 8.10: Se citește un număr n<=10 de produse și pentru fiecare produs vânzările lui trimestriale pe un an
(4 valori). Se cere să se afișeze care produse au înregistrat o creștere continuă a vânzărilor în decurs de un an.*/

/*#include <stdio.h>
#include <stdlib.h>
#define MAX_N 10

//fiecare linie va reprezenta cate un produs
int main(){
    int n;
    scanf("%d", &n);
    if(n>MAX_N)
        exit(EXIT_FAILURE);
    int a[n][4];//cele 4 valori vor fi tinute minte pe o linie
    for(int i=0; i<n; i++)
        scanf("%d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]); //valorile trimestriale pe un an
    printf("Produsele ce au inregistrat o crestere pe tot parcursul anului sunt:\n");
    for(int i=0; i<n; i++){
        int ok=1;
        for(int j=0; j<3 && ok==1; j++){
            if(a[i][j]>a[i][j+1])
                ok=0;
        }
        if(ok)
            printf("%d ", i+1); //pentru a avea produsul 1, nu produsul 0
    }
}*/