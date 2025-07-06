//
// Created by me on 13-04-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
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
#define PRCN fixed<<setprecision(20)
#define I_ cin>>
#define EL endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef stack<ll> skll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef vector<pair<ll, ll>> vprll;
typedef map<ll,ll>  mpll;
typedef unordered_map<ll,ll> uompll;
typedef set<ll> stll;
const ll t9p7=1000000007;


void soln(ll t){
    ll n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,days=0,leftover=0;
    I_ n>>c;
    vll arr(n),brr(n-1);
    FR_IR(i,0,n){
        I_ arr[i];
    }

    FR_IR(i,0,n-1){
        I_ brr[i];
    }
    mn=ceil((ld)c/(ld)arr[0]);
    days=ceil((ld)brr[0]/(ld)arr[0])+1;
    leftover=(arr[0]-brr[0]%arr[0])%arr[0];
    FR_IR(i,1,n){
        //O_ mn<<" "<<days<<" "<<leftover<<EL
        cnt=ceil((ld)(c-leftover)/(ld)arr[i]);
        if(days+cnt<mn)mn=days+cnt;
        days+=ceil((ld)(brr[i]-leftover)/(ld)arr[i])+1;
        leftover=(arr[i]-(brr[i]-leftover)%arr[i])%arr[i];
    }
    O_ mn<<EL
}

DRIVER
