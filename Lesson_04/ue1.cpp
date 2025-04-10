#include <iostream>
#include <stdio.h>
#include "Person.h"
#include "Employee.h"
#include <stdexcept>
#include <vector>
#include <memory>

#include "printable.h"


using MC23::Person;
using MC23::Employee; // using namespace MC23::Employee;
   
int main() {

    std::vector<Person*> array; // der "*" für
    std::vector<std::shared_ptr<Person>> array2;

    // destructor wird automatisch ausgeführt, obwohl wir nie delete schreiben
    std::unique_ptr<Person> person0 = std::make_unique<Person>("Person0", 20);

    // shared pointer werden verwendet wenn mehrerer den gleichen pointer teile so wie in einer lsite
    // solange es die person betrifft nimmt man einfache referenzen bei der übergabe bei sharde pointern bei der übergabe muss * vor das objekt wie zb: p->match(*e);
    auto person1 = std::make_shared<Person>("Person1", 20);
    auto employee1 = std::make_shared<Employee>("Employee", 20, 500);
    // es gibt aber auch einer weak_ptr für referenz auf zb previous list.elements

    person0->print(); // ermöglicht durch uniquepointer

    array2.push_back(person1);
    array2.push_back(employee1);

    auto x = array2.front();
    x->print();

    auto y = array2.back();
    y->print();

    // Person* p = new Person{"Person 1", 20};
    // Person* e = new Employee{"Employee 1", 30, 1000.0};
    //
    // array.push_back(p);
    // array.push_back(e);
    //
    // for (int i = 0; i < array.size(); i++) {
    //     array[i]->print();
    // }
    //
    // // kurzform für for schleife, aber nullpointer setzten geht nicht
    // for (auto i : array) {
    //     i->print();
    // }
    //
    // std::cout << "name: " << e->getName() << std::endl;
    // std::cout << "Salary: " << dynamic_cast<Employee*>(e)->getSalary() << std::endl;
    //
    // e->print();
    // p->print();
    //
    // delete p;
    // delete e;

}

