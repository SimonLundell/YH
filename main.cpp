#include <iostream>
#include "text.hpp"


int main(int argc, char* argv[]) {
    for (int i = 0; i < text_txt_len; i++)
    {
        std::cout << text_txt[i] << " ";
    }

}