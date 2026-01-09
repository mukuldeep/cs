//
// Created by mukul on 09-01-2026.
//

#include <iostream>
#include "ThreadPool.h"

int task1(int num){
    return num;
}

int task2(int a, int b){
    return a+b;
}

int main() {
    ThreadPool pool(0);

    auto f1 = pool.enqueue(task1,42);
    auto f2 = pool.enqueue(task2, 10, 20);

    std::cout << f1.get() << std::endl;
    std::cout << f2.get() << std::endl;
}

