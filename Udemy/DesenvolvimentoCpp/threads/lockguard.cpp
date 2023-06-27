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
            std::lock_guard<std::mutex> Lock(m);
            vec.push_back(i);
        }
    });

    for (int i = 0; i < N; i++)
    {
        std::lock_guard<std::mutex> Lock(m);
        vec.push_back(i);
    }

    threadB.join();

    std::cout << "Tamanho do vetor: " << vec.size() << std::endl;
    return 0;
}
