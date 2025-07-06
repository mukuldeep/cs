//
// Created by me on 17-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define t9p7 1000000007
using namespace std;
vector<ll> sum;
vector<ll> coins;
ll n_ways_dp(ll req_sum){
    sum[0]=1;
    for(ll x=1;x<=req_sum;x++){
        ll cnt=0;
       for(auto coin:coins){
           if(x>=coin){
               cnt+=sum[x-coin];
               cnt%=t9p7;
           }else{
               break;
           }
       }
       sum[x]=cnt;
    }
    return sum[req_sum];
}

void soln(ll t){
    ll n,x,ans=0,lsum=0,a,b;
    cin>>n>>x;
    sum.assign(x+5,0);
    for(ll i=0;i<n;i++){
        cin>>a;
        coins.push_back(a);
    }
    sort(coins.begin(),coins.end());
    ans=n_ways_dp(x);
    cout<<ans<<endl;
}

int main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



