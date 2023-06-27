#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <atomic>
#include <numeric>
#include <vector>
#include <random>

int main(int argc, char const *argv[])
{
    std::cout << "Inicializando ... " << std::flush;
    const int N = 500'000'000;
    std::vector<int> Numbers(N, 0);
    std::cout << "Feito" << std::endl;

    std::cout << "Gerando numeros ... " << std::flush;
    std::random_device RandomDevice;
    std::uniform_int_distribution<> Distribution(0, 100);
    for (int& X : Numbers)
    {
        X = Distribution(RandomDevice);
    }
    std::cout << "Feito\n" << std::endl;

    using namespace std::chrono;
    using ClockT = high_resolution_clock;

    {
        std::cout << "Fazendo soma serial ... " << std::flush;
        ClockT::time_point StartTime = ClockT::now();
        const int Sum = std::accumulate(Numbers.begin(), Numbers.end(), 0);
        ClockT::time_point EndTIme = ClockT::now();
        std::cout << "Feito\n" << std::endl;
        nanoseconds Elapsed = EndTIme - StartTime;

        std::cout << "Serial" << std::endl;
        std::cout << "Soma  : " << Sum << std::endl;
        std::cout << "Tempo : " << duration_cast<milliseconds>(Elapsed).count() << " ms\n" << std::endl;
    }

    {
        std::cout << "Paralelo" << std::endl;
        for (int NumThreads = 1; NumThreads <= std::thread::hardware_concurrency(); NumThreads++)
        {
            std::atomic<int> Sum{ 0 };

            auto ThreadFunc = [&](int StartIndex, int EndIndex)
            {
                int LocalSum = 0;
                for (int I = StartIndex; I < EndIndex; I++)
                {
                    LocalSum += Numbers[I];
                }
                Sum += LocalSum;
            };

            std::vector<std::thread> Threads;

            ClockT::time_point StartTime = ClockT::now();

            const int NumbersPerThread = N / NumThreads;
            for (int ThreadId = 0; ThreadId < NumThreads; ThreadId++)
            {
                const int StartIndex = ThreadId * NumbersPerThread;
                int EndIndex = StartIndex + NumbersPerThread;

                if (ThreadId == NumThreads - 1)
                {
                    EndIndex = std::min(N, EndIndex);
                    EndIndex = std::max(N, EndIndex);
                }

                Threads.emplace_back(ThreadFunc, StartIndex, EndIndex);
            }

            for (std::thread& Thread : Threads)
            {
                Thread.join();
            }

            ClockT::time_point EndTime = ClockT::now();
            nanoseconds Elapsed = EndTime - StartTime;

            std::cout << "Soma: " << Sum
                      << " Threads: " << NumThreads
                      << " Tempo: " << duration_cast<milliseconds>(Elapsed).count() << " ms"
                      << std::endl;
        }
    }

    return 0;
}
