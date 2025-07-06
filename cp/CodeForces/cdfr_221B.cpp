//
// Created by me on 16-09-2021.
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
/*
 * Count total no of factor of n in T=O(sqrt(n)) S=O(1)
 */
bool dig[10]={false};
bool is_found(ll a){
    while(a){
        if(dig[a%10])return true;
        a/=10;
    }
    return false;
}
ll countFactors(ll n)
{
    ll cnt = 0;
    for (ll i=1; i<= sqrt(n); i++) {
        if (n % i == 0) {
            if(is_found(i))
                cnt++;
            if(n/i != i)
                if(is_found(n/i))
                    cnt++;
        }
    }
    return cnt;
}

void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n;
    a=n;
    while(a){
        dig[a%10]=1;
        a/=10;
    }
    ans=countFactors(n);
    O_ ans<<EL


}

DRIVER
