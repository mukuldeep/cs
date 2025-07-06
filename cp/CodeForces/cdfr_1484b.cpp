//
// Created by me on 21-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,a,k1,k2,w,b,maxe=LONG_LONG_MIN;
    cin>>n;
    vector<ll> arr;
    set<ll> xx;
    for(ll i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
        if(a>maxe)maxe=a;
        xx.insert(a);
    }
    if(xx.size()==1){
        cout<<0<<endl;
        return;
    }
    set<ll> diff;
    for(ll i=1;i<n;i++){
        diff.insert(arr[i]-arr[i-1]);
    }

    ll len=diff.size();
    if(len!=2){
        if(len==1)
            cout<<0<<endl;
        else
            cout<<-1<<endl;
        return;
    }else{
        ll a1,a2;ll md,cc;
        vector<ll> difv(diff.begin(),diff.end());
        a1=difv[0];a2=difv[1];
        if(a1>0 && a2<0){
            md=a1-a2;
            cc=a1;
            if(md>maxe)
                cout<<md<<" "<<cc<<endl;
            else
                cout<<-1<<endl;
            return;
        }else if(a1<0 && a2>0){
            md=a2-a1;
            cc=a2;
            if(md>maxe)
                cout<<md<<" "<<cc<<endl;
            else
                cout<<-1<<endl;
            return;
        }
        cout<<-1<<endl;
    }

}

int cc_main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



