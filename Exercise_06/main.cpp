#include "list.h"
#include "person.h"
#include <cassert>
#include <algorithm>

void print() {
}

int main() {
    MC::List<int> list1;
    // assert(list1.size() == 0);
    list1.push_back(400);
    // assert(list1.size() == 1);
    // assert(list1.back() == 400);
    list1.push_back(300);
    list1.push_back(200);
    list1.push_front(100);

    list1.print();
    std::cout << std::endl;

    MC::List<Person> list2;
    list2.push_back(Person{"John Doe"});
    list2.push_back(Person{"Jane Doe"});

    list2.print();
    std::cout << std::endl;

    list2.sort([](const Person &a, const Person &b) {
        return a.name < b.name;
    });

    std::cout << "Sorted Lsit: " << std::endl;
    list2.print();
    std::cout << std::endl;

    MC::List<Person> list3 = list2;
    list3.print();
    std::cout << std::endl;

    list3.push_back(Person{"Felix Sams"});
    list2 = list3;
    list2.print();
    std::cout << std::endl;

    list2.pop_back();
    list2.print();
    std::cout << std::endl;

    for (auto i: list1) {
        std::cout << i << std::endl;
    }

    auto result = std::find(list1.begin(), list1.end(), 200);
    std::cout << "result: " << *result << std::endl;

    for (auto i: list2) {
        std::cout << i << std::endl;
    }

    auto result2 = std::find(list2.begin(), list2.end(), Person{"Jane Doe"});
    std::cout << "result: " << *result2 << std::endl;
}
