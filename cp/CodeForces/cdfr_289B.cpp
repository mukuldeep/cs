//
// Created by me on 16-06-2021.
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
mpll cost;
ll calc_cost(vvll arr, ll n,ll m,ll k, ll target){
    ll cst=0;
    if(cost.find(target)!=cost.end())return cost[target];
    FR_IR(i,0,n) {
        FR_IR(j, 0, m) {
            cst+=abs(target-arr[i][j])/k;
        }
    }
    cost[target]=cst;
    return cst;
}

ll ternary(vvll arr,ll l,ll r,ll n,ll m,ll k){
    //O_ "tern:"<<l<<" to "<<r<<EL
    if(r<l)return 1e18;
    ll ans;
    ll a=calc_cost(arr,n,m,k,l);
    ll d=calc_cost(arr,n,m,k,r);
    ll _1_3=l+(((r-l)/k)/3)*k;
    ll _2_3=l+2*(_1_3-l);
    ll b=calc_cost(arr,n,m,k,_1_3);
    ll c=calc_cost(arr,n,m,k,_2_3);
    if((r-l)/k<10){
        ans=a;
       for(ll i=l;i<=r;i+=k){
           ll cs=calc_cost(arr,n,m,k,i);
           //O_ i<<" "<<cs<<EL
            ans=min(ans,cs);
        }
        return ans;
    }

    if(c>b){
        ans=ternary(arr,l,_2_3,n,m,k);
    }else{
        ans=ternary(arr,_1_3,r,n,m,k);
    }
    return ans;
}

void soln(ll t){
    ll m,n,k,a,b,c=1,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m>>k;
    vvll arr(n,vll(m));
    FR_IR(i,0,n){
        FR_IR(j,0,m) {
            I_ arr[i][j];
            if ((arr[i][j] - arr[0][0]) % k)c = 0;
            mx=max(mx,arr[i][j]);
            mn=min(mn,arr[i][j]);
        }
    }
    if(c==0){
        O_ -1<<EL
        return;
    }

//    a=1e18;
//    a-=(a%k);
    ans=ternary(arr,mn,mx,n,m,k);
    O_ ans<<EL



}
DRIVER
