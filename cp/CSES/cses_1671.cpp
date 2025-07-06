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
    vector<bool> u(n, false);
    d.assign(n,INFINITY);
    d[0]=0;
    for(ll i=0;i<n;i++){
        int v=-1;
        //choosing the smallest unmarked graph
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        //if none other than infinity found
        if (d[v] == INFINITY)
            break;

        u[v] = true;//mark the current node

        //iterate through the edges from the current node
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
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



