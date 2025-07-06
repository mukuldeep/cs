//
// Created by me on 20-05-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){SYNC ll t=10;W_(t)soln(t);return 0;}
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
vvll dp(505,vll(505,0));
ll cnt_sol(ll a,ll b){
    if(a==b)return 0;
    if(a==1)return b-1;
    if(b==1)return a-1;

    if(dp[a][b])return dp[a][b];
    //if(b>a)swap(a,b);
    ll mn=LONG_LONG_MAX,k=ceil((ld)a/2.0);
    FR_IR(i,1,k+1){
        mn=min(mn,cnt_sol(i,b)+cnt_sol(a-i,b));
    }
    k=ceil((ld)b/2.0);

    FR_IR(i,1,k+1){
        mn=min(mn,cnt_sol(a,i)+cnt_sol(a,b-i));
    }
    return dp[a][b]=dp[b][a]=mn+1;
}
void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    I_ a>>b;
    O_ cnt_sol(a,b)<<EL
}

DRIVER
