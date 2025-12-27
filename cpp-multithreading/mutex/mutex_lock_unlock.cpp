//
// Created by mukul on 27-12-2025.
//

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int counter = 0; // Shared resource

void increment(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        mtx.lock();
        counter++; // RACE CONDITION HAPPENS HERE
        mtx.unlock();
    }
}

int main() {
    int iterations = 100000;

    // Launch two threads to do the same task
    std::thread t1(increment, iterations);
    std::thread t2(increment, iterations);

    t1.join();
    t2.join();

    std::cout << "Expected: " << iterations * 2 << std::endl;
    std::cout << "Actual:   " << counter << std::endl;

    return 0;
}
