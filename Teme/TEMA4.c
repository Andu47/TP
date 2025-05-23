#include <stdio.h>
#include <string.h>

/*Să se codifice cu ajutorul structurilor cu câmpuri pe biți informațiile despre un fișier: nume (șir de
maxim 15 caractere), dimensiunea acestuia (int - număr de octeți, maxim 1024 octeți), tipul acestuia (.txt - 0, .doc
- 1, .xls – 2), tipul fisierului (normal – 0, read-only – 1). Să se citească informația despre un fișier, și să se afișeze
pe ecran.*/

/*struct Fis
{
    char nume[16];
    struct
    {
        unsigned int dim : 10;
        unsigned int ext : 2;
        unsigned int tip : 1;
    } info;
};

int main()
{
    struct Fis f;

    printf("Nume fisier: ");
    fgets(f.nume, 16, stdin);
    size_t len = strlen(f.nume);
    if (f.nume[len - 1] == '\n')
        f.nume[len - 1] = '\0';

    printf("Dimensiune: ");
    scanf("%u", f.info.dim);

    printf("Extensie (.txt=0, .doc=1, .xls=2): ");
    scanf("%u", f.info.ext);

    printf("Tip (0=normal, 1=read-only): ");
    scanf("%u", f.info.tip);

    printf("\nNume: %s\n", f.nume);
    printf("Dimensiune: %u octeti\n", f.info.dim);

    switch (f.info.ext)
    {
    case 0:
        printf("Extensie: .txt\n");
        break;
    case 1:
        printf("Extensie: .doc\n");
        break;
    case 2:
        printf("Extensie: .xls\n");
        break;
    default:
        printf("Extensie: necunoscuta\n");
    }

    printf("Tip: %s\n", f.info.tip ? "read-only" : "normal");

    return 0;
}*/

/*Aplicația 4.4: Folosind câmpuri pe biți, definiţi o structură pentru memorarea următoarelor informaţii despre
animale:
● numărul de picioare: număr întreg, minim 0 (ex. şarpe), maxim 1000 (ex. miriapod)
● greutatea în kg: număr real
● periculos pentru om: da/nu
● abrevierea ştiinţifică a speciei: şir de maxim 8 caractere
● vârsta maximă în ani: număr întreg, minim 0, maxim 2000
Unde este posibil, codificaţi informaţiile prin numere întregi de dimensiune cât mai mică, spre exemplu “da”=1,
“nu”=0. Definiţi structura în aşa fel încât să ocupe spaţiul minim de memorie posibil. Afişaţi spaţiul de memorie
ocupat, folosind operatorul sizeof. Folosind structura definită, citiţi de la tastatură informaţii despre un animal, iar
pe urmă afişaţi-le pe ecran.
Exemplu: valoare=147000, unitate:gram => 147 kilogram*/

/*struct Animal {
    char specie[9];
    float greutate;
    struct {
        unsigned int picioare : 10;
        unsigned int periculos : 1;
        unsigned int varsta_max : 11;
    } info;
};

int main() {
    struct Animal a;

    printf("Specie (max 8 caractere): ");
    fgets(a.specie, 9, stdin);
    size_t len = strlen(a.specie);
    if (a.specie[len - 1] == '\n') a.specie[len - 1] = '\0';

    printf("Greutate (kg): ");
    scanf("%f", &a.greutate);

    printf("Numar picioare (0 - 1000): ");
    scanf("%u", &a.info.picioare);

    printf("Periculos (0=nu, 1=da): ");
    scanf("%u", &a.info.periculos);

    printf("Varsta maxima (0 - 2000): ");
    scanf("%u", &a.info.varsta_max);

    printf("\n--- Informatii animal ---\n");
    printf("Specie: %s\n", a.specie);
    printf("Greutate: %.2f kg\n", a.greutate);
    printf("Picioare: %u\n", a.info.picioare);
    printf("Periculos: %s\n", a.info.periculos ? "da" : "nu");
    printf("Varsta maxima: %u ani\n", a.info.varsta_max);

    printf("\nMemorie ocupata: %lu bytes\n", sizeof(a));

    return 0;
}*/

/*Aplicația 4.6: Se consideră că o măsurătoare are asociată unitatea de măsură (gram, metru, litru) și multiplicatorul
acesteia (pico, nano, mili, centi, deci, deca, hecto, kilo, mega, giga).
● Să se codifice o măsurătoare astfel încât să conțină o valoare întreagă pozitivă care să acopere un interval
cât mai mare de valori, unitatea de măsură și multiplicatorul acesteia. O măsurătoare va ocupa exact 2
octeți.
● Să se citească o valoare unsigned și o unitate de măsură. La citire nu există multiplicator. Să se determine
multiplicatorul astfel încât valoarea stocată să fie cât mai mică, fără a se pierde precizie, iar apoi să se
stocheze într-o măsurătoare. Dacă valoarea nu încape, se va afișa o eroare. Să se afișeze toate câmpurile
măsurătorii.*/

/*const char *unitati[] = {"gram", "metru", "litru"};
const char *multiplicatori[] = {
    "pico", "nano", "micro", "mili", "centi", "deci",
    "unitate", "deca", "hecto", "kilo", "mega", "giga"
};

struct Masurare {
    unsigned int valoare : 10;
    unsigned int multiplicator : 4;
    unsigned int unitate : 2;
};

int main() {
    unsigned int val_input;
    char unit_input[10];
    int unit_index = -1;
    int m;

    printf("Valoare pozitiva: ");
    scanf("%u", &val_input);

    printf("Unitate (gram/metru/litru): ");
    scanf("%s", unit_input);

    if (strcmp(unit_input, "gram") == 0) unit_index = 0;
    else if (strcmp(unit_input, "metru") == 0) unit_index = 1;
    else if (strcmp(unit_input, "litru") == 0) unit_index = 2;
    else {
        printf("Unitate necunoscuta.\n");
        return 1;
    }

    int multiplicator_final = -1;
    for (m = 0; m < 12; m++) {
        if ((val_input >> m) <= 1023) {
            multiplicator_final = m;
            break;
        }
    }

    if (multiplicator_final == -1) {
        printf("Eroare: valoarea nu poate fi reprezentata in 10 biti.\n");
        return 1;
    }

    struct Masurare m1;
    m1.valoare = val_input >> multiplicator_final;
    m1.multiplicator = multiplicator_final;
    m1.unitate = unit_index;

    printf("\nMasurare codificata:\n");
    printf("Valoare: %u\n", m1.valoare);
    printf("Multiplicator: %s\n", multiplicatori[m1.multiplicator]);
    printf("Unitate: %s\n", unitati[m1.unitate]);

    return 0;
}*/
