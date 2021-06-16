#include "hello.hpp"
#include <iostream>

template<class T>
Person<T>::Person(T age) : _age(age) {
    std::cout << "fuck you\n";
}

template<class T>
Person<T>::Person() {
    std::cout << "fuck you\n";
}

template<class T>
T Person<T>::getAge() {
    std::cout << _age << "\n";
}


int main() {

    Person<int> person(20.0);
    Person<int> person2;
    person.getAge();

    return 0;
}