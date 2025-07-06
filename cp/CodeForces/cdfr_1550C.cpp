//
// Created by me on 18-07-2021.
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
ll dist(ll x1,ll y1,ll x2, ll y2){
    return abs(x1-x2)+abs(y1-y2);
}
bool is_bad(ll x1,ll y1,ll x2, ll y2,ll x3,ll y3){
    ll d1=dist(x1,y1,x2,y2);
    ll d2=dist(x1,y1,x3,y3);
    ll d3=dist(x2,y2,x3,y3);
    if(d1+d2==d3 || d1+d3==d2 || d2+d3==d1)return true;
    return false;
}

void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n;
    vll arr(n);
    FR_IR(i,0,n){
        I_ arr[i];
    }
    FR_IR(i,0,n){
        a=1;
        if(i<n-2){
            if(!is_bad(arr[i],i,arr[i+1],i+1,arr[i+2],i+2)){
                cnt++;
            }else a=0;
        }
        if(a && i<n-3){
            if(!is_bad(arr[i],i,arr[i+3],i+3,arr[i+2],i+2)
                && !is_bad(arr[i],i,arr[i+1],i+1,arr[i+3],i+3)
                   && !is_bad(arr[i+1],i+1,arr[i+3],i+3,arr[i+2],i+2)){
                cnt++;
            }
        }
    }
    cnt+=n+n-1;
    O_ cnt<<EL
}

DRIVER
