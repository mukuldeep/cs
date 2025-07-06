//
// Created by me on 5-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define lld long double
using namespace std;

void soln(ll t){
    ll n,s,d,k;
    cin>>n>>k;
    set<ll> st;
    for(int i=0;i<n;i++) {
        cin>>d;
        st.insert(d);
    }
    auto high=st.end();high--;
    auto low=st.begin();


    ll size=st.size(),newsize=-1;

    ll mex=0;

    while(*low==mex){
        mex++;
        low++;
        if(low==st.end())break;
    }
    //cout<<*low<<" "<<mex;
    ll mm=0;
    while(k--) {
        if(*high==st.size()-1){
            mm=k+1;
            break;
        }
            ll x = *high + mex;
            x = ceil((lld)x/2.0);
            st.insert(x);
            newsize=st.size();
            if(size==newsize)break;
            size=newsize;

        low--;low--;
        mex--;mex--;
        while(*low==mex){
            mex++;
            low++;
            if(low==st.end())break;
        }
        high=st.end();high--;

    }
//    while(newsize!=size) {
//        ll x = *high + *low;
//        x /= 2;
//        size=st.size();
//        st.insert(x);
//        newsize = st.size();
//    }
    cout<<st.size()+mm<<endl;
}

int cc_main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



