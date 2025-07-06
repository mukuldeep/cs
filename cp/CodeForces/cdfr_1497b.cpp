//
// Created by me on 17-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,m,s,d,k;
    string str;
    cin>>n>>m;
    vector<ll> md;md.assign(m+1,0);
    for(int i=0;i<n;i++) {
        cin>>s;
        md[s%m]++;
    }
    d=m/2;
    ll cnt=0;
    if(md[0])cnt++;
    if(m&1)d++;
    for(ll i=1;i<d;i++){
        if(md[i]==0 || md[m-i]==0){
            cnt+=(md[i]+md[m-i]);
        }else{
            if(abs(md[i]-md[m-i])<2){
                cnt++;
            }else{
                cnt+=(abs(md[i]-md[m-i]));
            }
        }
    }

    if(m%2==0){
        if(md[d])cnt++;
    }
    cout<<cnt<<endl;
}

int main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



