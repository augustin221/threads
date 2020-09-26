#include <mutex>
#include <queue>

class threadsSafe_queue
{
    std::queue<int> rawQueue;
    std::mutex m;

public:
    int &RetrieAndDelete()
    {
        int frontVlaue = 0;
        m.lock();

        if (!rawQueue.empty())
        {
            frontVlaue = rawQueue.front();
            rawQueue.pop();
        }
        m.unlock();

        return frontVlaue;
    }
};

void push(int val)
{
    m.lock();
    rawQueue.push(val);
    m.unlock();
}