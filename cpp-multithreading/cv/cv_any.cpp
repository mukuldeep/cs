//
// Created by mukul on 08-01-2026.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::recursive_mutex rm;
std::condition_variable_any cv;
bool done = false;

void wait_task()
{
    std::unique_lock<std::recursive_mutex> lock(rm);
    cv.wait(lock, [] {
        return done;
    });
}

void signal_task()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::recursive_mutex> lock(rm);
        done = true;
    }
    cv.notify_one();
}



int main() {

    std::thread t1(wait_task);
    std::thread t2(signal_task);

    t1.join();
    t2.join();

    return 0;
}
