#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
/*Implementati pe calculator structura de date stiva, asa cum este descrisa in laborator.*/

int stack[MAX_LEN];
int top_stack = -1; // spre deosebire de coada, ne intereseaza doar varful stivei
int queue[MAX_LEN];
int front_queue = -1, rear_queue = -1; // trebuie sa stim inceputul si finalul cozii de elemente

//! Stiva are 3 comenzi: push, pop, display

void push(int element)
{
    if (top_stack == MAX_LEN - 1)
    {
        printf("Stiva e plina");
        return;
    }
    else
    {
        stack[++top_stack] = element;
    }
}

int pop()
{
    if (top_stack == -1)
    {
        printf("Stiva este goala");
        return -1;
    }
    else
    {
        return stack[top_stack--];
    }
}

void displayStack()
{
    if (top_stack == -1)
    {
        printf("Stiva e goala");
    }
    else
    {
        for (int i = top_stack; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

//! Coada are 3 comenzi: addQueue, removeQueue, displayQueue + lenQueue

void addQueue(int element)
{
    if (rear_queue == MAX_LEN - 1)
    {
        printf("Coada este plina");
        return;
    }
    else
    {
        queue[++rear_queue] = element;
        if (front_queue == -1)
            front_queue = 0;
    }
}

int removeQueue()
{
    if (front_queue > rear_queue || front_queue == -1 /*echivalent cu rear_queue==-1*/)
    {
        printf("Coada este goala");
        return -1;
    }
    else
    {
        return queue[front_queue++];
    }
}

void displayQueue()
{
    if (front_queue > rear_queue || front_queue == -1 /*echivalent cu rear_queue==-1*/)
    {
        printf("Coada este goala");
    }
    else
    {
        for (int i = front_queue; i <= rear_queue; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

/*Sa se implementeze cu ajutorul unei stive functia undo dintr-un fisier text. Functia
undo permite utilizatorului sa se revina la o versiune mai veche a documentului, eliminand ultimele
modificari. Pentru a implementa functia undo cu o stiva fiecare modificare va fi retinuta pe stiva, iar
cand e necesar sa se revina la o versiune anterioara se va elimina din stiva ultima modificare
adaugata. Pe stiva se va retine la fiecare modificare: textul nou scris (sir de maxim 100 de
caractere), randul unde a fost scris (int).*/

// Putem modifica structura de stiva deja scrisa, construindu-ne o structura pentru stiva noastra:

typedef struct
{
    char text[100];
    int row;
} modificare;

int top_modificare = -1;
modificare modificari[MAX_LEN];

void pushModificare(char *newText, int row)
{
    if (top_modificare == MAX_LEN - 1)
    { // stack-ul poate fi alocat si dinamic, pt a avea un numar mai mare de modificari valabile
        printf("S a ajuns la nivelul maxim de modificari");
        return;
    }
    else
    {
        // in varful stivei de modificari copiem ultima modificare
        modificari[++top_modificare].row = row;
        strcpy(modificari[top_modificare].text, newText);
    }
}

modificare *popModificare()
{
    if (top_modificare == -1)
    {
        printf("Nu exista modificari precedente");
        return NULL;
    }
    else
    {
        return &modificari[top_modificare--];
    }
}

void displayModificare()
{
    if (top_modificare == -1)
    {
        printf("Nu s-au facut modificari");
    }
    else
    {
        for (int i = top_modificare; i >= 0; i--)
        {
            printf("Modificarea a fost facuta pe randul %d: %s\n", modificari[i].row, modificari[i].text);
        }
        printf("\n");
    }
}
void verificareFunctieUNDO()
{
    //*Verificare pentru push pop display
    char *p = malloc(10 * sizeof(char)); // trebuie verificat
    p = "andu";
    pushModificare(p, 5); // primul el din stiva
    p = "CdaA";
    pushModificare(p, 6); // al doilea el din stiva
    displayModificare();  // afisam stiva (CdaA, andu)
    modificare *aux;      // verificam comanda pop
    if ((aux = popModificare()) != NULL)
    {
        printf("%s", aux->text);
    }
    //! functia Undo este de fapt doar functia popModificare()
    // Algoritmul poate fi implementat pentru un fisier text, comanda push fiind folosita (de ex.) la umplerea unui buffer de caractere
}

/*Sa se implementeze cu ajutorul unei cozi un buffer care retine temporar informatiile
primite de la diversi transmitatori (informatia este adaugata in coada) si le transmite mai apoi catre
un receptor (informatia este eliminata din coada). Informatia primita in buffer are urmatoare
structura: numar identificare transmitator (int), mesaj (sir de caractere de maxim 256 caractere).*/

// La fel ca la problema anterioara, creem o structura specifica pentru problema

typedef struct
{
    int id;
    char text[256];
} transmisie;

transmisie bufT[MAX_LEN]; // bufferul care va memora transmisiile
int rearT = -1, frontT = -1;

// vom avea nevoie de o comanda de push pop si display

void pushT(transmisie *newT)
{ // spre deosebire de problema anterioara, am ales sa se dea push la o transmisie (nu la caracteristicile ei)
    if (rearT == MAX_LEN - 1)
    {
        printf("Bufferul de transmisii este plin\n");
        return;
    }
    else
    {
        bufT[++rearT] = *newT; // copiem newT in urmatoarea pozitie din buffer
        if (frontT == -1)
            frontT = 0;
    }
}

transmisie *popT()
{
    if (frontT > rearT || frontT == -1)
    {
        printf("Bufferul de transmisii este gol\n");
        return NULL;
    }
    else
    {
        return &bufT[frontT++];
    }
}

void displayT()
{
    if (frontT > rearT || frontT == -1)
    {
        printf("Bufferul de transmisii este gol\n");
    }
    else
    {
        for (int i = frontT; i >= rearT; i++)
        {
            printf("ID %d: %s", bufT[i].id, bufT[i].text);
        }
    }
}

void verificareTransmitatori()
{
    // ar trebui sa mearga, fiind aceeasi structura ca inainte
}
int main()
{
    verificareFunctieUNDO();
    verificareTransmitatori();
}
