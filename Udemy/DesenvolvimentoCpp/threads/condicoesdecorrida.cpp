#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

using namespace std::chrono_literals;

int main(int argc, char const *argv[])
{
    std::atomic<int> counter(0);
    // int counter = 0;

    std::thread t = std::thread([&]
    {
        for (int i = 0; i < 100; i++)
        {
            counter++;
            std::this_thread::sleep_for(1ms);
        }
    });

    for (int i = 0; i < 100; i++)
    {
        counter++;
        std::this_thread::sleep_for(1ms);
    }

    t.join();

    std::cout << counter << std::endl;

    return 0;
}
