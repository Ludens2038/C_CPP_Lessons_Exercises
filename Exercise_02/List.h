#ifndef LIST_H
#define LIST_H

typedef struct _Node {
    void* value;
    struct _Node* next;
    struct _Node* prev;
} Node;

typedef struct {
    int nOfElements;
    Node* head;
    Node* tail;
} List;

// creation
void init(List* l); // initializes a newly created list

// capacity
int size(List* l); // returns the number of elements
int empty(List* l); // checks whether the list is empty

// modifiers
void clear(List* l);
void push_back(List* l, void* value); // adds an element to the end
void pop_back(List* l); // removes the last element
void push_front(List* l, void* value); // inserts an element to the beginning
void pop_front(List* l); // removes the first element
void sort(List* l, int (*compare)(void*, void*)); // sorts the elements

// element access
void* front(List* l); // access the first element
void* back(List* l); // access the last element

#endif