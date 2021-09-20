#include <iostream>

template<typename T>
void getValue(T var){
    std::cout << var << "\n";
}

template<class T>
class Vector
{
    public:
        Vector(T x, T y, T z);


        add(Vector<T> vec);
            
    private:
        T x;
        T y;
        T z;

};

int main() 
{
    getValue(5);
    getValue(5.0);
    getValue("Hello");
}