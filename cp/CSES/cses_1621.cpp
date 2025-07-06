//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){

    ll n,ans=0,a;
    set<ll> st;
    cin>>n;
    while(n--){
        cin>>a;
        st.insert(a);
    }
    cout<<st.size()<<endl;
}

int main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



