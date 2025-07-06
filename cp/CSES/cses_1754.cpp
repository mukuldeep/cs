//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll a,b;
    cin>>a>>b;
    ll x,y;
    x=(2*a-b);
    y=(2*b-a);

    if((x/3)>=0 && (y/3)>=0 && x%3==0 && y%3==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

int cc_main() {
    ll t=1;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



