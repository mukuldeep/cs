//
// Created by me on 20-08-2021.
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
    I_ n>>str;
    vll arr(n),rrr(n);
    arr[0]=1;
    FR_IR(i,1,n){
        if(str[i]!=str[i-1]){
            arr[i]=arr[i-1]+1;
        }else{
            arr[i]=1;
        }
    }
    rrr[n-1]=1;
    for(ll i=n-2;i>=0;i--){
        if(str[i]!=str[i+1]){
            rrr[i]=rrr[i+1]+1;
        }else{
            rrr[i]=1;
        }
    }
    O_ 1+((str[0]=='R')?rrr[0]:0)<<" ";
    FR_IR(i,1,n){
        ans=1+((str[i]=='R')?rrr[i]:0)+((str[i-1]=='L')?arr[i-1]:0);
        O_ ans<<" ";
    }
    O_ 1+((str[n-1]=='L')?arr[n-1]:0)<<" ";
    O_ EL


}
DRIVER
