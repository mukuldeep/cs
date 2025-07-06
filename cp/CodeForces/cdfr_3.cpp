//
// Created by me on 5-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void soln(ll t){
    ll n;
    cin>>n;
    vector<ld> mine,miner;
    ll x,y,tp=2*n;
    for(int i=0;i<tp;i++) {
        cin>>x>>y;
        if(x==0){
            miner.push_back(y*y);
        }else{
            mine.push_back(x*x);
        }
    }
    sort(miner.begin(),miner.end());
    sort(mine.begin(),mine.end());
    ld ans=0;
    for(ll i=0;i<n;i++){
        ans+=sqrt(miner[i]+mine[i]);
    }
    cout<<fixed<<setprecision(20)<<ans<<endl;
}

int main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



