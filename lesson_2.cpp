#include <iostream>
#include <string>

class Person {
    public:
      std::string name;

      Person(std::string name) {
          this->name = name;
      }
};

int main() {
    Person* person = new Person("Chocolate");
    Person* person2 = new Person("Strawberry");
    Person* person3 = person2;
    Person* person4 = (Person*)malloc(sizeof(Person));

    std::cout << person2 << "\n";
    std::cout << person3->name << "\n";
    person3->name = "Fuck me";
    std::cout << person2->name << "\n";

    return 0;
}