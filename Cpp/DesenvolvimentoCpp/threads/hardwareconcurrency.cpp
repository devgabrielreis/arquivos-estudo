#include <thread>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << std::thread::hardware_concurrency() << std::endl;
    return 0;
}
