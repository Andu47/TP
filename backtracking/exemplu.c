#include <stdio.h>
#include <stdlib.h>

#define MAX 100

char lab[MAX][MAX];
char labMin[MAX][MAX];
int nLab;
int startI, startJ;

void citireLab(char *numeF){
    FILE *fis=fopen(numeF, "r");
    if(!fis) exit(EXIT_FAILURE);

    fscanf(fis, "%d", &nLab);
    fscanf(fis, "%d %d", &startI, &startJ);

    char linie[MAX+1];
    fgets(linie, MAX, fis);

    for(int i=0; i<nLab; i++){
        fgets(linie, MAX, fis);
        for(int j=0; j<nLab; j++){
            lab[i][j]=linie[j];
        }
    }
    fclose(fis);
}

void afisareLab(){
    for(int i=0; i<nLab; i++){
        for(int j=0; j<nLab; j++){
            putchar(labMin[i][j]);
        }
        putchar('\n');
    }
}

int traseuI[MAX], traseuJ[MAX]; //*vom memora pasii pe care ii facem
int nTraseu=0; //*tinem minte lungimea traseului
int nTraseuMin=0; //*tinem minte lungimea traseului minim
int nSolutii=0; //*tinem minte cate solutii gasim
int di[4]={1,-1,0,0}; 
int dj[4]={0,0,1,-1}; //*pasii ce pot fi facuti

void afisareSol(){
    nSolutii++;
    //printf("Solutia %d, lungime %d\n", nSolutii, nTraseu);
    //afisareLab();
    //putchar('\n');
    if(nTraseu>nTraseuMin){
        nTraseuMin=nTraseu;
        for(int i=0; i<nLab; i++){
            for(int j=0; j<nLab; j++){
                labMin[i][j]=lab[i][j];
            }
        }
    }
}

void cauta(int i, int j){
    //!VALID
    if(i<0||i>nLab-1 || j<0||j>nLab-1)return; //*daca ajungem pe un patrat ce nu se afla in labirint renuntam
    if(lab[i][j]!='.')return; //*daca ajungem pe un patrat ce nu este liber renuntam

    //!v[k]=i
    traseuI[nTraseu]=i;
    traseuJ[nTraseu]=j;
    lab[i][j]='0'+nTraseu%10;
    nTraseu++;

    //!SOLUTIE
    if(i==0||i==nLab-1 || j==0||j==nLab-1){
        afisareSol();
    }
    else{
        for(int k=0; k<4; k++)
            cauta(i+di[k], j+dj[k]);
    }

    //*Dupa ce ne intoarcem din recursivitate la pasul acesta, putem sterge ce am memorat; pentru urmatoarele treceri prin (i,j)
    nTraseu--;
    lab[i][j]='.';
}

int main(){
    char numeFis[20]="exemplu1.txt";
    citireLab(numeFis);
    cauta(startI, startJ);
    printf("Avem %d solutii, din care cea mai scurta are lungimea: %d\n", nSolutii, nTraseuMin);
    afisareLab();
}