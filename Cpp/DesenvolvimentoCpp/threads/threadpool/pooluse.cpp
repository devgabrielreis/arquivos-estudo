#include "threadpool.hpp"

#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>

using namespace std::chrono_literals;

void func()
{
    std::random_device rd;
    std::mt19937 rng(rd());

    // build a vector of random numbers
    std::vector<int> data;
    data.reserve(100000);
    std::generate_n(std::back_inserter(data), data.capacity(), [&](){ return rng(); });
    std::sort(data.begin(), data.end(), std::greater<int>());
}

int main(int argc, char const *argv[])
{
    ThreadPool tp;
    tp.Start();

    std::thread b = std::thread([&]
    {
        for (int i = 0; i < 500; i++)
        {
            tp.QueueJob(func);
        }
    });

    for (int i = 0; i < 500; i++)
    {
        tp.QueueJob(func);
    }

    b.join();

    // std::this_thread::sleep_for(2s);

    for (int i = 0; i < 500; i++)
    {
        tp.QueueJob(func);
    }

    // while(tp.busy()) {}

    tp.Stop();

    std::cout << std::boolalpha << "busy: " << tp.busy() << std::endl;
    std::cout << "jobs left: " << tp.jobsLeft() << std::endl;
    return 0;
}
