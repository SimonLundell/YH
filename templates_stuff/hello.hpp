template <class T>
class Person {
    public:
        Person(T age);
        Person();
        T getAge();
    
    private:
        T _age;
};
