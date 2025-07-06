//
// Created by me on 29-03-2021.
//
#include <bits/stdc++.h>
#define for_(a,c)   for ( int (a)=0; (a)<(c); (a)++)
#define pb_ push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<pair<ll, ll>> vp;
typedef map<ll,ll>  mp;


void soln(ll t){
    ll a,b,n,w,h=0;
    cin>>n>>w;
    map<ll,ll> mp;
    for(ll i=0;i<n;i++){
        cin>>a;
        mp[a]++;
    }

    while(n) {
        h++;
        ll l_w = w;
        for (auto it = mp.rbegin(); it != mp.rend(); it++) {
            ll key = (*it).first, val = (*it).second;
            //cout << key << " " << val << endl;
            ll large_pos = min(l_w / key, val);
            mp[key] -= large_pos;
            l_w -= key * large_pos;
            n -= large_pos;
            if (l_w <= 0)break;
        }
    }
        cout << h << endl;

}

int main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}