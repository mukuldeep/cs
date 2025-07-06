//
// Created by me on 26-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define t9p7 1000000007
using namespace std;



void soln(ll t){
    cout<<"Case #"<<t<<": ";
    ll n,s,d;
    cin>>n;
    vector<ll> arr;
    for(int i=0;i<n;i++) {
        cin>>s;
        arr.push_back(s);
    }

    ll cost=0;
    for(ll i=0;i<n-1;i++) {
        ll pos=i,sm=arr[i],j;
        for(j=i+1;j<n;j++){
            if(arr[j]<sm){
                sm=arr[j];
                pos=j;
            }
        }
        cost+=pos-i+1;
        reverse(arr.begin()+i,arr.begin()+pos+1);
//        cout<<"pos:"<<pos<<" ";
//        for(auto p:arr)cout<<p<<" ";cout<<endl;
    }
    cout<<cost<<"\n";
}

int cc_main() {
    ll t;
    cin>>t;
    for(int i=1;i<=t;i++){soln(i);}
    return 0;
}



