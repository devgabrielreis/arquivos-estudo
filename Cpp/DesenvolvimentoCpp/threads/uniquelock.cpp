#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

int main(int argc, char const *argv[])
{
    std::mutex m;
    std::vector<int> vec;

    int N = 500000;

    std::thread threadB = std::thread([&]
    {
        for (int i = 0; i < N; i++)
        {
            std::unique_lock<std::mutex> Lock(m);
            vec.push_back(i);
            Lock.unlock();
        }
    });

    for (int i = 0; i < N; i++)
    {
        std::unique_lock<std::mutex> Lock(m);
        vec.push_back(i);
        Lock.unlock();
    }

    threadB.join();

    std::cout << "Tamanho do vetor: " << vec.size() << std::endl;
    return 0;
}
