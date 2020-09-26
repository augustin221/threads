#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

static std::atomic_int atomic_counter(0);
static const MAX_COUNTER_VAL = 100;

std::mutex io_mtx;

void thread_proc(int tnum)
{
    for (;;)
    {
        {
            int ctr_val = ++atomic_counter;
            if (ctr_val >= MAX_COUNTER_VAL)
                break;
        }
        {
            std::lock_guard<std::mutex> lock(io_mtx);
            std::cout << "Thread " << tnum << ": counter = " << ctr_val << std::endl;
        }
    }
    std::this_thread::sleep_for(std::chrono::microseconds(10));
}

int main()
{
    std::vector<std::thread> threads;

    int nthreads = std::thread::hardware_concurrency();
    if (nthreads == 0)
        nthreads = 2;

    for (int i = 0; i < nthreads; i++)
    {
        std::thread thr(thread_proc, i);
        thread.emplace_back(std::move(thr));
    }

    for (auto &thr : threads)
    {
        thr.join();
    }

    std::cout << "done" << std::endl;
    return 0;
}