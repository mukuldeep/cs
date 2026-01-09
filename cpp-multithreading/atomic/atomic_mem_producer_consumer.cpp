//
// Created by mukul on 09-01-2026.
//

#include <iostream>
#include <thread>

#include<atomic>

std::atomic<bool> ready{false};
int data;

void producer() {
    std::cout << "Producer entry"<<"\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    data = 42;
    ready.store(true, std::memory_order_release);
}

void consumer() {
    std::cout << "Consumer entry"<<"\n";
    while (!ready.load(std::memory_order_acquire)) {}
    std::cout << "Consumed data: " << data << "\n";  // guaranteed to see 42
}



int main() {

    std::thread t1(consumer);
    std::thread t2(producer);

    t1.join();
    t2.join();

    return 0;
}
