//
// Created by me on 3-3-2021.
//
#include <bits/stdc++.h>
#define ll long long    
using namespace std;

void soln(ll t){
    ll n,x,ans=0,lans=0,a,b;
    vector<pair<ll,ll>> arr;
    cin>>n>>x;
    for(ll i=0;i<n;i++){
        cin>>a;
        if(a<x)
            arr.push_back(make_pair(a,i+1));
    }
    sort(arr.begin(),arr.end());
    n=arr.size();
    ll f=1;
    for(ll strt=0,ed=n-1;strt<ed;){
        ll sm=arr[strt].first+arr[ed].first;
        if(sm>x){
            ed--;
        }else if(sm<x){
            strt++;
        }else{
            cout<<arr[strt].second<<" "<<arr[ed].second<<endl;
            f=0;
            break;
        }
    }
    if(f)
        cout<<"IMPOSSIBLE"<<endl;
}

int cc_main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



