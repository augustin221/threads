#include <iostream>
#include <string>
#include <thread>

void runA(bool &value, int i)
{
    if (value)
    {
        std::string out = "[" + std::to_string(i) + "] value, вова пидар" + std::to_string(value) + "\n";
        std::cout << out;
    }
}

void runB(bool &value)
{
    bool value = true;
}

int main()
{
    for (int i = 0; i < 20; i++)
    {
        bool value = true;
        std::thread tA(runA, std::ref(value), i);
        std::thread tB(runB, std::ref(value));
        tA.join();
        tB.join();
    }
}