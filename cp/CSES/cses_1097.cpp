//
// Created by me on 15-06-2021.
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


const int MAX = 5005;

ll dp[MAX][MAX];

ll calc(ll sum,ll i,ll j){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=max(
            sum-calc(sum-dp[i][i],i+1,j),
            sum-calc(sum-dp[j][j],i,j-1)
            );
}

void soln(ll t){
    //freopen("output.txt", "a", stdout);
    //freopen("test_input.txt", "r", stdin);
    ll m,n,k,a,b,c,cnt=0,ans=0,sum=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    memset(dp, -1, sizeof(dp));
    I_ n;
    vll arr(n+1),presum(n+1,0);
    FR_IR(i,1,n+1){
        I_ arr[i];
        sum+=arr[i];
        dp[i][i]=arr[i];
    }
    O_ calc(sum,1,n);


}

DRIVER
