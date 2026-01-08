//
// Created by mukul on 08-01-2026.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;

bool data_ready = false;
int data = 0;

void consumer()
{
    std::cout << "Consumer entry"<<"\n";
    std::unique_lock<std::mutex> lock(m);

    // Wait until data_ready == true
    cv.wait(lock, [] {
        return data_ready;
    });

    std::cout << "Consumed data: " << data << "\n";
}

void producer()
{
    std::cout << "Producer entry"<<"\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    {
        std::lock_guard<std::mutex> lock(m);
        data = 42;
        data_ready = true;
    }
    std::cout << "notifying consumer "<<"\n";
    cv.notify_one();  // wake one consumer
}



int main() {

    std::thread t1(consumer);
    std::thread t2(producer);

    t1.join();
    t2.join();

    return 0;
}
