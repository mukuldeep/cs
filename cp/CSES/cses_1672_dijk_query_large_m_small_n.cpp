//
// Created by me on 21-03-2021.
//
#include <bits/stdc++.h>
#define ll long long

using namespace std;
void soln(ll t){
    ll  INF=LONG_LONG_MAX-10000000;
    ll n,m,a,b,c,q;
    cin>>n>>m>>q;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(ll i=0;i<m;i++){
        cin>>a>>b>>c;
        adj[a-1].push_back(make_pair(b-1,c));
        adj[b-1].push_back(make_pair(a-1,c));
    }

    vector<vector<ll>> dist;
    for(ll x=0;x<n;x++) {
        vector<ll> d;
        d.assign(n, INF);
        d[x] = 0;
        set<pair<int, int>> q;
        q.insert({0, x});
        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());

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
        dist.push_back(d);
    }

    for(ll i=0;i<q;i++){
        cin>>a>>b;
        a--;b--;
        ll a2b,b2a;
        a2b=dist[a][b];
        b2a=dist[b][a];
        if(a2b==INF && b2a==INF){
            cout<<-1<<endl;
        }else{
            cout<<min(a2b,b2a)<<endl;
        }
    }
}

int main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



