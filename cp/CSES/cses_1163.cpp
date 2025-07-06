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
    set<ll> light;
    multiset<ll> dist;
    cin>>x>>n;
    light.insert(0);
    light.insert(x);
    dist.insert(x);
    for(ll i=0;i<n;i++){
        cin>>a;
        auto pos_in_l=light.upper_bound(a),pre_pos=pos_in_l;pre_pos--;
        dist.erase(dist.find(*pos_in_l-*pre_pos));
        dist.insert(a-*pre_pos);
        dist.insert(*pos_in_l-a);
        light.insert(a);
        auto ans=dist.end();ans--;
        cout<<*ans<<" ";
    }

}

int main() {
    soln(0);
    return 0;
}



