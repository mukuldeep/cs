//
// Created by me on 18-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,a,k1,k2,w,b;
    cin>>n>>k1>>k2;
    cin>>w>>b;

    ll max_w,max_b;
    max_w=min(k1,k2);
    max_w+=(abs(k1-k2)/2);

    max_b=min(n-k1,n-k2);
    max_b+=(abs(k1-k2)/2);

    if(max_w>=w && max_b>=b){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



