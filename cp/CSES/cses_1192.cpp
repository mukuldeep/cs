//
// Created by me on 5-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
vector<string> mp;
void dfs(ll i,ll j,ll n,ll m){
    mp[i][j]='#';
    if(j+1<m){//right
        if(mp[i][j+1]=='.'){
            dfs(i,j+1,n,m);
        }
    }
    if(j-1>=0){//left
        if(mp[i][j-1]=='.'){
            dfs(i,j-1,n,m);
        }
    }
    if(i+1<n){//down
        if(mp[i+1][j]=='.'){
            dfs(i+1,j,n,m);
        }
    }
    if(i-1>=0){//up
        if(mp[i-1][j]=='.'){
            dfs(i-1,j,n,m);
        }
    }
}

void soln(ll t){
    ll n,m,x=0,a,b,cnt=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;

    cin>>n>>m;
    string line;
    for(ll i=0;i<n;i++){
        cin>>line;
        mp.push_back(line);
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(mp[i][j]=='.'){
                cnt++;
                dfs(i,j,n,m);
            }
        }
    }

    cout<<cnt<<endl;
}

int main() {
    soln(0);
    return 0;
}



