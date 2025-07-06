//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n;
    ll ar[]={0,0,6,28,96,252,550,1056,1848};
    cin>>n;
    if(n>5){
        for(ll i=1;i<6;i++)
            cout<<ar[i]<<endl;
        for(ll i=6;i<=n;i++){
            ll sqn=i*i,im4=i-4;
            cout<<(((sqn*(sqn-1))>>1)-((im4*im4)<<2)-20*im4-24)<<endl;
        }
    }else {
        for (ll i = 1; i <= n; i++) {
            cout << ar[i] << endl;
        }
    }

}

int cc_main() {
    soln(0);
    return 0;
}



