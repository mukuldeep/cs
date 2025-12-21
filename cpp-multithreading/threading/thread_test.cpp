//
// Created by mukul on 21-12-2025.
//

#include "thread_test.h"

#include <iostream>
#include <thread>

void task() {
    std::cout << "Hello from the worker thread!" << std::endl;
}

int main() {
    // 1. Create a thread and give it a task
    std::thread t1(task);

    // 2. Wait for the thread to finish (joining)
    t1.join();

    // 2. detaches the thread from main thread
    //t1.detach();

    std::cout << "Back in the main thread." << std::endl;
    return 0;
}
