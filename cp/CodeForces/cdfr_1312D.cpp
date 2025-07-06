//
// Created by me on 15-08-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();
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
const ll t9p7=998244353;
/*
 * nCr nPr mod p precompute O(N) for 0<n<=N
 * each query O(C)=O(1)
 * <!> put in pre() as it is
 */
ll const N=1000005;
ll factorialNumInverse[N + 1];
ll naturalNumInverse[N + 1];
ll fact[N + 1];
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (ll i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (ll i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}

void factorial(ll p)
{
    fact[0] = 1;
    for (ll i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
ll nCrp(ll n, ll R, ll p)
{
    ll ans = ((fact[n] * factorialNumInverse[R])%p * factorialNumInverse[n-R])%p;
    return ans;
}
ll nPrp(ll n, ll R, ll p)
{
    ll ans=(fact[N] * factorialNumInverse[N-R])%p;
    return ans;
}
void pre(){
    ll p = 998244353;
    InverseofNumber(p);
    InverseofFactorial(p);
    factorial(p);
}
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
    string str;
    I_ n>>m;
    if(n<3){
        O_ 0<<EL
        return;
    }
    ans=nCrp(m,n-1,t9p7);
        ans*=(n-2);ans%=t9p7;
        ans*=pow_ex(2,n-3);ans%=t9p7;
    O_ ans<<EL


}

DRIVER
