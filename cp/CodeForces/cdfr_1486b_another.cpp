//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n;
    cin>>n;
    ll b,sum=0;
    for(ll i=0;i<n;i++) {
        cin >> b;
        sum+=b;
    }
    b=(n*(n+1))/2;
    if(sum<b)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;

}

int cc_main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



