//
// Created by me on 5-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;


void soln(ll t){
    multiset<pair<ll,ll>> mxxk;
    mxxk.insert(make_pair(1,2));
    mxxk.insert(make_pair(2,6));
    mxxk.insert(make_pair(8,2));
    mxxk.insert(make_pair(4,3));
    mxxk.insert(make_pair(4,9));
    mxxk.insert(make_pair(3,9));

    for(auto o:mxxk)
        cout<<o.first<<" "<<o.second<<endl;
    cout<<endl;

    ll oo=2,oi=4;
    auto l_bound = lower_bound(mxxk.begin(), mxxk.end(), make_pair(oo,LONG_LONG_MIN));
    auto u_bound = upper_bound(mxxk.begin(), mxxk.end(), make_pair(oi, LONG_LONG_MAX));

    for(auto itr_xx=l_bound;itr_xx!=u_bound && itr_xx!=mxxk.end();itr_xx++){
        ll f,s;
        f=(*itr_xx).first;
        s=(*itr_xx).second;
        cout<<f<<" "<<s<<endl;
    }cout<<endl;

    mxxk.erase(l_bound,u_bound);

     l_bound = lower_bound(mxxk.begin(), mxxk.end(), make_pair(oo=1,LONG_LONG_MIN));
     u_bound = upper_bound(mxxk.begin(), mxxk.end(), make_pair(oi, LONG_LONG_MAX));
    for(auto itr_xx=l_bound;itr_xx!=u_bound ;itr_xx++){
//        ll f,s;
//        f=;
//        s=;
        cout<<(*itr_xx).first<<" "<<(*itr_xx).second<<endl;
    }cout<<endl;
    for(auto o:mxxk)
        cout<<o.first<<" "<<o.second<<endl;
    cout<<endl;


}

int cc_main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



