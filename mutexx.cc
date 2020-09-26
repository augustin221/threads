std::unique_lock<std::mutex> unique_lock_name(raw_mutex);
#include <mutex>
#include <vector>
std::mutex door; //объявление мьютекса
std::vector<int> v;
{
    std::unique_lock<std::mutex> ul(door);
    // Вызывается конструктор ul, эквивалентный door.lock();
    // ul, размещённый в стеке
    // гарантируется монопольное использование вектора

    door.unlock();

    // выполнение операций, не связанных с вектором
    // ....
    // теперь мне снова нужен доступ к вектору

    door.lock();
    //Снова гарантируется монопольное использование вектора
}