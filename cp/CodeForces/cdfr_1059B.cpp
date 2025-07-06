//
// Created by me on 25-05-2021.
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

bool match_pen(ll i,ll j,vector<string> &arr){
    if(arr[i][j]=='#' && arr[i][j+1]=='#' && arr[i][j+2]=='#' &&
       arr[i+1][j]=='#' && arr[i+1][j+2]=='#' &&
       arr[i+2][j]=='#' && arr[i+2][j+1]=='#' && arr[i+2][j+2]=='#')return true;
    return false;
}
void set_pen(ll i,ll j,vector<string> &dp){
    dp[i][j]='.';dp[i][j+1]='.';dp[i][j+2]='.';
    dp[i+1][j]='.';dp[i+1][j+2]='.';
    dp[i+2][j]='.';dp[i+2][j+1]='.';dp[i+2][j+2]='.';
}

void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m;
    vector<string> arr(n),dp;
    FR_IR(i,0,n){
        I_ arr[i];
    }
    dp=arr;
    FR_IR(i,0,n) {
        FR_IR(j, 0, m) {
            if (dp[i][j] == '#') {
                if (i<n-2){
                    if(j<m-2 && match_pen(i,j,arr))set_pen(i,j,dp);
                    if(j>0 && j<m-1 && match_pen(i,j-1,arr))set_pen(i,j-1,dp);
                    if(j>1 && match_pen(i,j-2,arr))set_pen(i,j-2,dp);

                }
                if(i>0 && i<n-1){
                    if(j<m-2 && match_pen(i-1,j,arr))set_pen(i-1,j,dp);
                    if(j>1 && match_pen(i-1,j-2,arr))set_pen(i-1,j-2,dp);
                }
                if(i>1 && i<n-2){
                    if(j<m-2 && match_pen(i-2,j,arr))set_pen(i-2,j,dp);
                    if(j>0 && j<m-1 && match_pen(i-2,j-1,arr))set_pen(i-2,j-1,dp);
                    if(j>1 && match_pen(i-2,j-2,arr))set_pen(i-2,j-2,dp);
                }

            }
        }
    }

    FR_IR(i,0,n) {
        //O_ dp[i]<<EL
        FR_IR(j, 0, m) {
            if(dp[i][j]=='#'){
                ans=1;
                //break;
            }
        }
    }
    if(ans)O_ "NO\n";
    else O_ "YES\n";

}

DRIVER
