//
// Created by me on 25-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> adj[100005];
bool v[100005]={false};

void bfs(ll n){
    queue<ll> qu;
    vector<ll> par(n+1,0);
    ll fg=0,cr;

    for(ll o=1;o<=n;o++) {
        if(v[o])continue;
        qu.push(o);
        v[o] = true;
        while (!qu.empty()) {
            ll curr = qu.front();
            qu.pop();
            for (auto adjc:adj[curr]) {
                if (!v[adjc]) {
                    v[adjc] = true;
                    qu.push(adjc);
                    par[adjc] = curr;
                } else {
                    fg = adjc;
                    cr = curr;
                    break;
                }
            }
            if (fg)break;
        }
        if (fg)break;
    }
    if(fg){
        vector<ll> ans;
        ans.push_back(fg);
        ans.push_back(cr);
        while(par[cr]!=fg){
            ans.push_back(par[cr]);
            cr=par[cr];
        }
        ans.push_back(fg);

        cout<<ans.size()<<endl;
        for(ll i=ans.size()-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }cout<<endl;
    }else{
        cout<<"IMPOSSIBLE\n";
    }


}
void soln(ll t){
    ll n,m,a,b;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(n);
}

int cc_main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



