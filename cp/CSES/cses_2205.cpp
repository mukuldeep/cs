//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,nb;
    cin>>n;
    nb=n;
    n=1<<n;
    for(ll i=0;i<n;i++){
        cout<<(bitset<16> (i^(i>>1)).to_string()).substr(16-nb,nb)<<endl;
    }
}

int main() {
    ll t=1;
//    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



