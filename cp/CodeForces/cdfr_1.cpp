//
// Created by me on 5-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,s,d,k;
    string str;
    cin>>n>>k;
    cin>>str;
    ll f=1;
    for(int i=0;i<k;i++) {
        if(str[i]!=str[n-i-1]){
            f=0;
            break;
        }
    }

    if(f && k*2!=n){
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



