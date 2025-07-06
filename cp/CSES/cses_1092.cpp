//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,sum;
    cin>>n;
    sum=(n*(n+1))/2;
    if(sum&1)
        cout<<"NO"<<endl;
    else{
        sum>>=1;
        vector<ll> st1,st2;
        for(ll i=n;i>0;i--){
            if(sum>=i){
                sum-=i;
                st1.push_back(i);
            }else
                st2.push_back(i);
        }


        cout<<"YES"<<endl;
        cout<<st1.size()<<endl;
        for(auto o:st1)
            cout<<o<<" ";
        cout<<endl<<st2.size()<<endl;
        for(auto o:st2)
            cout<<o<<" ";
    }

}

int cc_main() {
    soln(0);
    return 0;
}



