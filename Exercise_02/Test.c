#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "List.h"
#include "Person.h"

void printList(List* l) {
    if (l == NULL || l->nOfElements == 0) {
        printf("List is empty\n");
        return;
    }

    int counter = 0;

    Node* curr = l->head;
    while (curr != NULL) {
        printf("Person %d => ", counter);
        printPerson(curr->value);
        curr = curr->next;
        counter++;
    }
    printf("----------------------\n");
}

int compare(void* a, void* b) {
    Person* p1 = (Person*)a;
    Person* p2 = (Person*)b;

    return p1->id - p2->id;
}

int main(void) {
    List* list = malloc(sizeof(List));
    init(list);

    assert(size(list) == 0);

    Person* axel = new_Person(1, 5, "Axel");
    Person* max = new_Person(2, 10, "Max");
    Person* peter = new_Person(3, 15, "Peter");

    push_back(list, axel);
    push_back(list, max);
    push_back(list, peter);

    assert(size(list) == 3);

    printList(list);

    sort(list, compare);

    printList(list);

    printf("first element: %s\n", ((Person*)front(list))->name);
    printf("last element: %s\n", ((Person*)back(list))->name);
    printf("----------------------\n");

    pop_back(list);

    printList(list);

    pop_front(list);

    printList(list);
}