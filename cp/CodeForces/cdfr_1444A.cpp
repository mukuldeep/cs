//
// Created by me on 19-04-2021.
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

void pre(){

}

/*
 * returns prime factors with their counts for a number < ~1e10 - 1e12
 * as map<ll,ll> i.e. mpll
 */
mpll prime_factors_cnt(ll n)
{
    mpll pfs;
    while (n % 2 == 0)
    {
        pfs[2]++;
        n = n/2;
    }

    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            pfs[i]++;
            n = n/i;
        }
    }

    if (n > 2)pfs[n]++;
    return pfs;
}

/*
 * returns prime factors of a number < ~1e10 - 1e12
 * as vector<ll> i.e. vll
 */
vll prime_factors(ll n)
{
    vll pfs;
    while (n % 2 == 0)
    {
        pfs.PB_(2);
        n = n/2;
    }
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            pfs.PB_(i);
            n = n/i;
        }
    }
    if (n > 2)pfs.PB_(n);
    return pfs;
}
void soln(ll t){
    ll p,q,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    I_ p>>q;
    if(p%q!=0){
        O_ p<<EL
        return;
    }
    a=p;
    mpll pfs=prime_factors_cnt(q);
    mpll pfd;
    FR_AU(xd,pfs){
        //O_ xd.first<<" "<<xd.second<<EL
        while(p%xd.first==0){
            pfd[xd.first]++;
            p/=xd.first;
        }
        //O_ pfd[xd.first]<<EL
        if(pfd[xd.first] && pfd[xd.first]>=xd.second){
            ll cfg=pow(xd.first,(pfd[xd.first]-xd.second+1));
            mn=min(mn,cfg);
        }
    }
    //O_ mn<<EL
    ans=a/mn;
    O_ ans<<EL
}

DRIVER
