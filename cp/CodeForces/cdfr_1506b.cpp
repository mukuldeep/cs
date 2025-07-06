//
// Created by me on 25-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,k;
    cin>>n>>k;
    string b;
    cin>>b;

    ll fir=-1,last=-1;
    for(ll i=0;i<n;i++){
        if(b[i]=='*'){
            fir=i;
            break;
        }
    }
    for(ll i=n-1;i>=0;i--){
        if(b[i]=='*'){
            last=i;
            break;
        }
    }
    //cout<<"f l :"<<fir<<" "<<last<<endl;
    if(fir==last){
        cout<<1<<endl;
    }else{
        ll cnt=2;
        for(ll gi=fir;gi<last;){
            if(gi+k<last) {
                for (ll j = gi + k; j > gi; j--) {
                    if (b[j] == '*') {
                        cnt++;
                        gi = j;
                        break;
                    }
                }
            }else{
                break;
            }
        }
        ll cnt2=2;
        cout<<cnt<<endl;
    }



}

int cc_main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



