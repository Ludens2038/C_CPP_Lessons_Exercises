#include "list.h"
#include "person.h"
#include <cassert>
#include <algorithm>
#include <vector>

void print() {

}

int compare_int(const int& l, const  int& r) {
    return l - r;
}

template <typename T>
void sort_0(std::vector<T> v, int (*cmp)(const T& l, const T& r)) {
    if (v[0] > v[1]) {
        v[0] = v[1];
    }
}

template <typename T, typename F>
void sort_1(std::vector<T> v, F cmp) {
    if (v[0] > v[1]) {
        v[0] = v[1];
    }
}

int main() {

    std::vector<int> list{3, 2};


    int x = 0;
    int y = 1;

    // capture clause !(anschauen!)
    auto l = [] (const int& l, const int& r) {
        std::cout << "hello 1: " << std::endl;
        return true;
    };

    l(x, y);
    x = 1000; // wird nicht übernommen bei capture clause
    y = 1000; // wird nicht übernommen bei capture clause
    l(x, y);

    sort_0(list, compare_int);
    sort_1


    [] { std::cout << "hello" << std::endl; }();

    std::cout << "end of lesson 06" << std::endl;
    std::cout << std::endl;


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
    list2.push_back(Person{ "John Doe" });
    list2.push_back(Person{ "Jane Doe" });

    list2.print();
    std::cout << std::endl;

    list2.sort();

    list2.print();
    std::cout << std::endl;

    MC::List<Person> list3 = list2;
    list3.print();
    std::cout << std::endl;

    list3.push_back(Person{ "Felix Sams" });
    list2 = list3;
    list2.print();
    std::cout << std::endl;

    list2.pop_back();
    list2.print();
    std::cout << std::endl;

    for (auto i : list1) {
        std::cout << i << std::endl;
    }

    auto result = std::find(list1.begin(), list1.end(), 200);
    std::cout << "result: " << *result << std::endl;

    for (auto i : list2) {
        std::cout << i << std::endl;
    }

    // auto result2 = std::find(list2.begin(), list2.end(), 'Jane');
    // std::cout << "result: " << *result2 << std::endl;


}