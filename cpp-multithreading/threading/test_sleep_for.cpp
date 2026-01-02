//
// Created by mukul on 02-01-2026.
//

#include <iostream>
#include <thread>
#include <chrono>

void task( int seconds) {

    for(int i=0;i<5; i++) {
        std::cout << "Thread " << std::this_thread::get_id() << " started, sleeping for " << seconds << "s...\n";

        // Suspend ONLY this specific thread
        std::this_thread::sleep_for(std::chrono::seconds(seconds));

        std::cout << "Thread " << std::this_thread::get_id() << " woke up after " << seconds << "s!\n";
    }
}

int main() {
    using namespace std::chrono_literals;

    // Launch two threads with different sleep durations
    std::thread t1(task, 1); // Sleeps for 1 second
    std::thread t2(task, 3); // Sleeps for 3 seconds

    std::cout << "Main thread is still running and waiting...\n";

    // Wait for both threads to finish
    t1.join();
    t2.join();

    std::cout << "All threads completed.\n";
    return 0;
}