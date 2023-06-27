#include <iostream>
#include <thread>

#define NUM 10

void threadFunc()
{
    for (int i = 0; i < NUM; i++)
    {
        std::cout << "Thead func" << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    std::thread threadA = std::thread(threadFunc);
    std::thread threadB = std::thread([](){ for (int i = 0; i < NUM; i++){std::cout << "Thread lambda" << std::endl;}});

    for (int i = 0; i < NUM; i++)
    {
        std::cout << "Main" << std::endl;
    }

    threadA.join();
    threadB.join();

    return 0;
}
