//
// Created by me on 10-09-2021.
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

ll pow_ex(ll a,ll b, ll p=t9p7){
    ll res=1;
    a%=p;
    if(b==0)return 1;
    if(a==0)return 0;
    WH_(b){
        if(b&1)res=(res*a)%p;
        b>>=1;
        a=(a*a)%p;
    }
    return res;
}

void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str,str2;
    I_ str;
    if(str.size()<3){
        str2=str;
    }else{
        str2=str.substr(str.size()-2,2);
    }
    n=0;
    FR_AU(xd,str2){
        n*=10;
        n+=(xd-'0');
    }
    ans=(1+pow_ex(2,n,5)+pow_ex(3,n,5)+pow_ex(4,n,5))%5;
    O_ ans<<EL
}

DRIVER
