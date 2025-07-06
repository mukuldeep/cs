//
// Created by me on 1-4-2021.
//
#include <bits/stdc++.h>
#define DRIVER int main(){ll t=1;W_(t)soln(t);return 0;}
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
    ll n,k,a,b,c;
    string str;
    I_ str;
    n=str.length();
    ll f=1;
    if(n<3){
        O_ "YES"<<EL
        return;
    }
    FR_IR(i,2,n){
        if(str[i]!=('A'+((str[i-1]-'A')+(str[i-2]-'A'))%26)){
            f=0;
            break;
        }
    }

    if(f)
        O_ "YES"<<EL
    else
        O_ "NO"<<EL
}

DRIVER
