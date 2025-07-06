//
// Created by me on 28-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void soln(ll t){
    ll a,b,n;
    cin>>a>>b>>n;
    vector<ll> att(n+1);
    ll hea_need=0,hea,max_att=LONG_LONG_MIN;
    for(ll i=0;i<n;i++) {
        cin >> att[i];
        max_att=max(max_att,att[i]);
    }
    for(ll i=0;i<n;i++){
        cin>>hea;
        hea_need+=att[i]*(hea/a);
    }
    hea_need-=max_att;
    if(hea_need<=b)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

int cc_main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



