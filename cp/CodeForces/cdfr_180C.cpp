//
// Created by me on 09-07-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define FR_(a,c)   for (ll (a)=0;(a)<(c); (a)++)
#define FR_E(a,c)   for (ll (a)=0;(a)<=(c); (a)++)
#define FR_IR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FR_AU(xx,xxs) for(auto (xx):(xxs))
#define srt(ww) sort((ww).begin(),(ww).end())
#define rsrt(ww) sort((ww).rbegin(),(ww).rend())
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
typedef vector<vll> vvll;
typedef stack<ll> skll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef vector<pair<ll, ll>> vprll;
typedef map<ll,ll>  mpll;
typedef unordered_map<ll,ll> uompll;
typedef set<ll> stll;
const ll t9p7=1000000007;


void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ str;
    n=str.length();
    vll dpf(n+1,0),dpb(n+1,0);
    FR_IR(i,0,n){
        if('a'<=str[i] && str[i]<='z')dpf[i+1]=dpf[i]+1;
        else dpf[i+1]=dpf[i];
    }
    for(ll i=n-1;i>=0;i--){
        if('A'<=str[i] && str[i]<='Z')dpb[i]=dpb[i+1]+1;
        else dpb[i]=dpb[i+1];
    }
    FR_IR(i,0,n){
        mn=min(mn,dpf[i]+dpb[i+1]);
    }
//    FR_AU(xd,dpf)O_ xd<<" ";O_ EL
//    FR_AU(xd,dpb)O_ xd<<" ";O_ EL

    mn=min(mn,dpf[n]);
    mn=min(mn,dpb[0]);

    O_ mn<<EL

}

DRIVER
