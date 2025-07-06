//
// Created by me on -0-2021.
//
#include <bits/stdc++.h>
#define DRIVER int main(){ll t;cin>>t;while(t--)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){ll t;I_ t;W_(t)soln(t);return 0;}
#define FR_(a,c)   for (ll (a)=0;(a)<(c); (a)++)
#define FR_E(a,c)   for (ll (a)=0;(a)<=(c); (a)++)
#define FR_IR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FR_AU(xx,xxs) for(auto (xx):(xxs))
#define W_(n) while((n)--)
#define WH_ while
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
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef vector<pair<ll, ll>> vprll;
typedef map<ll,ll>  mpll;
typedef unordered_map<ll,ll> uompll;



void soln(ll t){
    ll n,k,a,b,c;
    string num;
    I_ num;
    ll sm=0,zro=0,ev=0;
    FR_IR(i,0,num.length()){
        sm+=num[i]-'0';
        if(num[i]=='0')zro++;
        if(!((num[i]-'0')&1))ev++;
    }
    if(!(sm%3) && zro && ev>1){
        O_ "red"<<EL;
    }else{
        O_ "cyan"<<EL;
    }

}

DRIVER
