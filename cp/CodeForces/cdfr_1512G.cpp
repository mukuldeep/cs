//
// Created by me on 13-04-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr); pre();
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

ll mx=10000001;
vector<ll> sod(mx+5),sm_n(mx+5,0);
void seive_sod(){
    FR_IR(i,1,mx){
        for(ll j=i;j<mx;j+=i)
            sod[j]+=i;
        if(sod[i]<=mx)
            if(sm_n[sod[i]]==0)
                sm_n[sod[i]]=i;
    }
}

void pre(){
    seive_sod();
}

void soln(ll t){
    ll n,k,a,b,c,cnt=0,ans=0;
    I_ n;
    if(sm_n[n]==0)
        O_ "-1"<<EL
    else
        O_ sm_n[n]<<EL
}

DRIVER
