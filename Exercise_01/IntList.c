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
    } else {
        return INT_MAX;
    }
}