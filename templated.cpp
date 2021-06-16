#include <iostream>

template<typename T>
T multiply(T a, T b) {
    return a*b;
}

template<typename RT, typename A, typename B>
RT divide(A a, B b) {
    return a/b;
}

int main() {

    float a = 10.002;
    float b = 304.3;

    int x = 3;
    int y = 5;

    double result = multiply<double>(100,500); // Hardcoded to double
    std::cout << result << "\n";
    std::cout << multiply(a,b) << " " << multiply(x,y) << "\n";

    float div = divide<float, double, double>(50,23); // argument with <returntype, arg, arg>
    std::cout << div << "\n";

    return 0;
}