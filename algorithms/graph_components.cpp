//
// Created by me on 03-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> adj[100005];
bool v[100005]={false};
vector<ll> local;
vector<vector<ll>> comps;

void dfs(ll vn){
    local.push_back(vn);
    v[vn]=true;
    for(auto ch:adj[vn]){
        if(!v[ch]){
            dfs(ch);
        }
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
    for(ll i=1;i<=n;i++){
        if(!v[i]){
            local.clear();
            dfs(i);
            comps.push_back(local);
        }
    }
    cout<<"connected components are: "<<endl;
    for(auto c_comp:comps){
        for(auto vrt:c_comp){
            cout<<vrt<<" ";
        }
        cout<<endl;
    }
    cout<<"no of components:"<<comps.size()<<endl;

//    ll bridges=comps.size()-1;
//    cout<<bridges<<endl;
//    for(ll i=1;i<=bridges;i++){
//        cout<<comps[i-1][0]<<" "<<comps[i][0]<<endl;
//    }

}

int cc_main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



