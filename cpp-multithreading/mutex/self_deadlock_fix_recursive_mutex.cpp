//
// Created by mukul on 06-01-2026.
//

#include <mutex>

std::recursive_mutex m;

void inner() {
    //it assumes to hold lock
}

void outer() {
    std::lock_guard<std::recursive_mutex> lock(m);
    inner();
}

int main() {
    outer();
}
