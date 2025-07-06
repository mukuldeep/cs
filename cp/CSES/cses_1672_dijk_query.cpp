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
    for(ll i=0;i<n;i++) {
        vector<ll> d;
        d.assign(n, INF);
        d[i] = 0;
        using pii = pair<ll, ll>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, i});//putting node 0 as starting node

        while (!q.empty()) {
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



