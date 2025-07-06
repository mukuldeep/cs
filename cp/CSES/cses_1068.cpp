//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n;
    cin>>n;
    cout<<n<<" ";
    while(n!=1){
        if(n&1)
            n=n*3+1;
        else
            n>>=1;
        cout<<n<<" ";
    }
}

int cc_main() {
        soln(0);
    return 0;
}



