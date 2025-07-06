//
// Created by me on 03-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
class node{
public:
    node *l;
    node *r;
    ll val;
    ll h;
    ll cnt;

};
int height(node *N)
{
    if (N == NULL)
        return 0;
    return N->h;
}
node* new_node(ll key){
    node* n=new node();
    n->val=key;
    n->l=NULL;
    n->r=NULL;
    n->h=1;
    n->cnt=1;
    return n;
}
void preOrder(node *root)
{
    if(root != NULL)
    {
        cout << root->val << " ";
        preOrder(root->l);
        preOrder(root->r);
    }
}
int getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->l) - height(N->r);
}
node *rightRotate(node *y)
{
    node *x = y->l;
    node *T2 = x->r;

    x->r = y;
    y->l = T2;

    y->h = max(height(y->l),height(y->r)) + 1;
    x->h = max(height(x->l),height(x->r)) + 1;
    return x;
}

node *leftRotate(node *x)
{
    node *y = x->r;
    node *T2 = y->l;

    y->l = x;
    x->r = T2;

    x->h = max(height(x->l),height(x->r)) + 1;
    y->h = max(height(y->l),height(y->r)) + 1;

    return y;
}
node* insert(node* nd, int key)
{
    if (nd== NULL)
        return(new_node(key));

    if (key < nd->val)
        nd->l = insert(nd->l, key);
    else if (key > nd->val)
        nd->r = insert(nd->r, key);
    else {
        nd->cnt++;
        return nd;
    }
    nd->h = 1 + max(height(nd->l),height(nd->r));

    int balance = getBalance(nd);

    // Left Left Case
    if (balance > 1 && key < nd->l->val)
        return rightRotate(nd);

    // Right Right Case
    if (balance < -1 && key > nd->r->val)
        return leftRotate(nd);

    // Left Right Case
    if (balance > 1 && key > nd->l->val)
    {
        nd->l = leftRotate(nd->l);
        return rightRotate(nd);
    }

    // Right Left Case
    if (balance < -1 && key < nd->r->val)
    {
        nd->r = rightRotate(nd->r);
        return leftRotate(nd);
    }
    return nd;
}

/* Given a non-empty binary search tree,
return the node with minimum key value
found in that tree. Note that the entire
tree does not need to be searched. */
node * minValueNode(node* nod)
{
    node* current = nod;

    /* loop down to find the leftmost leaf */
    while (current->l != NULL)
        current = current->l;

    return current;
}

// Recursive function to delete a node
// with given key from subtree with
// given root. It returns root of the
// modified subtree.
node* deleteNode(node* root, int key)
{

    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL) {
        return root;
    }

    // If the key to be deleted is smaller
    // than the root's key, then it lies
    // in left subtree
    if ( key < root->val ) {
        root->l = deleteNode(root->l, key);
    }

        // If the key to be deleted is greater
        // than the root's key, then it lies
        // in right subtree
    else if( key > root->val )
        root->r = deleteNode(root->r, key);

        // if key is same as root's key, then
        // This is the node to be deleted
    else
    {   if(root->cnt>1){
            root->cnt--;
            return root;
        }else{
            // node with only one child or no child
            if ((root->l == NULL) ||
                (root->r == NULL)) {
                node *temp = root->l ? root->l : root->r;

                // No child case
                if (temp == NULL) {
                    temp = root;
                    root = NULL;
                } else // One child case
                    *root = *temp; // Copy the contents of
                // the non-empty child
                free(temp);
            } else {
                // node with two children: Get the inorder
                // successor (smallest in the right subtree)
                node *temp = minValueNode(root->r);

                // Copy the inorder successor's
                // data to this node
                root->val = temp->val;

                // Delete the inorder successor
                root->r = deleteNode(root->r,
                                     temp->val);
            }
        }
    }

    // If the tree had only one node
    // then return
    if (root == NULL)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->h = 1 + max(height(root->l),
                           height(root->r));

    // STEP 3: GET THE BALANCE FACTOR OF
    // THIS NODE (to check whether this
    // node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced,
    // then there are 4 cases

    // Left Left Case
    if (balance > 1 &&
        getBalance(root->l) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 &&
        getBalance(root->l) < 0)
    {
        root->l = leftRotate(root->l);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 &&
        getBalance(root->r) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 &&
        getBalance(root->r) > 0)
    {
        root->r = rightRotate(root->r);
        return leftRotate(root);
    }

    return root;
}

node* search_n_del(node* root, node* nd,ll key){
    if(nd==NULL){
        cout<<-1<<endl;
        return root;
    }
    if(nd->val==key){
        cout<<nd->val<<endl;
        //del nd
        if(nd->cnt>1)
            nd->cnt--;
        else
            root=deleteNode(root,nd->val);
    }else if(nd->val<key){
        if(nd->r){
            if(nd->r->val>key){
                cout<<nd->val<<endl;

                //del nd
                if(nd->cnt>1)
                    nd->cnt--;
                else
                    root=deleteNode(root,nd->val);
            }else{
                root=search_n_del(root,nd->r,key);
            }
        }else{
            cout<<nd->val<<endl;
            //del nd
            if(nd->cnt>1)
                nd->cnt--;
            else
                root=deleteNode(root,nd->val);
        }
    }else{
        root=search_n_del(root,nd->l,key);
    }
    return root;
}
ll findMaxforN(node* root, ll N)
{
    // Base cases
    if (root == NULL)
        return -1;
    if (root->val == N) {
        return N;
    }

        // If root's value is smaller, try in rght
        // subtree
    else if (root->val < N) {
        int k = findMaxforN(root->r, N);
        if (k == -1)
            return root->val;
        else
            return k;
    }

        // If root's key is greater, return value
        // from left subtree.
    else if (root->val > N)
        return findMaxforN(root->l, N);
}
void soln(ll t){
    ll n,m,x,cnt,a,index;
    node *root=NULL;
    cin>>n>>m;
    for(ll i=0;i<n;i++) {
        cin >> a;
        root=insert(root,a);
//        preOrder(root);
//        cout<<endl;
    }
    for(ll i=0;i<m;i++) {
        cin >> a;
        //root=search_n_del(root,root,a);
        ll xx=findMaxforN(root,a);
        cout<<xx<<endl;
        if(xx!=-1){
            root=deleteNode(root,xx);
        }

//        preOrder(root);
//        cout<<endl;
    }
}

int cc_main() {
//    freopen("./inout/test_output.txt", "a", stdout);
//    freopen("./inout/test_input.txt", "r", stdin);
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



