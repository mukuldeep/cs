//
// Created by me on 10-06-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC pre();ll t=1;I_ t;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){SYNC pre();ll t=1;I_ t;W_(t)soln(t);return 0;}
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


ll const prime_uptow=32000;
bool prime[prime_uptow + 1];
vector<ll> prime_list;
void SieveOfEratosthenes(ll n=prime_uptow)
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

ll const prime_upto=100005;
vll prime_cnt(prime_upto+1,0);
void p_cnt(ll n=prime_upto)
{   prime_cnt[2]=1;
    prime_cnt[3]=1;
    ll cnt;
    FR_IR(p,4,prime_upto) {
        n=p;
        cnt = 0;
        while (n % 2 == 0) {
            cnt++;
            n = n/2;
            if(prime_cnt[n]){
                prime_cnt[p]=prime_cnt[n]+cnt;
                n=1;
            }
        }
        for (int i = 3; i <= sqrt(n); i = i + 2) {
            while (n % i == 0) {
                cnt++;
                n = n / i;
                if(prime_cnt[n]){
                    prime_cnt[p]=prime_cnt[n]+cnt;
                    n=1;
                    break;
                }
            }
        }
        if (n > 2) {
            cnt++;
            prime_cnt[p] = cnt;
        }
        //O_ p<<" "<<prime_cnt[p]<<EL
    }
}
void pre(){
    p_cnt();
    SieveOfEratosthenes();
//    FR_IR(i,0,100){
//        O_ i<<" "<<prime_cnt[i]<<EL
//    }
}



ll sopf(ll n){
    ll cnt=0;
    FR_AU(xd,prime_list){
        while (n%xd == 0)
        {
            cnt++;
            n = n/xd;
            if(n<prime_upto)return cnt+prime_cnt[n];
        }
    }
    if (n > 2)
        cnt++;
    return cnt;
}


void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m>>k;
    cnt=sopf(n)+sopf(m);
    if(k==1){
        if(m!=n && (m%n==0 || n%m==0 ))O_ "YES"<<EL
        else O_ "NO"<<EL
        return;
    }
    if(k<=cnt)O_ "YES"<<EL
    else O_ "NO"<<EL

}

DRIVER
