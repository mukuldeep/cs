//
// Created by me on 27-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void soln(ll t){
    ll n,a,d,k;
    string str;
    cin>>n>>k;
    cin>>str;
    if(!(n&1) && n/2==k){
        cout<<"NO"<<endl;
        return;
    }

    ll f=1;
    for(ll i=0;i<k;i++){
        if(str[i]!=str[n-1-i]){
            f=0;
            break;
        }
    }

    if(f)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

int cc_main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



