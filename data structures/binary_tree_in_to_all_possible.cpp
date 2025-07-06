//
// Created by mukul on 3-11-2020.
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

vector<node *> in_to_all_tree(int in[],int start,int end){

    vector<node *> trees;
        if(start>end){
            trees.push_back(NULL);
            return trees;
        }

        for(int mid=start;mid<=end;mid++) {
            vector<node *> ltrees=in_to_all_tree(in,start,mid-1);
            vector<node *> rtrees=in_to_all_tree(in,mid+1,end);
            for(int l=0;l<ltrees.size();l++){
                for(int r=0;r<rtrees.size();r++){
                    node* curr_node=new node(in[mid]);
                    curr_node->left=ltrees[l];
                    curr_node->right=rtrees[r];
                    trees.push_back(curr_node);
                }
            }

        }
    return trees;
}

// A utility function to do preorder traversal of BST
void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}
// A utility function to do postorder traversal of BST
void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
}
// A utility function to do inorder traversal of BST
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

int cc_main() {

    int size=5;
    int in[]={1,2,3,4,5};

    vector<node *> trees;
    trees=in_to_all_tree(in,0,size-1);


    for(int i=0;i<trees.size();i++){
        preorder(trees[i]);
        cout<<endl;
        inorder(trees[i]);
        cout<<endl;
        postorder(trees[i]);
        cout<<endl;
        cout<<endl;

    }
    return 0;
}

