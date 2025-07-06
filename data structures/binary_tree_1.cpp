//
// Created by mukul on 22-10-2020.
//
#include <bits/stdc++.h>
using namespace std;
struct node{
    int value;
    struct node* left;
    struct node* right;

    node(int d){
        value=d;
        left=NULL;
        right=NULL;
    }
};

int cc_main() {
    struct node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);

    return 0;
}

