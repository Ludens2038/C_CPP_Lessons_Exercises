#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Person.h"

Person* new_Person(int id, int age, char* name) {
    Person* this = malloc(sizeof(Person));
    if (this != NULL) {
        this->id = id;
        this->age = age;
        this->name = _strdup(name);
    }
    return this;
}

void delete_Person(Person* this) {
    free(this->name);
    free(this);
}

void printPerson(Person* p) {
    printf(" ID: %d, Name: %s, Age: %d\n", p->id, p->name, p->age);
}