//
// Created by me on 4-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
ll calc_cost(vector<ll> arr, ll k){
    ll cost=0;
    for(auto o:arr){
        cost+=abs(o-k);
    }
    return cost;
}
ll ter_min_k(vector<ll> arr,ll h,ll l){
    if(h-l<3)
        return calc_cost(arr,(l+h)/2);
    ll mid1=l+(h-l)/3;
    ll mid2=h-(h-l)/3;
    ll mid1c,mid2c;
    mid1c=calc_cost(arr,mid1);
    mid2c=calc_cost(arr,mid2);
    if(mid1c<mid2c)
        return ter_min_k(arr,mid2,l);
    else
        return ter_min_k(arr,h,mid1);

}

ll minCost(vector<ll> A)
{
    ll n=A.size();
    ll cost = 0;
    sort(A.begin(), A.end());
    ll K = A[n / 2];
    for (auto o:A)
        cost += abs(o - K);

    if (n % 2 == 0) {
        ll tempCost = 0;
        K = A[(n / 2) - 1];
        for (auto o:A)
            tempCost += abs(o - K);
        cost = min(cost, tempCost);
    }

    return cost;
}

void soln(ll t){
    ll n,x=0,a,b,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    vector<ll> arr;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
        if(a>mx)mx=a;
        if(a<mn)mn=a;
    }
    //cout<<mn<<" "<<mx<<endl;
    //cout<<ter_min_k(arr,mn,mx)<<endl;
    cout<<minCost(arr)<<endl;
}

int cc_main() {
    soln(0);
    return 0;
}



