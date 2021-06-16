#include <iostream>
#include <exception>
#include <vector>

int main() {
    int a = 5;
    std::vector<int> b{2,4,0};
    int c;
    for(int i = 0; i < b.size(); i++) {
        try {
            if (b[i] == 0) throw std::overflow_error("Division by 0");
            c = a/b[i];
        }
        catch(std::overflow_error &o) {
        std::cerr << o.what() << "\n";
        return -1;
        }
    }    
    return 0;
}