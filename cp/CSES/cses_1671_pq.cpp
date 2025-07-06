//
// Created by me on 21-03-2021.
//
#include <bits/stdc++.h>
#define ll long long

using namespace std;
void soln(ll t){
    ll  INF=LONG_LONG_MAX-10000000;
    ll n,m,a,b,c;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(ll i=0;i<m;i++){
        cin>>a>>b>>c;
        adj[a-1].push_back(make_pair(b-1,c));
    }

    vector<ll> d;
    d.assign(n,INF);
    d[0]=0;
    using pii = pair<ll, ll>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 0});//putting node 0 as starting node

    while(!q.empty()){
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;
        //iterate through the edges from the current node
        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.push({d[to], to});
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



