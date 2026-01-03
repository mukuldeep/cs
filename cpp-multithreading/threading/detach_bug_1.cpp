//
// Created by mukul on 03-01-2026.
//

#include <iostream>
#include <thread>

int counter = 0;

void increment(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        counter++;
        std::cout << counter << " Th-id "<< std::this_thread::get_id() << std::endl;
    }
}

void start() {
    int x = 42;
    std::thread t([&]() {
        for(int i=0;i<100;i++) {
            std::cout << " Th-id "<< std::this_thread::get_id() <<" => "<< x << "\n";  // dangling reference of x
        }
    });
    t.detach();
}


int main() {
    start();

    int iterations = 100;
    std::thread t1(increment, iterations);
    t1.join();

    return 0;
}