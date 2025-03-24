#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#include "List.h"
#include "Person.h"

void init(List* l) {
    if (l != NULL) {
        l->nOfElements = 0;
        l->head = NULL;
        l->tail = NULL;
    }
}

int size(List* l)
{
    if (l != NULL) {
        return l->nOfElements;
    }
    return INT_MAX;
}

int empty(List* l) {
    if (l->nOfElements == 0) {
        return 0;
    }
    return 1;
}

void clear(List* l) {
    if (l == NULL || l->nOfElements == 0) {
        return;
    }

    Node* curr = l->head;
    Node* prev = NULL;

    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
        free(prev);
    }

    l->head = NULL;
    l->tail = NULL;
    l->nOfElements = 0;
}

void push_back(List* l, void* value) {
    if (l == NULL) {
        return;
    }

    Node* n = malloc(sizeof(Node));
    if (n == NULL) {
        return;
    }
    n->value = value;
    n->next = NULL;
    n->prev = NULL;

    if (l->nOfElements == 0) {
        l->head = n;
        l->tail = n;
    } else {
        l->tail->next = n;
        n->prev = l->tail;
        l->tail = n;
    }

    l->nOfElements++;
}

void pop_back(List* l) {
    if (l == NULL || l->nOfElements == 0) {
        return;
    }

    if (l->nOfElements == 1) {
        delete_Person(l->head->value);
        l->head = NULL;
        l->tail = NULL;
    } else {
        Node* pop = l->tail;
        l->tail = pop->prev;
        l->tail->next = NULL;
        delete_Person(pop->value);
    }

    l->nOfElements--;
}

void push_front(List* l, void* value) {
    if (l == NULL) {
        return;
    }

    Node* n = malloc(sizeof(Node));
    if (n == NULL) {
        return;
    }
    n->value = value;
    n->next = NULL;
    n->prev = NULL;

    if (l->nOfElements == 0) {
        l->head = n;
        l->tail = n;
    } else {
        l->head->prev = n;
        n->next = l->head;
        l->head = n;
    }

    l->nOfElements++;
}

void pop_front(List* l) {
    if (l == NULL || l->nOfElements == 0) {
        return;
    }

    if (l->nOfElements == 1) {
        delete_Person(l->head->value);
        l->head = NULL;
        l->tail = NULL;
    } else {
        Node* pop = l->head;
        l->head = pop->next;
        l->head->prev = NULL;
        delete_Person(pop->value);
    }

    l->nOfElements--;
}

void sort(List* l, int (*compare)(void*, void*)) {
    if (l == NULL || l->nOfElements < 2 || compare == NULL) {
        return;
    }

    Node* i = l->head;
    Node* j = NULL;

    Node temp;

    while (i != NULL) {
        j = i->next;
        while (j != NULL) {
            if (compare(i->value, j->value) < 0) {
                temp.value = i->value;
                i->value = j->value;
                j->value = temp.value;
            }
            j = j->next;
        }
        i = i->next;
    }
}

void* front(List* l) {
    if (l == NULL || l->nOfElements == 0) {
        return NULL;
    } else {
        return l->head->value;
    }
}

void* back(List* l) {
    if (l == NULL || l->nOfElements == 0) {
        return NULL;
    } else {
        return l->tail->value;
    }
}