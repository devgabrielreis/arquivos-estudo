#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

int main(int argc, char const *argv[])
{
    std::mutex lock;
    std::vector<int> vec;

    int N = 500000;

    std::thread threadB = std::thread([&]
    {
        for (int i = 0; i < N; i++)
        {
            lock.lock();
            vec.push_back(i);
            lock.unlock();
        }
    });

    for (int i = 0; i < N; i++)
    {
        lock.lock();
        vec.push_back(i);
        lock.unlock();
    }

    threadB.join();

    std::cout << "Tamanho do vetor: " << vec.size() << std::endl;
    return 0;
}
