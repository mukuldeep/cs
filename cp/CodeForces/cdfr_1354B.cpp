//
// Created by me on 26-04-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define FR_(a,c)   for (ll (a)=0;(a)<(c); (a)++)
#define FR_E(a,c)   for (ll (a)=0;(a)<=(c); (a)++)
#define FR_IR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FR_AU(xx,xxs) for(auto (xx):(xxs))
#define srt(ww) sort((ww).begin(),(ww).end())
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
    ll n,k,a,b,c,cnt=0,ans=1e6,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    ll ar[]={-1,-1,-1,-1};
    string str;
    I_ str;
    n=str.size();

    FR_IR(i,0,n){
        ar[str[i]-'0']=i;
        if(ar[1]>-1 && ar[2]>-1 && ar[3]>-1){
            mn=min(ar[1],min(ar[2],ar[3]));
            mx=max(ar[1],max(ar[2],ar[3]));
            a=mx-mn+1;
            ans=min(ans,a);
        }
    }
    if(ans==1e6)ans=0;
    O_ ans<<EL
}

DRIVER
