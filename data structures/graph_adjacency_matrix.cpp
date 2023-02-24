#include <bits/stdc++.h>
#define ll long long
using namespace std;
class graph_adjm{
    vector<vector<ll>> adjm;
    ll n_node,n_edge;

public:
    graph_adjm(ll n_node,ll n_edge){
        this->n_node=n_node;
        this->n_edge=n_edge;
        adjm=vector<vector<ll>> (n_node+1,vector<ll>(n_node+1,0));
    }

    void add_edge(ll x,ll y){
        adjm[x][y]=1;
        adjm[y][x]=1;
    }

    void edge_input(){
        ll x,y;
        cin>>x>>y;
        this->add_edge(x,y);
    }

    void print_adjl(){
        for(ll i=1;i<=n_node;i++){
            for(ll j=1;j<=n_node;j++){
                cout<<adjm[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
};

int main() {
    graph_adjm graph(4,4);
    graph.add_edge(1,3);
    graph.add_edge(2,3);
    graph.add_edge(3,4);
    graph.add_edge(2,4);

    graph.print_adjl();
    return 0;
}
