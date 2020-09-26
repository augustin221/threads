#include <iostream>
#include <thread>
#include <vector>
#include <shared_mutex>
#include <atlsimpcoll.h>
std::shared_timed_mutex mtx;

static int counter = 0;
static const int MAX_COUNTER_VAL = 100;

void thread_proc(int tnum)
{
    for (;;)
    {
        {
            // see also std::shared_lock
            std::unique_lock<std::shared_timed_mutex> lock(mtx);
            if (counter == MAX_COUNTER_VAL)
                break;
            int ctr_val = ++counter;
            std::cout << "Thread " << tnum << ": counter = " << ctr_val << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; i++)
    {
        threads.emplace_back(std::move(thr));
    }
    for (auto &thr : threads)
    {
        thr.join();
    }

    std::cout << "done" << std::endl;
    return 0;
}