//
// Created by me on 09-06-2021.
//wrong
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC pre();ll t=1;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){SYNC pre(); ll t=1;W_(t)soln(t);return 0;}
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
/*
 * nCr nPr mod p precompute O(N) for 0<n<=N
 * each query O(C)=O(1)
 * <!> put in pre() as it is
 */
ll const N=12;
ll fact[N + 1];
void factorial()
{
    fact[0] = 1;
    for (ll i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i);
    }
}
ld nCr(ll n, ll R)
{
    ll ans = (ld)fact[n]/(ld)( fact[R] * fact[n-R]);
    return ans;
}

void pre(){
    ll p = 1000000007;
    factorial();
}

void soln(ll t){
    ll m,n,k,a=0,b,c=0,d=0,q,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    ld prob=0.0;
    string str;
    I_ str;
    n=str.length();
    FR_IR(i,0,n){
        if(str[i]=='+')a++;
    }
    b=n-a;
    I_ str;
    FR_IR(i,0,n){
        if(str[i]=='+')c++;
        else if(str[i]=='-')d++;
    }
    q=n-c-d;
    if(q==0){
        if(a==c && b==d)prob=1;
    }else{
        if(a-c>=0 && b-d>=0){
            prob=nCr(q,a-c)*pow(0.5,q);
        }
    }

    O_ PRCN<<prob<<EL


}

DRIVER
