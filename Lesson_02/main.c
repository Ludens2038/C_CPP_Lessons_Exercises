#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int goodMorning(int i) {
    printf("good morning \n");
    return i * 2;
}
int goodEvening(int i) {
    printf("good evening \n");
    return i * 3;
}

typedef int (*PFN)(int); //pointer auf funktion, wird so gemacht, wenn man array aus funktionen hat

void axel2(int i, PFN pfn) {
    printf("axel: %d\n", i);
    pfn(i);
}

int compareInt(void* a, void* b) { //void pointer sind generische pointer, beim derefernzieren von void pointern muss ich typecasten
    return ((int*)a) - ((int*)b); //typecasten von void pointer auf int pointer
}

typedef struct Person Person;

struct Person {
    int id;
    int age;
    char* name;

    void (*print)(struct Person*); //pointer auf funktion, typedef funzt noch nicht, weil er quasi noch nicht existiert
};

void printPerson(Person* p) {
    printf("Person: %s, %d, %d\n", p->name, p->id, p->age);
}

void printEmployee(Person* p) {
    printf("Employee: %s, %d, %d\n", p->name, p->id, p->age);
}

Person* new_Person(int id, int age, char* name) {
    Person* this = malloc(sizeof(Person));
    if (this != NULL) {
        this->print = printPerson; //jedes Person struct hat jetzt auch die funktion print gespeichert
        this->id = id;
        this->age = age;
        this->name = _strdup(name);
    }
    return this; //falls null wird wenigstens null zurückgegeben
}

void delete_Person(Person* this) { //geht auch mit void pointer, aber kein bock auf casten
    free(this->name);
    free(this);
}

int main() {

    printf("funktion axel2 \n");
    axel2(10, goodMorning);

    printf("--------------------\n");

    int i = 17;
    int* pi = &i;
    *pi = 5;

    printf("funktionen in array geben \n");

    //int (*pfn)(int); vorläufer vom polymprphismus
    PFN pfn;
    int a[] = {1, 2, 3};
    PFN funktions[] = {goodMorning, goodEvening};
    for (int i = 0; i < 2; i++) {
        funktions[i](10);
    }

    printf("--------------------\n");
    printf("funktionen in if else \n");

    if (i == 17) {
        pfn = goodMorning;
    } else {
        pfn = goodEvening;
    }

    printf("%d \n", pfn(10));
    printf("--------------------\n");

    printf("quicksort verwenden \n");
    int b[] = {3, 2, 1};
    qsort(b, 3, sizeof(int), compareInt);

    for (int i = 0; i < 3; i++) {
        printf("%d, ", b[i]);
    }
    printf("\n--------------------\n");

    printf("Person struct \n");

    Person *p = malloc(sizeof(Person));
    p->id = 1;
    p->age = 5;
    p->name = "Axel";

    printPerson(p);

    free(p);

    printf("\n--------------------\n");

    printf("arbeiten mit gebautem konstruktor und destruktor \n");

    Person* axel = new_Person(1, 5, "Axel");
    printPerson(axel); //normal
    axel->print(axel); //über pointer
    //delete_Person(axel);

    printf("\n--------------------\n");

    printf("arbeiten mit employee \n");

    //wird vom compiler automatisch erledigt
    axel->print = printEmployee;

    axel->print(axel);

    delete_Person(axel);

    printf("\n--------------------\n");

    return 0;
}

