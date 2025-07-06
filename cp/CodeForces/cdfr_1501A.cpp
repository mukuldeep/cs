//
// Created by me on 27-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void soln(ll t){
    ll n,a,d;
    vector<ll> ar,de;
    cin>>n;
    ar.push_back(0);
    de.push_back(0);
    for(ll i=1;i<=n;i++){
        cin>>a>>d;
        ar.push_back(a);
        de.push_back(d);
    }
    ll art=0,det=0;
    for(ll i=1;i<=n;i++){
        cin>>d;
        art=det+(ar[i]-de[i-1]+d);
        ll cal_det=art+ceil((ld)(de[i]-ar[i])/2);
        det=max(de[i],cal_det);
    }
    cout<<art<<endl;
}

int main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



