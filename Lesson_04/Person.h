#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

#include "printable.h"

namespace MC23 {



 class Person : public Pritnable {
   public : 
   Person(std::string n = "", int a= 0) : name{n}, age{a} {
    std::cout << "Person ctor" << std::endl;
    }
 

 virtual ~Person() {
     std::cout << "Person dthor "<< std::endl;
     }

public:
        virtual std::string getName() const {
            return name;
    }

    virtual void print() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
            std::cout << std::endl;
    }


   
   
    private:
std::string name{ "" };
int age = {0};

    
    


};
}


#endif