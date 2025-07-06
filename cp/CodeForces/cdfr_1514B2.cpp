//
// Created by me on 19-04-2021.
// WRONG
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();
#define DRIVER int main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define FR_(a,c)   for (ll (a)=0;(a)<(c); (a)++)
#define FR_E(a,c)   for (ll (a)=0;(a)<=(c); (a)++)
#define FR_IR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FR_AU(xx,xxs) for(auto (xx):(xxs))
#define srt(ww) sort((ww).begin(),(ww).end())
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
ll const N=1000005;

ll factorialNumInverse[N + 1];
ll naturalNumInverse[N + 1];
ll fact[N + 1];
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}

void factorial(ll p)
{
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
ll Binomial(ll N, ll R, ll p)
{
    ll ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
    return ans;
}
void pre(){
    ll p = 1000000007;
    InverseofNumber(p);
    InverseofFactorial(p);
    factorial(p);
}
void soln(ll t){
    ll n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    I_ n>>k;n--;
    ll car[23]={0};
    a=(1<<k)-1;
    FR_IR(i,a-n+1,a+1){
        b=i;
        c=0;
        while(b){
            if(b&1){
                car[c]++;
            }
            b>>=1;
            c++;
        }
    }
    n++;
    ans=1;
    FR_IR(i,0,23){
        //O_ car[i]<<" ";
//        if(i){
//            car[i]=car[i]+(car[i-1])/2;
//            if(car[i]>n)car[i]=n;
//        }
        if(car[i]){
            c=(Binomial(n,car[i],t9p7))%t9p7;
            //O_ "C:"<<c<<" ";
            ans*=c;
            ans%=t9p7;
        }
    }
    O_ ans<<EL


}

TEST_DRIVER

