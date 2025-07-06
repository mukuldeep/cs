//
// Created by me on 17-08-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
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
const ll t9p7=1000000007;

/*
 * returns prime factors of a number < ~1e10 - 1e12
 * as vector<ll> i.e. vll
 */
vll prime_factors(ll n)
{   uompll mp;
    vll pfs;
    ll ans=1;
    while (n % 2 == 0)
    {
        //pfs.PB_(2);
        ans*=2;
        if(mp.size()<2 && !(mp[ans])){
            mp[ans]=1;
            ans=1;
        }
        n = n/2;
    }
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            //pfs.PB_(i);
            ans*=i;
            if(mp.size()<2 && !(mp[ans])){
                mp[ans]=1;
                ans=1;
            }
            n = n/i;
        }
    }
    if (n > 2){
        //pfs.PB_(n);
        ans*=n;
    }
    if(ans>2)mp[ans]=1;
    if(mp.size()==3){
        FR_AU(xd,mp){
            pfs.push_back(xd.first);
        }
    }
    return pfs;
}

void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n;
    vll arr;
    arr=prime_factors(n);
    if(arr.size()==3){
        O_ "YES"<<EL
        O_ arr[0]<<" "<<arr[1]<<" "<<arr[2]<<EL
    }else{
        O_ "NO"<<EL
    }
}

DRIVER
