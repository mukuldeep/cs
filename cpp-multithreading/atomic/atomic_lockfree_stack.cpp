//
// Created by mukul on 09-01-2026.
//

#include <iostream>
#include <thread>

#include<atomic>

template<typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};


template<typename T>
class LockFreeStack {
private:
    std::atomic<Node<T> *> top;

public:
    LockFreeStack() : top(nullptr) {}

    void push(const T& value) {
        Node<T>* new_node = new Node<T>(value);

        // Loop until CAS succeeds
        do {
            new_node->next = top.load(std::memory_order_relaxed);
        } while (!top.compare_exchange_weak(
                new_node->next,   // expected
                new_node,         // desired
                std::memory_order_release,
                std::memory_order_relaxed
        ));
    }

    bool pop(T& result) {
        Node<T>* old_top = top.load(std::memory_order_relaxed);

        while (old_top) {
            if (top.compare_exchange_weak(
                    old_top,
                    old_top->next,
                    std::memory_order_acquire,
                    std::memory_order_relaxed
            )) {
                result = old_top->data;
                delete old_top;
                return true;
            }
        }
        return false;
    }
};



LockFreeStack<int> stack;

void consumer(){
    int value;
    int i=0;
    while(i<100){
        if(stack.pop(value)) {
            std::cout << "val:\t" << value << "\n";
            i++;
        }
    }
}

void producer(){
    for(int i=0;i<100;i++){
        std::cout<<"push:"<<i<<"\n";
        stack.push(i);
    }
}


int main() {

    std::thread t1(consumer);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::thread t2(producer);

    t1.join();
    t2.join();

    return 0;
}
