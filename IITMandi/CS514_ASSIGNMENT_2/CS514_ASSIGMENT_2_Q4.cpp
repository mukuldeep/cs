/*
 * Created by mukul on 01-10-2024.
 */
#include <bits/stdc++.h>
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1; // I t;
#define Dr int main(){Sync W(t)soln(t);return 0;}
#define W(n) while(n--)
//ds
#define ll long long

using namespace std;

void pre(){

}

enum Color {RED, BLACK};

struct Node {
    ll data;
    bool color;
    Node *left, *right, *parent;
    int size;

    Node(int data){
        this->data = data;
        left = right = parent = nullptr;
        this->color = RED;
        this->size = 1;
    }
};

class RBTree{
private:
    Node *root;

    void updateSize(Node *x){
        if(x)
            x->size = 1 + size(x->left) + size(x->right);
    }

    int size(Node *x){
        return (x == nullptr) ? 0 : x->size;
    }

    // left  rotate
    void leftRotate(Node *&root, Node *&x){
        Node *y = x->right;
        x->right = y->left;
        if(x->right != nullptr)
            x->right->parent = x;

        y->parent= x->parent;
        if(x->parent== nullptr){
            root = y;
        }else if(x == x->parent->left){
            x->parent->left = y;
        }else{
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;

        updateSize(x);
        updateSize(y);
    }

    // right rotate
    void rightRotate(Node *&root,Node *&x){
        Node *y =x->left;
        x->left =y->right;
        if(x->left != nullptr){
            x->left->parent = x;
        }
        y->parent =x->parent;
        if(x->parent == nullptr){
            root = y;
        }else if(x == x->parent->left){
            x->parent->left = y;
        }else{
            x->parent->right = y;
        }
        y->right = x;
        x->parent = y;

        updateSize(x);
        updateSize(y);
    }

    // Fix  insert violation of rbtree conditions
    void fix_violation(Node *&root, Node *&x){
        Node *parent_x=nullptr;
        Node *grand_parent_x=nullptr;

        while((x != root) &&(x->color != BLACK) &&(x->parent->color == RED)){

            parent_x = x->parent;
            grand_parent_x = x->parent->parent;

            /* Case : A Parent of x is left child of Grand-parent of x */
            if(parent_x == grand_parent_x->left){
                Node *uncle_x = grand_parent_x->right;
                /* Case : 1 The uncle of x is also red Only Recoloring required */
                if(uncle_x != nullptr && uncle_x->color == RED){
                    grand_parent_x->color = RED;
                    parent_x->color = BLACK;
                    uncle_x->color = BLACK;
                    x = grand_parent_x;
                }else{
                    /* Case : 2 x is right child of its parent Left-rotation required */
                    if(x == parent_x->right){
                        leftRotate(root, parent_x);
                        x = parent_x;
                        parent_x = x->parent;
                    }

                    /* Case : 3 x is left child of its parent Right-rotation required */
                    rightRotate(root, grand_parent_x);
                    swap(parent_x->color, grand_parent_x->color);
                    x = parent_x;
                }
            }else{ /* Case : B Parent of x is right child of Grand-parent of x */
                Node *uncle_x = grand_parent_x->left;
                if(uncle_x != nullptr && uncle_x->color == RED){/* Case : 1 The uncle of x is also red Only Recoloring required */
                    grand_parent_x->color = RED;
                    parent_x->color = BLACK;
                    uncle_x->color = BLACK;
                    x = grand_parent_x;
                }else{
                    if(x ==parent_x->left){/* Case : 2 x is left child of its parent Right-rotation required */
                        rightRotate(root, parent_x);
                        x = parent_x;
                        parent_x = x->parent;
                    }

                    /* Case : 3 x is right child of its parent Left-rotation required */
                    leftRotate(root, grand_parent_x);
                    swap(parent_x->color, grand_parent_x->color);
                    x = parent_x;
                }
            }
        }

        root->color = BLACK;
    }

    int rank(Node* node, int x){
        if(node == nullptr)
            return -1;

        if(x == node->data)
            return size(node->left) + 1;

        if(x < node->data)
            return rank(node->left, x);
        else{
            int rightRank = rank(node->right, x);
            if(rightRank == -1)
                return -1;
            return size(node->left) + 1 + rightRank;
        }
    }

    int select(Node *node, int i){
        if(node == nullptr)
            return -1;

        int leftSize = size(node->left);

        if(i == leftSize + 1)
            return node->data;
        else if(i <= leftSize)
            return select(node->left, i);
        else
            return select(node->right, i - leftSize - 1);
    }

    // insert a new node with given key in BST
    Node* BSTInsert(Node* root, Node *pt){
        if(root==nullptr)
            return pt;

        if(pt->data<root->data){
            root->left = BSTInsert(root->left, pt);
            root->left->parent = root;
        }else if(pt->data > root->data){
            root->right = BSTInsert(root->right, pt);
            root->right->parent = root;
        }
        updateSize(root);
        return root;
    }


public:
    RBTree(){ root = nullptr; }

    // insert a new node with given data
    void insert(const int &data){
        Node *node = new Node(data);
        root = BSTInsert(root, node);
        fix_violation(root, node);
    }

    // Returns rank of an element x
    int rank(int x){
        return rank(root, x);
    }

    // Returns element with i-th rank
    ll select(int i){
        return select(root, i);
    }


};



void soln(ll t){

    RBTree tree;


    tree.insert(17);
    tree.insert(28);
    tree.insert(43);
    tree.insert(53);
    tree.insert(93);

    tree.insert(1);
    tree.insert(5);
    tree.insert(7);
    tree.insert(10);
    tree.insert(15);


    cout << "Rank of "<<28<<": " << tree.rank(28) << endl;
    cout << "Element with rank "<<5<<": " << tree.select(5) << endl;

}

Dr


/**
 * Problem statement
 *  Construct a red-black tree T which supports the following operations
 *  (a) Insert(x):- Inserts x in the T
 *  (b) Rank(x) :- Returns rank of x if x is present in T, else returns -1.
 *  (c) Select(i) :- Returns the element x from T which has exactly i − 1
 *  elements smaller than itself in T, otherwise if such an element does
 *  not exist return -1.
 *
 */


/**
 *  HOW TO RUN
 *  1. Consider soln() as main function for the program
 *  change iff any changes in test cases are required
 *
 */
