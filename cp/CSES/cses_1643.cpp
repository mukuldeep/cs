//
// Created by me on 3-3-2021.
//
#include <bits/stdc++.h>
#define ll long long    
using namespace std;

void soln(ll t){
    ll n,x,gsum=LONG_LONG_MIN,lsum=0,a,b;
    vector<pair<ll,ll>> arr;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a;
        if(a>=0){
            lsum+=a;
            if(gsum<lsum)
                gsum=lsum;
        }else{
            if(lsum+a>=0){
                lsum+=a;
                if(gsum<lsum)
                    gsum=lsum;
            }else{
                lsum=0;
                if(gsum<a)
                    gsum=a;
            }
        }
    }

    cout<<gsum<<endl;
}

int cc_main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



