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
    for(ll x=1;x<=req_sum;x++){
       for(auto coin:coins){
           if(x>coin){
               if(sum[x-coin]) {
                   if(!sum[x])sum[x]=LONG_LONG_MAX;
                   sum[x] = min(sum[x], sum[x - coin] + 1);
               }
           }else if(x==coin){
               sum[x]=1;
           }else{
               break;
           }
       }
       //cout<<x<<":"<<sum[x]<<endl;
    }

    return sum[req_sum]==0?-1:sum[req_sum];
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



