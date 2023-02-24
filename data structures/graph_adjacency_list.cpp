#include <bits/stdc++.h>
#define ll long long
using namespace std;
class graph_adjl{
    vector<vector<ll>> adjl;
    ll n_node,n_edge;

public:
    graph_adjl(ll n_node,ll n_edge){
        this->n_node=n_node;
        this->n_edge=n_edge;
        adjl=vector<vector<ll>> (n_node+1);
    }

    void add_edge(ll x,ll y){
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }

    void edge_input(){
        ll x,y;
        cin>>x>>y;
        this->add_edge(x,y);
    }

    void print_adjl(){
        for(ll i=1;i<=n_node;i++){
            cout<<"node "<<i<<":";
            for(auto adj_node:adjl[i]){
                cout<<adj_node<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    graph_adjl graph(4,4);
    graph.add_edge(1,3);
    graph.add_edge(2,3);
    graph.add_edge(3,4);
    graph.add_edge(2,4);

    graph.print_adjl();
    return 0;
}
