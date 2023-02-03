/*
Synchronizing data between multiple threads that run at the same time and access the same data is an important aspect of concurrent programming. In C++, you can use synchronization objects to ensure that data is accessed and modified safely by multiple threads.

Here are some of the synchronization objects that are provided by the C++ Standard Library:

- std::mutex: A mutex (short for "mutual exclusion") is a synchronization object that can be locked by one thread and unlocked by another. When a mutex is locked, any other threads that try to lock the same mutex will be blocked until it is unlocked. You can use a mutex to protect a critical section of code that accesses shared data.

- std::lock_guard: A std::lock_guard is a RAII (Resource Acquisition is Initialization) wrapper around a mutex. It locks the mutex in its constructor and unlocks it in its destructor. You can use a std::lock_guard to ensure that a mutex is always unlocked, even if an exception is thrown.

- std::unique_lock: A std::unique_lock is similar to a std::lock_guard, but it provides more flexibility. It can be used to lock and unlock a mutex multiple times, and it can be moved to another std::unique_lock object. You can use a std::unique_lock to lock a mutex in one function and unlock it in another.

- std::condition_variable: A condition variable is a synchronization object that can be used to wait for a condition to be met. You can use a condition variable in combination with a mutex to wait for a change in the shared data, and to notify other threads when the data has changed.

Here's an example that shows how to use a mutex and a condition variable to synchronize data between two threads:
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

int data = 0;
std::mutex data_mutex;
std::condition_variable data_cond;

void worker1() {
    while (true) {
        std::unique_lock<std::mutex> lock(data_mutex);
        data_cond.wait(lock, [] { return data != 0; });
        std::cout << "worker1: data = " << data << std::endl;
        data = 0;
        lock.unlock();
        data_cond.notify_one();
    }
}

void worker2() {
    while (true) {
        std::unique_lock<std::mutex> lock(data_mutex);
        data = 42;
        lock.unlock();
        data_cond.notify_one();
        std::unique_lock<std::mutex> lock2(data_mutex);
        data_cond.wait(lock2, [] { return data == 0; });
    }
}

int main() {
    std::thread t1(worker1);
    std::thread t2(worker2);
    t1.join();
    t2.join();

    return 0;
}

// or

#include <iostream>
#include <thread>
#include <mutex>

int data = 0;
std::mutex data_mutex;

void worker1() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(data_mutex);
        data += 1;
        std::cout << "worker1: data = " << data << std::endl;
        lock.unlock();
    }
}

void worker2() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(data_mutex);
        data += 1;
        std::cout << "worker2: data = " << data << std::endl;
        lock.unlock();
    }
}

int main() {
    std::thread t1(worker1);
    std::thread t2(worker2);
    t1.join();
    t2.join();

    return 0;
}


/*
In this example, two threads worker1 and worker2 access the shared variable data and synchronize their access using a mutex and a
*/