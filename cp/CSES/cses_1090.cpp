//
// Created by me on 03-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,x,cnt=0,a;
    vector<ll> chld;
    cin>>n>>x;
    for(ll i=0;i<n;i++){
        cin>>a;
        chld.push_back(a);
    }

    sort(chld.begin(),chld.end());
    ll fi=0,li=chld.size()-1;
    while(fi<li){
        if(chld[fi]+chld[li]<=x)
            fi++;
        li--;
        cnt++;
    }
    if(fi==li)cnt++;
    cout<<cnt<<endl;

}

int cc_main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



