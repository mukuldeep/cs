//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void dfs(vector<vector<int>> gr, vector<int> &ans,int index,int parent, int depth ){
    ans[index]=(depth&1)?2:1;
    for(auto ele:gr[index]){
        if(ele==parent)continue;
        dfs(gr,ans,ele,index,depth+1);
    }
}

void soln(ll t){
    ll n,s,d;
    cin>>n;
    vector<vector<int>> x(n+1);
    vector<int> ans(n+1,0);
    for(int i=1;i<n;i++){
        cin>>s>>d;
        x[s].push_back(d);
        x[d].push_back(s);
    }
    dfs(x,ans,1,0,1);

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int cc_main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



