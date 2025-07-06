//
// Created by me on 14-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,in,d;
    cin>>n;
    vector<ll> arr;
    vector<vector<ll>> my_arr;
    vector<ll> her_arr;
    her_arr.assign(63,0);
    my_arr.assign(n+1,her_arr);

    ll max_sum=0,last_max=0;
    for(int i=1;i<=n;i++) {
        cin >> in;
        arr.push_back(in);
    }

    ll ans=0;
    for(ll i=0;i<n;i++){
        for(ll j=i;j<n;j++){
            ll maxm=arr[i];
            ll r_and=arr[i];
            ll r_or=arr[i];

            for(ll k=i+1;k<=j;k++){
                maxm=max(maxm,arr[k]);
                r_and=r_and & arr[k];
                r_or=r_or | arr[k];
            }
            if(r_or^r_and>=maxm)
                ans++;
        }
    }
    cout<<ans<<endl;
}

int cc_main() {
    //test();
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



