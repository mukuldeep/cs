//
// Created by mukul on 27-12-2025.
//

#include <iostream>
#include <thread>

void task(int param) {
    std::cout << "Hello from the worker thread! with param = "<< param << std::endl;
}

int main() {
    // 1. Create a thread and give it a task
    std::thread t1(task, 42);

    // 2. Wait for the thread to finish (joining)
    t1.join();

    // 2. detaches the thread from main thread
    //t1.detach();

    std::cout << "Back in the main thread." << std::endl;
    return 0;
}
