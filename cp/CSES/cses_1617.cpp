//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,ans=1;
    cin>>n;
    while(n--){
        ans<<=1;
        ans%=1000000007;
    }
    cout<<ans<<endl;
}

int cc_main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



