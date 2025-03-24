#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "IntList.h"

void printList(IntList* l) {
    if (l == NULL || l->nOfElements == 0) {
        return;
    }

    int counter = 0;

    Node* curr = l->head;
    while (curr != NULL) {
        printf("Element %d: %d\n", counter, curr->value);
        curr = curr->next;
        counter++;
    }
    printf("----------------------\n");
}

int main(void)
{
    IntList* list = malloc(sizeof(IntList));
    init(list);

    push_back(list, 110);
    push_back(list, 12);
    push_front(list, 420);
    push_front(list, 69);

    printf("first element: %d\n", front(list));
    printf("last element: %d\n", back(list));

    printList(list);

    pop_front(list);
    printList(list);

    pop_back(list);
    printList(list);

    printf("first element: %d\n", front(list));
    printf("last element: %d\n", back(list));

    /*
    assert(size(list) == 0);
    push_back(list, 100);
    assert(size(list) == 1);
    assert(back(list) == 110);
    clear(list);
    free(list);
    */
}
