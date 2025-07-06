//
// Created by me on 12-05-2021.
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
const ll t9p7=1000000007;

ll const prime_upto=100005;
bool prime[prime_upto + 1];
vector<ll> prime_list;
void SieveOfEratosthenes(ll n=prime_upto)
{
    memset(prime, true, sizeof(prime));
    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p])
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // grinding into a list
    for (int p = 2; p <= n; p++)
        if (prime[p])
            prime_list.push_back(p);
}
ll smp=0;
bool is_prime(ll n){
    if(n<prime_upto && prime[n])return prime[n];
    FR_AU(xd,prime_list){
        if(n%xd==0){
            smp=xd;
            return false;
        }
    }
    return true;
}
void pre(){
    SieveOfEratosthenes();
}
void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    I_ n;
    if(is_prime(n)){
        O_ 1<<EL
    }else{
        if(smp==2){
            O_ (n>>1)<<EL
        }else{
            //O_ smp<<EL
            O_ ((n-smp)>>1)+1<<EL
        }
    }

}

DRIVER
