//
// Created by me on 20-05-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){SYNC ll t=1;W_(t)soln(t);return 0;}
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

ll mod_inv(ll a, ll m)
{
    ll m0 = m;
    ll y=0,x=1;
    if (m==1)
        return 0;
    while (a>1) {
        ll q=a/m;
        ll t=m;
        m=a%m,a=t;
        t=y;
        y=x-q*y;
        x=t;
    }
    if(x<0)
        x+=m0;
    return x;
}
void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    I_ n;
    a=(n*(n+1))/2;
    if(a&1){
        O_ 0<<EL
        return;
    }
    a>>=1;

    vvll dp(n+1,vll(a+1,0));
    FR_IR(i,0,n+1){
        dp[i][0]=1;
    }
    FR_IR(i,1,n+1){
        FR_IR(j,1,a+1){
            dp[i][j]=dp[i-1][j];
            if(j-i>=0){
                dp[i][j]+=dp[i-1][j-i];
                dp[i][j]%=t9p7;
            }
            //O_ dp[i][j]<<" ";
        }//O_ EL
    }
    ans=dp[n][a]*mod_inv(2,t9p7);
    ans%=t9p7;
    O_ ans<<EL
}

DRIVER
