//
// Created by me on 5-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,s,d;
    cin>>n;
    d=n;
    ll h_bit=0;
    while(n){
        n>>=1;
        h_bit++;
    }
    ll inv=0;
    for(ll i=0;i<h_bit;i++){
        if(!(d & 1<<i))
            inv+=1<<i;
    }
    h_bit--;
    ll hp2=1<<h_bit;
    cout<<((inv|hp2)*(hp2-1))<<endl;
}

int cc_main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



