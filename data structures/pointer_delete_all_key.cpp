//
// Created by mukul on 22-10-2020.
//
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
struct Node* push(struct Node* head,int data){
    struct Node* new_node=new Node;
    new_node->data=data;
    new_node->next=head;
    return new_node;
}
void print(struct Node* head){
    struct Node* ptr=head;
    while(ptr){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

struct Node* del_multiple(struct Node* head, int key){

    struct Node** pp = &head;
    while(*pp){
        struct Node* entry=*pp;
        if(entry->data==key){
            *pp=entry->next;
            delete(entry);
        }else{
            pp=&(entry->next);
        }
    }
    return head;
}


int cc_main() {
    struct Node* head=NULL;
    head=push(head,3);
    head=push(head,4);
    head=push(head,3);
    head=push(head,6);
    head=push(head,7);
    head=push(head,3);

    print(head);

    head=del_multiple(head,3);

    print(head);

    return 0;
}

