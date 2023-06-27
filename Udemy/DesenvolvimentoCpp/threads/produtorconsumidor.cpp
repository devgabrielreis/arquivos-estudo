#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <vector>
#include <condition_variable>

using namespace std::chrono_literals;

int main(int argc, char const *argv[])
{
    std::mutex Mutex;
    std::condition_variable CondVar;

    std::vector<int> NumbersToProcess;
    std::atomic_bool bContinue{ true };

    std::thread ConsumerThread([&]
    {
        std::unique_lock<std::mutex> Lock{ Mutex };
        while(bContinue)
        {
            while (!NumbersToProcess.empty())
            {
                const int Number = NumbersToProcess.back();
                NumbersToProcess.pop_back();
                std::cout << "[Consumer Thread]: Numero -> " << Number << std::endl;
            }

            // Espera ter novos elementos na lista
            CondVar.wait(Lock);
        }
    });

    std::thread ProducerThread([&]
    {
        while (bContinue)
        {
            std::cout << "Digite um numero ";
            int Number;
            std::cin >> Number;

            std::unique_lock<std::mutex> Lock{ Mutex };
            NumbersToProcess.push_back(Number);

            if (NumbersToProcess.size() == 5)
            {
                Lock.unlock();
                CondVar.notify_one();
                std::this_thread::sleep_for(1s);
            }
        }
    });

    std::this_thread::sleep_for(10s);

    std::cout << "Tempo esgotado" << std::endl;

    bContinue = false;
    ProducerThread.join();
    CondVar.notify_all();
    ConsumerThread.join();

    return 0;
}
