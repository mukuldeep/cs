//
// Created by me on 26-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void soln(ll t){
    string str;
    cin>>str;
    ll len=str.length();
    vector<ll> chrcnt(150,0);
    for(ll i=0;i<len;i++){
        chrcnt[str[i]]++;
    }
    vector<char> ans;
    vector<ll> vis(150,0);
    for(ll i=0;i<len;i++){
        chrcnt[str[i]]--;
        if(!vis[str[i]]){
            while(!ans.empty() && ans.back()<=str[i] && chrcnt[ans.back()]){
                vis[ans.back()]=0;
                ans.pop_back();
            }
            ans.push_back(str[i]);
            vis[ans.back()]=1;
        }
    }
    cout<<string(ans.begin(),ans.end())<<endl;
}

int main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



