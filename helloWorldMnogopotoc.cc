#include <iostream>
#include <thread>

void hello()
{
    std::cout << "дарова конурент ворлд";
}

int main()
{
    std::thread t(hello);
    t.join();
}