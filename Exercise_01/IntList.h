#ifndef INTLIST_H
#define INTLIST_H

typedef struct _Node {
    int value;
    struct _Node* next;
    struct _Node* prev;
} Node;

typedef struct {
    int nOfElements;
    Node* head;
    Node* tail;
} IntList;

// creation
void init(IntList* l); // initializes a newly created list

// capacity
int size(IntList* l); // returns the number of elements
int empty(IntList* l); // checks whether the list is empty

// modifiers
void clear(IntList* l);
void push_back(IntList* l, int value); // adds an element to the end
void pop_back(IntList* l); // removes the last element
void push_front(IntList* l, int value); // inserts an element to the beginning
void pop_front(IntList* l); // removes the first element
void sort(IntList* l); // sorts the elements

// element access
int front(IntList* l); // access the first element
int back(IntList* l); // access the last element

#endif