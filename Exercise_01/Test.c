#include <assert.h>
#include <stdlib.h>

#include "IntList.h"

int main(void)
{
    IntList* list = malloc(sizeof(IntList));
    init(list);
    assert(size(list) == 0);
    push_back(list, 100);
    assert(size(list) == 1);
    assert(back(list) == 110);
    clear(list);
    free(list);
}
