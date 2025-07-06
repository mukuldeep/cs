//
// Created by me on 02-04-2021.
//
#include <bits/stdc++.h>
#define DRIVER int main(){ll t=1;I_ t;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){ll t=1;I_ t;W_(t)soln(t);return 0;}
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
    ll n,k,a,b,c,f=1;
    I_ a>>b;
    string str;
    I_ str;
    n=str.length();
    vector<ll> hsh(256,0);
    FR_IR(i,0,n){
        hsh[str[i]]++;
    }
    if(b>0 && hsh['U']<b)f=0;
    if(b<0 && hsh['D']<-b)f=0;
    if(a>0 && hsh['R']<a)f=0;
    if(a<0 && hsh['L']<-a)f=0;

    if(f)O_ "YES"<<EL
    else O_ "NO"<<EL
}

DRIVER