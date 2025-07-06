//
// Created by me on 17-04-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();
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
ll dp[200025][10]={0};
void pre(){
    dp[0][0]=1;
    FR_IR(i,1,200021){
        dp[i][0]=dp[i-1][9]%t9p7;
        dp[i][1]=(dp[i-1][0]+dp[i-1][9])%t9p7;
        dp[i][2]=dp[i-1][1]%t9p7;
        dp[i][3]=dp[i-1][2]%t9p7;
        dp[i][4]=dp[i-1][3]%t9p7;
        dp[i][5]=dp[i-1][4]%t9p7;
        dp[i][6]=dp[i-1][5]%t9p7;
        dp[i][7]=dp[i-1][6]%t9p7;
        dp[i][8]=dp[i-1][7]%t9p7;
        dp[i][9]=dp[i-1][8]%t9p7;
    }
}
void soln(ll t){
    ll n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    I_ n>>k;
    while(n) {
        ll c_dgt=n%10;
        n/=10;
        ans=accumulate(dp[k+c_dgt],dp[k+c_dgt]+10,ans);
        ans%=t9p7;
    }
    O_ ans<<EL
}

DRIVER
