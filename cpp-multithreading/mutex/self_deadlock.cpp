//
// Created by mukul on 04-01-2026.
//

#include <mutex>

std::mutex m;

void inner() {
    m.lock();      // DEADLOCK HERE
    m.unlock();
}

void outer() {
    m.lock();
    inner();       // same thread tries to lock again
    m.unlock();
}

int main() {
    outer();
}
