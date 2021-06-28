#include "Person.hpp"
#include <iostream>

int main() {
    Person* person = new Person(33);

    std::cout << person->getAge() << "\n";
}
