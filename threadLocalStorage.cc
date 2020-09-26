#include <iostream>
#include <mutex>
#include <thread>
#include <vector>


std::mutex io_mtx;
thread_local int counter = 0;
static const int MAX_COUNTER_VAL = 10;

void thread_proc(int tnum){
    for(;;){
        counter++;
        if(counter == MAX_COUNTER_VAL)
            break; 
            {
                std::lock_guard<std::mutex>lock(io_mtx);
                std::cout << "thread" << thum << "залупа" << counter << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main() {
    std::vector<std::thread> threads;
    for(int i = 0; i < 10; i++) {
        std::thread thr(thread_proc, i);
        threads.emplace_back(std::move(thr));
    }

    for(auto& thr : threads) {
        thr.join();
    }

    std::cout << "Done!" << std::endl;
    return 0;
}