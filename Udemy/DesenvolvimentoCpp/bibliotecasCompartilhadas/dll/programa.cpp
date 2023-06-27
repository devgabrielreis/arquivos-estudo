#include "minhadll.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
    std::string input;
    std::cout << "diga algo: ";
    std::cin >> input;

    dizer(input);

    return 0;
}
