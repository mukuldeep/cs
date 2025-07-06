/*
 * Created by mukul on 03-09-2024.
 */
#include <bits/stdc++.h>
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1;  //I t;
#define Dr int main(){Sync W(t)soln(t);return 0;}
#define Drt int cc_main(){Sync W(t)soln(t);return 0;}
#define F(a,c) for (ll a=0;a<c; a++)
#define Fe(a,c) for(ll a=0;a<=c; a++)
#define Fi(i,s,e) for(ll i=s;i<e;i++)
#define Rfi(i,s,e) for(ll i=s;i>e;i--)
#define Fa(xx,xxs) for(auto xx:xxs)
#define Srt(x) sort(x.begin(),x.end());
#define Rsrt(x) sort(x.rbegin(),x.rend());
#define Rev(x) reverse(x.begin(),x.end());
#define W(n) while(n--)
#define Wh while
#define Il while(1)
#define Pb push_back
#define O cout<<
#define Prcn fixed<<setprecision(20)
#define I cin>>
#define El endl;
//ds
#define ll long long
#define ld long double
#define S string
#define Ch char
#define V(x) vector<x>
#define Vv(x) V(V(x))
#define Sk(x) stack<x>
#define St(x) set<x>
#define Q(x) queue<x>
#define Dq(x) deque<x>
#define P(x) pair<x,x>
#define P2(x,y) pair<x,y>
#define Mp(x,y) map<x,y>
#define Uom(x,y) unordered_map<x,y>

//functions
#define p_bin(x) if(x)O "YES"<<El else O "NO"<<El

//constants
#define t9p7 1000000007
#define INF 100000000000000000 //1e17
using namespace std;

void pre(){

}


struct Node {
    int value;
    Node* parent;
    Node* child1;
    Node* child2;
    Node* child3;

    Node(int val) {
        value = val;
        parent = nullptr;
        child1 = nullptr;
        child2 = nullptr;
        child3 = nullptr;
    }
};

class TernaryMinHeap {
private:
    Node *root;
    deque<Node*> deque;

    // heapify up restores min-heap property after insertion of new element
    // bottom to Top : starts from the leaf node where new element just been inserted
    void heapifyBottom2Up(Node* node) {
        if (!node || !node->parent) return;
        if (node->value < node->parent->value) { // as parent value should be smaller in case of min heap
            swap(node->value, node->parent->value);
            heapifyBottom2Up(node->parent);
        }
    }

    //heapify down restores min-heap property after deletion of the min element from the root
    // Top to down: starts from root node after deletion
    void heapifyTop2Down(Node* node) {
        if (!node) return;

        Node* smallest = node;
        // comparing current node with first child, if first child is smaller then update smallest pointer to the child node
        if (node->child1 && node->child1->value < smallest->value) {
            smallest = node->child1;
        }
        if (node->child2 && node->child2->value < smallest->value) { // same as done in case of child1
            smallest = node->child2;
        }
        if (node->child3 && node->child3->value < smallest->value) { // same as done in case of child1
            smallest = node->child3;
        }

        // if any one of the child is smaller then swap current node with the child node and recurse for the child node
        if (smallest != node) {
            swap(node->value, smallest->value);
            heapifyTop2Down(smallest);
        }
    }


public:
    TernaryMinHeap(){
        root = nullptr;
    }

    // Function to insert a new value in the heap
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!root) { // no element present
            root = newNode;
            deque.push_back(root);
        } else {
            // node to push new node
            Node* current = deque.front();
            if (!current->child1) {
                newNode->parent = current;
                current->child1 = newNode;
                deque.push_back(current->child1);
                heapifyBottom2Up(current->child1);
            }else if (!current->child2) {
                newNode->parent = current;
                current->child2 = newNode;
                deque.push_back(current->child2);
                heapifyBottom2Up(current->child2);
            }else if (!current->child3) {
                newNode->parent = current;
                current->child3 = newNode;
                deque.push_back(current->child3);
                heapifyBottom2Up(current->child3);
                deque.pop_front();
            }
        }
    }

    // get and delete the minimum value from the min heap
    int deleteMin() {
        if (!root) {
            O "Heap is empty"<<El
        }

        int minValue = root->value;

        // If the root is the only node
        if (!root->child1 && !root->child2 && !root->child3) {
            delete root;
            deque.pop_back();
            root = nullptr;
        } else {

            // finding node to swap with
            Node* lastNode = deque.back();
            Node* lastNodeParent = lastNode -> parent;

            //swap value with root node
            root->value = lastNode->value;

            //delete last node currently having value same as root earlier
            if(lastNodeParent->child1 == lastNode){
                lastNodeParent->child1 = nullptr;
            }else if(lastNodeParent->child2 == lastNode){
                lastNodeParent->child2 = nullptr;
            }else if(lastNodeParent->child3 == lastNode){
                lastNodeParent->child3 = nullptr;
            }
            delete lastNode;

            // deleting from the queue
            deque.pop_back();
            //O "deQueue popbacked "<<El

            //heapify top to down for the new value  in the root
            heapifyTop2Down(root);

        }

        return minValue;
    }

//    //get the minimum value without removing it
//    int getMin() const {
//        if (!root) {
//            O "HEAP is Empty"<<El
//        }
//        return root->value;
//    }

};

void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    //S str;
    //I n;
    n = 15;
    V(ll) arr = {167,125,96,835,35,98,921,436,362,284,6593,8453,234,54,23};

    TernaryMinHeap ternaryMinHeap;

    Fa(xx,arr){
        ternaryMinHeap.insert(xx);
        O "inserted:"<<xx<<El
    }
    F(i,n){
        O ternaryMinHeap.deleteMin()<<" ";
    }O El

}

Dr

/**
 *  TIME COMPLEXITY ANALYSIS
 *  1. Insertion of an element : O(log_3(n))
 *      finding node to insert new element in DeQueue is O(3)=O(1) as checking all three nodes atmost once in the node at the front of the dequeue
 *      inserting new node is O(1) as only changing a pointer in the existing heap
 *      heapify from  down to top to maintain min heap properties is O(log_3(n)) as we are traversing through atmost one node in each depth
 *      Total O(1)+O(1)+O(log_3(n)) = O(log_3(n))
 *
 *   2. Deletion of an element : O(log_3(n))
 *      finding last node to delete element from the Dequeue is O(1) as its the node in the back of the dequeue
 *      swapping value with the root node is O(1) as constant operations are being performed
 *      heapify from root to down to maintain min heap properties is O(log_3(n)) as we are traversing through atmost one node in each depth
 *      where maximum depth can be Log_3(n) i.e. log n base 3
 *      Total O(1)+O(1)+O(log_3(n)) = O(log_3(n))
 *
 */

/**
 *  HOW TO RUN
 *  1. Consider soln() as main function for the program
 *  change iff any changes in test cases are required
 *
 */

/**
 * Problem statement
 * Devise a ternary heap which supports insertion and delete minima operations. Use linked lists for the implementation. Arrays cannot be used for
 * this problem.
 *
 */