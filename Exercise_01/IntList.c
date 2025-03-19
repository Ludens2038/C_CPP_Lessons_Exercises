#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "IntList.h"

// returns the number of elements
int size(IntList* l)
{
    if (l != NULL) {
        return l->nOfElements;
    }
    return INT_MAX;
}

void IntList_init(IntList* l) {
    if (l != NULL) {
        l->nOfElements = 0;
        l->head = NULL;
        l->tail = NULL;
    }
}

// what should we return for true or false?
int empty(IntList* l) {
    if (l->nOfElements == 0) {
        return 0;
    }
    return 1;
}

void clear(IntList* l) {
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

void push_back(IntList* l, int value) {
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

void pop_back(IntList* l) {
    if (l == NULL || l->nOfElements == 0) {
        return;
    }

    if (l->nOfElements == 1) {
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
    } else {
        Node* pop = l->tail;
        l->tail = pop->prev;
        l->tail->next = NULL;
        free(pop);
    }

    l->nOfElements--;
}

void push_front(IntList* l, int value) {
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

void pop_front(IntList* l) {
    if (l == NULL || l->nOfElements == 0) {
        return;
    }

    if (l->nOfElements == 1) {
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
    } else {
        Node* pop = l->head;
        l->head = pop->next;
        l->head->prev = NULL;
        free(pop);
    }

    l->nOfElements--;
}

int front(IntList* l) {
    if (l == NULL || l->nOfElements == 0) {
        return INT_MAX;
    } else {
        return l->head->value;
    }
}

int back(IntList* l) {
    if (l == NULL || l->nOfElements == 0) {
        return INT_MAX;
    } else {
        return l->tail->value;
    }
}