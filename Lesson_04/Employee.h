#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include <string>


namespace MC23 {


class Employee : public Person {
public:
    Employee(std::string n, int a, double s) : Person(n, a), salary(s) {
        std::cout << "Employee ctor" << std::endl;
        std::cout << std::endl;
    }

    ~Employee() {
        std::cout << "Employee dtor" << std::endl;
        std::cout << std::endl;
    }

    double getSalary() {
        return salary;
    }

    virtual std::string getName() const override {
        return Person::getName() + "********\n";
    }

private:
    double salary{0.0};

   };
}


#endif