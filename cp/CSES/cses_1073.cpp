//
// Created by me on 4-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
void print_v(vector<ll> v){
    for(auto o:v)
        cout<<o<<" ";
    cout<<endl;
}
void soln(ll t){
    ll n,x=0,a,b,cnt=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    vector<ll> arr;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a;
        if(arr.size()==0){
            cnt++;
            arr.push_back(a);
        }else if(arr[arr.size()-1]<=a){
            cnt++;
            arr.push_back(a);
        }else{
            ll pos=upper_bound(arr.begin(),arr.end(),a)-arr.begin();
            arr[pos]=a;
        }
//        cout<<cnt<<endl;
//        print_v(arr);

    }
    cout<<cnt<<endl;
}

int cc_main() {
    soln(0);
    return 0;
}



