//
// Created by me on 02-04-2021.
//
#include <bits/stdc++.h>
#define DRIVER int main(){ll t=1;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){ll t=1;W_(t)soln(t);return 0;}
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
    ll n,q,k,a,b,c,c0=0,c1=0;
    I_ n>>q;
    vector<ll> arr(n+1,0);
    FR_IR(i,0,n){
        I_ k;
        if(k)arr[i]=1,c1++;
    }
    FR_IR(i,0,q){
        I_ a>>b;
        b--;
        if(a==1){
            if(arr[b])
                c1--,arr[b]=0;
            else
                c1++,arr[b]=1;
        }else{
            if(b<c1)
                O_ 1<<EL
            else
                O_ 0<<EL
        }
    }

}

DRIVER
