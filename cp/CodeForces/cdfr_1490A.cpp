//
// Created by me on 27-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void soln(ll t){
    ll n,a,d,k=0;
    cin>>n;
    cin>>d;
    for(ll i=1;i<n;i++){
        cin>>a;
        ll mn,mx;
        mn=min(a,d);
        mx=max(a,d);
        while(mx>mn<<1){
            k++;
            mn<<=1;
        }
        d=a;
    }
    cout<<k<<endl;
}

int main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



