#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

#include "greetings.h"

#define PI 3.1415
#define MAX_SIZE 10

//call by reference
void init(int* value) { // *value ist pointer auf adresse von value
    *value = 10000; // *value ist der wert von value
}

void initArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

struct Person_ {
    int id;
    int age;
    char* name;
};



typedef struct Person_ Person; //somit muss man beim erstellen nicht mehr struct dazuschreiben. eine art alias

void printPerson(Person* this) {
    if (this != NULL) {
        printf("%d %d %s \n", this->id, this->age, this->name); //bei einem pointer muss mittels pfeilchen auf die werte zugegriffen werden
        //printf("%d %d %s \n", (*this).id, (*this).age, (*this).name); //das ist das gleiche wie oben
    }
}

int main(void) {

    unsigned int x = UINT_MAX, y =12;
    char c = 'a';
    char* text = "Hallo Welt";
    int len = strlen(text);

    printf("Hello, World!\n");
    printf("der wert von x: %d; PI ist %f\n", x, PI);
    printf("Die Laenge von \"%s\" ist %d\n", text, len);

    printf("---------------\n");

    greetings("Hello World");

    printf("---------------\n");

    int z = 0;

    init(&z); // & ist pointer auf adresse von z
    printf("Adresse von z ist ... %x \n", &z); // %x gibt hexadezimal aus
    printf("Adresse von y ist ... %x \n", &y); // %x gibt hexadezimal aus

    printf("z ist ... %d \n", z);

    //scanf_s("%d", &z); //_s ist sicherer
    //printf("z ist ... %d \n", z);

    printf("---------------\n");

    int a = 10;

    int* pa = &a; //pointer auf int wert der adresse von a
    printf("a ist ... %d \n", *pa);

    *pa = 5;
    printf("a ist ... %d \n", *pa);
    printf("a ist ... %d \n", a);

    printf("---------------\n");

    int b = 10;
    int* pb = NULL;
    pb = &b;
    if (pb != NULL) {
        *pb = 5;
    }
    printf("a ist ... %d \n", b);

    printf("---------------\n");

    int values [MAX_SIZE] = {1,2,3};
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");

    //initArray(values, MAX_SIZE); //muss nicht mit pointer werkeln weil array automatisch auf 0er element zeigt
    //printArray(values, MAX_SIZE);
    //printf("\n");

    int d = 1;
    int size_int_d = sizeof(d);
    printf("Size of int is %d \n", size_int_d);

    int size_array = sizeof(values);
    printf("Size of array is %d \n", size_array);

    int nOfElements = size_array / size_int_d;
    printf("End of elements is %d \n", nOfElements);

    printf("---------------\n");

    int* pe = values;
    printf("values[0] is %d %d \n", values[0], *pe);

    pe = pe + 1;
    printf("values[0] is %d %d \n", values[0], *pe);
    printf("values[0] is %d %d \n", values[2], *pe);

    printf("---------------\n");

    Person john;
    john.id = 1;
    john.age = 30;
    john.name = "John Doe";

    printPerson(&john);

    printf("---------------\n");

    char* mem = malloc(5); //mindestens 5 Bytes werden reserviert
    int* mem2 = malloc(sizeof(int)); //reserviert die Größe eines Integers

    if (mem2 != NULL) {
        *mem = 17;
        printf("%d \n", *mem);
        free(mem); //speicher wieder freigeben (quasi garbage collection)
    }

    Person* jane = malloc(sizeof(Person));
    if (jane != NULL) {
        jane->id = 2;
        jane->age = 25;
        jane->name = "Jane Doe";

        printPerson(jane);

        free(jane);
    }

    printf("---------------\n");

    return 0;
}
