//
// Created by me on 18-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=200005;
ll t[4*MAXN];
void build(vector<ll> &a, ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
ll sum(ll v, ll tl, ll tr, ll l, ll r) {
    //cout<<tl<<":"<<tr<<" "<<l<<":"<<r<<endl;
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    ll tm = (tl + tr) / 2;

    return sum(v*2, tl, tm, l, min(r, tm))
            + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}
void soln(ll tt){
    ll n,q,a,b,ln;
    vector<ll> arr;
    cin>>n>>q;
    ln=n;
    for(ll i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
    }
    build(arr,1,0,n-1);
    //cout<<"build "<<n<<endl;
    for(ll i=0;i<q;i++){
        cin>>a>>b;
        //if(a>b)swap(a,b);
        //cout<<"ln:"<<ln<<endl;
        cout<<sum(1,0,n-1,a-1,b-1)<<endl;
    }

}

int main() {
    ll tt=1;
    //cin>>t;
    while(tt--)
        soln(tt);
    return 0;
}



