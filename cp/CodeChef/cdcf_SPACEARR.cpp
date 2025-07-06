//
// Created by me on 5-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,s,d;
    cin>>n;
    vector<ll> arr;
    for(int i=0;i<n;i++) {
        cin>>s;
        arr.push_back(s);
    }
    sort(arr.begin(),arr.end());
    ll f=0,sum=0;
    for(int i=1;i<=n;i++) {
        if(arr[i-1]>i){
            f=1;
            break;
        }
        sum+=(i-arr[i-1]);
    }
    if(f || !(sum & 1)){
        cout<<"Second"<<endl;
    }else{
        cout<<"First"<<endl;
    }
}

int cc_main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



