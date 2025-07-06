//
// Created by mukul on 12-11-2020.
//
#include <bits/stdc++.h>
using namespace std;
class minheap{
        int *heap_array;
        int heap_size;
        int capacity;
public:
    minheap(int cap){
        heap_array=new int[capacity];
        capacity=cap;
        heap_size=0;
    }
    void insert(int val);
    int parent(int i){return (i-1)/2;}
    int left_child(int i){return i*2+1;}
    int right_child(int i){return i*2+2;}

    int get_min() { return heap_array[0]; }
    void decrease_val(int i, int new_val);
    int extract_min();
    void min_heapify(int i);
    void del_value(int i);

};

void minheap::insert(int val) {
    if(heap_size>=capacity){
        cout<<"Overflow: No more element can be inserted!";
        return;
    }

    heap_size++;
    int i=heap_size-1;
    heap_array[i]=val;

    while(i && heap_array[i]<heap_array[parent(i)]){
        swap(heap_array[i],heap_array[parent(i)]);
        i=parent(i);
    }

}

void minheap::decrease_val(int i, int new_val) {
    heap_array[i]=new_val;
    while(i && heap_array[i]<heap_array[parent(i)]){
        swap(heap_array[i],heap_array[parent(i)]);
        i=parent(i);
    }
}

int minheap::extract_min(){
    if(heap_size<=0){
        return INT_MAX;
    }
    if(heap_size==1){
        heap_size--;
        return heap_array[0];
    }

    int root=heap_array[0];
    heap_array[0]=heap_array[heap_size-1];
    heap_size--;
    min_heapify(0);

    return root;
}
void minheap::min_heapify(int i) {
    int smallest=i;
    int l=left_child(i);
    int r=right_child(i);

    if(l<heap_size && heap_array[l]<heap_array[smallest])smallest=l;
    if(r<heap_size && heap_array[r]<heap_array[smallest])smallest=r;

    if(smallest!=i){
        swap(heap_array[i],heap_array[smallest]);
        min_heapify(smallest);
    }
}
void minheap::del_value(int i) {
    decrease_val(i,INT_MIN);
    extract_min();
}


int cc_main() {
    minheap h(10);
    h.insert(3);
    h.insert(2);
    h.del_value(1);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);
    cout << h.extract_min() << " ";
    cout << h.get_min() << " ";
    h.decrease_val(2, 1);
    cout << h.get_min();
    return 0;
}

