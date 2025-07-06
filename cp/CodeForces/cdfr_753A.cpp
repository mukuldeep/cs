//
// Created by me on 31-05-2021.
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
    I_ n;
    vvll dp(n+1,vll(n+1,0));
    FR_IR(i,0,n+1)dp[i][0]=1;
    FR_IR(i,1,n+1){
       FR_IR(j,1,n+1){
           dp[i][j]=dp[i-1][j];
           if(j-i>=0 && dp[i-1][j-i])dp[i][j]=max(dp[i][j],dp[i-1][j-i]+1);
       }
    }

//    FR_IR(i,0,n+1) {
//        FR_IR(j, 0, n + 1) {
//            O_ dp[i][j]<<" ";
//        }O_ EL
//    }
    cnt=dp[n][n]-1;
    O_ cnt<<EL
    a=n,b=n;
    while(cnt){
        if(dp[a-1][b-a]==dp[a][b]-1){
            O_ a<<" ";
            b-=a;
            a--;
            cnt--;
        }else{
            a--;
        }
    }
    O_ EL


}

DRIVER
