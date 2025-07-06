//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,f=0;
    string s;
    char ch;

    cin>>n;
    cin>>s;
    ch=s[n-1];
    while(s[f]!=ch)f++;

    if(f!=n-1){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }


}

int cc_main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



