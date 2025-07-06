//
// Created by me on 17-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define t9p7 1000000007
using namespace std;
vector<ll> nw;
ll n_ways_dp(ll sum){
    nw[0]=1;
    for(ll x=1;x<=sum;x++){
        ll cnt=0;
        for(ll i=1;i<7;i++){
            if(x-i>=0){
                cnt+=nw[x-i];
                cnt%=t9p7;
            }
        }
        nw[x]=cnt;
    }
    return nw[sum];
}
ll n_ways(ll sum){
    if(sum==0)return nw[sum]=1;
    if(nw[sum])return nw[sum];
    ll cnt=0;
    for(ll i=1;i<7;i++){
        if(sum>=i){
            cnt+=n_ways(sum-i);
            cnt%=t9p7;
        }
    }
    return nw[sum]=cnt;
}
void soln(ll t){
    ll n,x,ans=0,lsum=0,a,b;
    cin>>n;
    nw.assign(n+5,0);
    ans=n_ways_dp(n);

    cout<<ans<<endl;
}

int cc_main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



