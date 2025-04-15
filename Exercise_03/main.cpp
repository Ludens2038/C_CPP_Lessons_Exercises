#include "list.h"
#include <cassert>

int main() {

    MC::List<int> list1;
    assert(list1.size() == 0);
    list1.push_back(100);
    assert(list1.size() == 1);
    assert(list1.back() == 100);

}