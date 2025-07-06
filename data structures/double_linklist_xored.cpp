//
// Created by mukul on 22-10-2020.
//
#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* npx;
};
node *XOR_ADD(node* a,node* b){
    return reinterpret_cast<node *>(
            reinterpret_cast<uintptr_t>(a) ^
            reinterpret_cast<uintptr_t>(b));
}
void print(node *head){
    node *curr=head,*prev=NULL,*next;

    while(curr!=NULL){
        cout<<curr->data<<" ";
        next=XOR_ADD(curr->npx,prev);
        prev=curr;
        curr=next;
    }
}
node* insert(node **head,int data){
       node* ptr=new node();
       ptr->data=data;

       ptr->npx=*head;

       if(*head!=NULL){
           (*head)->npx=XOR_ADD((*head)->npx,ptr);
       }
       (*head)->npx=ptr;

    return *head;
}
int cc_main() {
    node* head=NULL;
    head=insert(&head,3);
    head=insert(&head,4);
    head=insert(&head,3);
    head=insert(&head,6);
    head=insert(&head,7);
    head=insert(&head,3);


    print(head);

    return 0;
}

