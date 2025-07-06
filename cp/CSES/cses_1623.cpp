//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll min_dif(ll ar[],ll n,ll sum,ll cur_sum){
    if(n==0)
        return abs(sum-cur_sum-cur_sum);
    return min(min_dif(ar,n-1,sum,cur_sum),min_dif(ar,n-1,sum,cur_sum+ar[n-1]));
}
void soln(ll t){
    ll p[25]={};
    ll n,i,sum=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>p[i];
        sum+=p[i];
    }
    cout<<min_dif(p,n,sum,0)<<endl;
}

int cc_main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



