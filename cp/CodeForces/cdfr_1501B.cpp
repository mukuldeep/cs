//
// Created by me on 30-03-2021.
//
#include <bits/stdc++.h>
#define DRIVER int main(){ll t;cin>>t;while(t--)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){ll t;I_ t;W_(t)soln(t);return 0;}
#define FR_(a,c)   for (ll (a)=0;(a)<(c); (a)++)
#define FR_E(a,c)   for (ll (a)=0;(a)<=(c); (a)++)
#define FR_IR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FR_AU(xx,xxs) for(auto (xx):(xxs))
#define W_(n) while((n)--)
#define IL_ while(1)
#define PB_ push_back
#define MP_(a,b) make_pair((a),(b))
#define O_ cout<<
#define I_ cin>>
#define EL endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpr;
typedef map<ll,ll>  mp;
typedef unordered_map<ll,ll> uomp;


void soln(ll t){
    ll n,k,a,b,c;
    I_ n;
    stack<ll> st;
    vector<ll> dr(n+1,0);
    FR_IR(i,0,n){
        I_ a;
        st.push(i);
        while(!st.empty() && i-a<st.top()){
            dr[st.top()]=1;
            st.pop();
        }
    }
    FR_IR(i,0,n){
        O_ dr[i]<<" ";
    }O_ EL;
}

DRIVER