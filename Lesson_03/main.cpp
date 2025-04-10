#include <iostream>

//#include <stdio.h>
#include <cstdio> // statt stdio.h
// das .h ist nicht notwendig, außer es ist eine selbst erstellte Header-Datei
#include "Person.h" //selbst erstellte Header-Datei einfügen

//using namespace MC23; //brutaler Namespace weil konzept connamespace verloren geht
//würden wir einen zweiten namesmace verwenden der auch Person enthält, dann würde es zu einem Konflikt kommen
//using namespace MC23::Person; würde nur die Person klasse importiert werden

using MC23::Person;

int main() {

    // double x =3.14;
    // MC23::Person person1;
    // person1.name = "Hans";
    //
    // std::string string2 = "ich bin auch initialisiert";
    // std::string string1{"ich bin initialisiert"};
    //
    // printf("Hallo Welt!, pi ist %f\n", x); // printf ist eine C-Funktion, die in C++ verwendet werden kann
    //
    // //die printmethode ist hinter << versteckt
    // std::cout << "Hello World!\n" << x << "\n" << "dies ist eine konkatinierung\n"; //verwendung von namespace std
    // std::cout << "Person x ist: " << person1.name <<"\n";
    //
    // //zum einlesen
    // std::cin >> x; // cin ist eine C++ Funktion, die in C verwendet werden kann
    // std::cout << "x wurde auf: " << x << " geändert\n";
    //
    // if (person1.name == "Hans") {
    //     std::cout << "Strings sind gleich" << std::endl;
    // }

    MC23::Perosn* p = foo();

}