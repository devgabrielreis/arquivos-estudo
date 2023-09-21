#include "minhadll.hpp"

#include <iostream>

void func()
{
    std::cout << "dentro da dll!!!" << std::endl;
}

void mostrarNumero(int x)
{
    std::cout << "numero: " << x << std::endl;
}
