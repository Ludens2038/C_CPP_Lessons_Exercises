#ifndef PERSON_H
#define PERSON_H

typedef struct Person {
    int id;
    int age;
    char* name;
} Person;

Person* new_Person(int id, int age, char* name);
void delete_Person(Person* this);
void printPerson(Person* p);

#endif