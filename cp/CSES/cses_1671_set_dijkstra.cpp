//
// Created by me on 21-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void soln(ll t){
    ll n,m,a,b,c;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(ll i=0;i<m;i++){
        cin>>a>>b>>c;
        adj[a-1].push_back(make_pair(b-1,c));
    }

    vector<ll> d;
    d.assign(n,INFINITY);
    d[0]=0;
    set<pair<int, int>> q;
    q.insert({0, 0});//putting node 0 as starting node

    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());
        //iterate through the edges from the current node
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }

    }

    for(ll i=0;i<n;i++){
        cout<<d[i]<<" ";
    }cout<<endl;


}

int main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



