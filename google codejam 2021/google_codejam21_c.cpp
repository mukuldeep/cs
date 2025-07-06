//
// Created by me on 26-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define t9p7 1000000007
using namespace std;



void soln(ll t){

    ll n,c,d;
    cin>>n>>c;
    vector<ll> arr;
    for(ll i=1;i<=n;i++) {
        arr.push_back(i);
    }
    ll mx_cst=(n*(n+1))/2-1,mn_cst=n-1;
    cout<<"Case #"<<t<<": ";
    if(c>mx_cst || c<mn_cst){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    ll cost=c,l_n=n;
    cost=cost-n+1;

    for(ll i=n-2;i>=0;i--){
        if(cost>=(n-i-1)){
            reverse(arr.begin()+i,arr.end());
            cost-=(n-i-1);
        }else{
            reverse(arr.begin()+i,arr.begin()+i+cost+1);
            cost=0;
        }
        if(cost==0)break;
    }

    for(auto ff:arr){
        cout<<ff<<" ";
    }cout<<"\n";

}

int cc_main() {
    ll t;
    cin>>t;
    for(int i=1;i<=t;i++){
        soln(i);
    }
    return 0;
}



