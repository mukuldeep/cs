//
// Created by me on 3-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,ans=0,lans=0,a,b;
    vector<pair<ll,ll>> sch;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a>>b;
        sch.push_back(make_pair(a,1));
        sch.push_back(make_pair(b,-1));
    }
    sort(sch.begin(),sch.end());
    for(auto x:sch){
        lans+=x.second;
        ans=max(ans,lans);
    }
    cout<<ans<<endl;
}

int main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



