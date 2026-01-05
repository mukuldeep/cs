//
// Created by mukul on 05-01-2026.
//

#include <iostream>
#include <thread>
#include <mutex>

std::mutex m1;
std::mutex m2;

void threadA() {
    std::lock_guard<std::mutex> lock1(m1);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::lock_guard<std::mutex> lock2(m2);  // lock in same order
    std::cout << "Thread A acquired both\n";
}

void threadB() {
    std::lock_guard<std::mutex> lock1(m1);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::lock_guard<std::mutex> lock2(m2);  // lock in same order
    std::cout << "Thread B acquired both\n";
}

int main() {
    std::thread t1(threadA);
    std::thread t2(threadB);

    t1.join();
    t2.join();
}

