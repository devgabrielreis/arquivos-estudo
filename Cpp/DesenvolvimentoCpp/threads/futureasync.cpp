#include <future>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::future<int> F1 = std::async([]
    {
        std::cout << "Thread A" << std::endl;
        return 42;
    });

    std::future<int> F2 = std::async([]
    {
        std::cout << "Thread B" << std::endl;
        return 24;
    });

    int soma = F1.get() + F2.get();

    std::cout << "Soma = " << soma << std::endl;

    return 0;
}
