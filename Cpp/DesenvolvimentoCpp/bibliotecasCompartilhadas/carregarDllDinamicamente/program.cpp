#include <windows.h>
#include <iostream>

using dllFuncPtr = void(*)();
using dllMostrarNumeroPtr = void(*)(int);

int main(int argc, char const *argv[])
{
    std::cout << "carregando dll..." << std::endl;
    HMODULE MinhaDLLModule = LoadLibraryA("minhadll.dll");

    if (!MinhaDLLModule)
    {
        std::cout << "erro ao carregar dll!" << std::endl;
        return 1;
    }

    dllFuncPtr func = (dllFuncPtr) GetProcAddress(MinhaDLLModule, "func");
    dllMostrarNumeroPtr mostrarNumero = (dllMostrarNumeroPtr) GetProcAddress(MinhaDLLModule, "mostrarNumero");

    std::cout << "chamando func" << std::endl;
    func();

    int num = 10;
    std::cout << "chamando mostrarNumero, num = " << num << std::endl;
    mostrarNumero(num);

    std::cout << "liberando dll" << std::endl;
    FreeLibrary(MinhaDLLModule);

    return 0;
}
