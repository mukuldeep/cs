//
// Created by me on 21-3-2021.
//incomplete
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void soln(ll t){
    ll n,a,k1,k2,w,b;
    cin>>n;
    vector<ll> arr,next(n+1);
    for(ll i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
        next.push_back(i+1);
    }
    ll len=arr.size();

    vector<ll> del_pos;
    vector<ll> ans;

    for(ll i=0;i<len;i++){
        if(gcd(arr[i],arr[next[i]])==1){
            del_pos.push_back(i);
            ans.push_back(arr[next[i]]);
            next[next[i]]=next[next[next[i]]];
            i=next[next[i]];
        }
    }

    while(del_pos.size()){
        vector<ll> new_del_pos;
        ll pre=-1;
        for(auto ind:del_pos){
            if(ind<pre){
                continue;
            }
            if(gcd(arr[ind],arr[next[ind]])==1){
                new_del_pos.push_back(ind);
                ans.push_back(arr[next[ind]]);
                next[next[ind]]=next[next[next[ind]]];
                pre=next[next[ind]];
            }
        }
        del_pos=new_del_pos;
    }


    for(auto xx:ans){

    }

}

int cc_main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



