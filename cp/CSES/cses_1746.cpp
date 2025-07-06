//
// Created by me on 13-04-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;W_(t)soln(t);return 0;}
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
    ll n,m,k,a,b,c,cnt=1,ans=0;
    string str;
    I_ n>>m;
    vector<vll> dp(n+1,vll(m+2,0));
    I_ a;
    if(a==0)FR_IR(i,1,m+1)dp[1][i]=1;
    else dp[1][a]=1;
    FR_IR(i,2,n+1){
        I_ a;
        if(a!=0){
            dp[i][a]=dp[i-1][a]+dp[i-1][a-1]+dp[i-1][a+1];
            dp[i][a]%=t9p7;
        }else{
            FR_IR(j,1,m+1){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1]+dp[i-1][j+1];
                dp[i][j]%=t9p7;
            }
        }
    }
    FR_IR(i,1,m+1){
        ans+=dp[n][i];
        ans%=t9p7;
    }
    O_ ans<<EL
}

DRIVER
