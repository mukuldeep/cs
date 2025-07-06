//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,b,sum=0,lasth=0;
    cin>>n;

    while(n--){
        cin>>b;
        if(b<lasth){
            sum+=lasth-b;
        }else{
            lasth=b;
        }
    }
    cout<<sum<<endl;
}

int cc_main() {
        soln(0);
    return 0;
}



