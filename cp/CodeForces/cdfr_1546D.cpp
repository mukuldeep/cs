//
// Created by me on 13-07-2021.
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
ll nCrp(ll N, ll R, ll p)
{
    ll ans = ((fact[N] * factorialNumInverse[R])%p * factorialNumInverse[N-R])%p;
    return ans;
}
ll nPrp(ll N, ll R, ll p)
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

void soln(ll t){
    ll m,n,k,a=0,b=-1,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>str;
    if(str[0]=='0')a++;

    FR_IR(i,1,n){
        if(str[i]=='0')
            a++;
        else{
            if(str[i-1]=='1' && b<i-1){
                cnt++;
                b=i;
            }
        }
    }
//    O_ "zeros:"<<a<<EL
//    O_ "groups:"<<cnt<<EL
    O_ nCrp(cnt+a,cnt,998244353)<<EL

}

DRIVER
