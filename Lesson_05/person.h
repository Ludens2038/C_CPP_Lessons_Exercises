#ifndef PEROSN_H
#define PEROSN_H

#include <string>

class Person {
public:
    std::string name;
};

bool operator<(const Person& rhs, const Person& lhs) {
    return rhs.name < lhs.name;
}

// extend << operator for Person-Object
std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.name;
    return os;
}

#endif