//
// Created by me on 06-04-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define srt(a) sort((a).begin(),(a).end());
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
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef vector<pair<ll, ll>> vprll;
typedef map<ll,ll>  mpll;
typedef unordered_map<ll,ll> uompll;

void soln(ll t){
    ll n,k,a,b,c;
    I_ n;
    vll arrx,arry;
    FR_IR(i,0,2*n){
        I_ a>>b;
        if(a)
            arrx.PB_(abs(a));
        else
            arry.PB_(abs(b));
    }
    srt(arrx)
    srt(arry)
    ld ans=0;
    FR_IR(i,0,n)
        ans+=sqrt(arry[i]*arry[i]+arrx[i]*arrx[i]);
    O_ PRCN<<ans<<EL
}

DRIVER
