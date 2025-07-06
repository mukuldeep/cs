//
// Created by me on 11-05-2021.
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


void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    vprll arr;
    vll as(4,0);
    I_ a>>b>>c;
    arr.PB_({a,0});
    arr.PB_({b,1});
    arr.PB_({c,2});

    srt(arr);
    m=abs(arr[1].first-arr[2].first);
    if(m>arr[0].first || (arr[0].first-m)&1){
        O_ "Impossible"<<EL
        return;
    }
    as[arr[0].second+arr[2].second]+=m;
    arr[0]={arr[0].first-m,arr[0].second};
    arr[2]={arr[2].first-m,arr[2].second};
    m=arr[0].first>>1;
    as[arr[0].second+arr[2].second]+=m;
    as[arr[0].second+arr[1].second]+=m;
    arr[0]={0,arr[0].second};
    arr[1]={arr[1].first-m,arr[1].second};
    arr[2]={arr[2].first-m,arr[2].second};

    as[arr[1].second+arr[2].second]+=arr[1].first;

    O_ as[1]<<" "<<as[3]<<" "<<as[2]<<EL





}

DRIVER
