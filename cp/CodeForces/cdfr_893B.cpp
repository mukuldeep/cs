//
// Created by me on 29-08-2021.
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
uompll mp;
void pre(){
    FR_IR(i,1,100){
        ll a=(pow_ex(2,i)-1)*(pow_ex(2,i-1));
        if(a<1e7){
            mp[a]=1;
            //O_ a<<EL
        }else{
            break;
        }
    }
}
/*
 * Count total no of factor of n in T=O(sqrt(n)) S=O(1)
 */
ll countFactors(ll n)
{
    ll cnt = 0;
    vll factors,rfactors;
    for (ll i=1; i<= sqrt(n); i++) {
        if (n % i == 0) {
            cnt++;
            factors.push_back(i);
            if(n/i != i){
                cnt++;
                rfactors.push_back(n/i);
            }
        }
    }
    while(!rfactors.empty()){
        factors.push_back(rfactors.back());
        rfactors.pop_back();
    }
    while(!factors.empty()){
        if(mp[factors.back()]==1){
            return factors.back();
        }
        factors.pop_back();
    }
    return 1;
}

void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n;
    O_ countFactors(n)<<EL

}

DRIVER
