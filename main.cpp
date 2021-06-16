#include <iostream>
#include <string>
//#include <stdlib.h>

namespace Test
{
    const std::string test1{"Hello 1"};
    const std::string test3{"Hello 3"};
} // namespace Test

int main(int argc, char* argv[]) {

    std::cout << Test::test1 << " " << Test::test3 << "\n";

    return 0;
}