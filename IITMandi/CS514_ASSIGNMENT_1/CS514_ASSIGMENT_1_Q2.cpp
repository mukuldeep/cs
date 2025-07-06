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
void pre(){}

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
        } else {
            // BFS using queue and insert in the first empty location
            queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                Node* current = q.front();
                q.pop();

                if (!current->child1) {//if the first child is null
                    newNode -> parent = current;
                    current->child1 = newNode;
                    heapifyBottom2Up(current->child1);
                    break;
                } else {// otherwise insert into the processing queue
                    q.push(current->child1);
                }

                //same for second child
                if (!current->child2) {
                    newNode -> parent = current;
                    current->child2 = newNode;
                    heapifyBottom2Up(current->child2);
                    break;
                } else {
                    q.push(current->child2);
                }

                //same for third child
                if (!current->child3) {
                    newNode -> parent = current;
                    current->child3 = newNode;
                    heapifyBottom2Up(current->child3);
                    break;
                } else {
                    q.push(current->child3);
                }
            }
        }
    }

    // get and delete the minimum value from the min heap
    int deleteMin() {
        if (!root) {
            //throw std::runtime_error("Heap is empty");
            O "Heap is empty"<<El
        }

        int minValue = root->value;

        // If the root is the only node
        if (!root->child1 && !root->child2 && !root->child3) {
            delete root;
            root = nullptr;
        } else {
            queue<Node*> q;
            q.push(root);

            // traverse to the last node using BFS implemented using queue
            Node* lastNode = nullptr;
            while (!q.empty()) {
                lastNode = q.front();
                q.pop();

                if (lastNode->child1) q.push(lastNode->child1);
                if (lastNode->child2) q.push(lastNode->child2);
                if (lastNode->child3) q.push(lastNode->child3);
            }

            // Replace root value with last node's value
            root->value = lastNode->value;

            // Remove last node
            if (lastNode->parent->child1 == lastNode) {
                lastNode->parent->child1 = nullptr;
            } else if (lastNode->parent->child2 == lastNode) {
                lastNode->parent->child2 = nullptr;
            } else if (lastNode->parent->child3 == lastNode) {
                lastNode->parent->child3 = nullptr;
            }
            delete lastNode;

            heapifyTop2Down(root);
        }

        return minValue;
    }


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
    }
    F(i,n){
        O ternaryMinHeap.deleteMin()<<" ";
    }O El

}

Dr


/**
 *  TIME COMPLEXITY ANALYSIS
 *  1. Insertion of an element : O(n)
 *      finding position to insert new element using bfs is O(n) as traversing all the nodes exactly once
 *      inserting new node is O(1) as only changing a pointer in the existing heap
 *      heapify from  down to top to maintain min heap properties is O(log_3(n)) as we are traversing through atmost one node in each depth
 *      Total O(n)+O(1)+ O(log_3(n)) = O(n)
 *
 *   2. Deletion of an element : O(n)
 *      finding last position to delete element from using bfs is O(n) as traversing all the nodes exactly once
 *      swapping value with the root node is O(1) as constant operations are being performed
 *      heapify from root to down to maintain min heap properties is O(log_3(n)) as we are traversing through atmost one node in each depth
 *      where maximum depth can be Log_3(n) i.e. log n base 3
 *      Total O(n)+O(1)+ O(log_3(n)) = O(n)
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