//
// Created by mukul on 02-01-2026.
//

#include <iostream>
#include <thread>

int counter = 0; // Shared resource

void increment(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        counter++; // RACE CONDITION HAPPENS HERE
        std::cout << counter << " Th-id "<< std::this_thread::get_id() << std::endl;
    }
}

int main() {
    int iterations = 100;

    // Launch two threads to do the same task
    std::thread t1(increment, iterations);
    std::thread t2(increment, iterations);

    t1.join();
    t2.join();

    std::cout << "Expected: " << iterations * 2 << std::endl;
    std::cout << "Actual:   " << counter << std::endl;

    return 0;
}