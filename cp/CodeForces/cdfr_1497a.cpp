//
// Created by me on 17-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,a;
    cin>>n;
    vector<ll> arr;
    for(int i=0;i<n;i++) {
        cin>>a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    cout<<arr[0]<<" ";
    vector<ll> ex;
    for(ll i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            ex.push_back(arr[i]);
        }else{
            cout<<arr[i]<<" ";
        }
    }
    for(auto kk:ex){
        cout<<kk<<" ";
    }cout<<endl;
}

int main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



