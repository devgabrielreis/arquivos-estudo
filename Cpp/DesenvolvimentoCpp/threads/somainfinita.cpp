#include <iostream>
#include <string>
#include <thread>
#include <chrono>

void soma(unsigned long long* valor, bool* stopped)
{
    using namespace std::chrono_literals;
    while (not *stopped)
    {
        (*valor)++;
        std::this_thread::sleep_for(1ms);
    }
    std::cout << "encerrando thread de soma" << std::endl;
}

void controle(unsigned long long* valor, bool* stopped)
{
    std::string opcao;

    while (not *stopped)
    {
        std::cin >> opcao;

        if (opcao == "valor")
        {
            std::cout << *valor << std::endl;
        }
        else if (opcao == "sair")
        {
            *stopped = true;
        }
    }

    std::cout << "encerrando thread controle" << std::endl;
}

int main(int argc, char const *argv[])
{
    bool stopped = false;
    unsigned long long valor = 0;

    std::thread a = std::thread(soma, &valor, &stopped);
    std::thread b = std::thread(controle, &valor, &stopped);

    b.join();
    a.join();

    std::cout << "encerrando" << std::endl;

    return 0;
}
