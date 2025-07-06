//
// Created by me on .
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();
#define DRIVER int main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define FR_(a,c)   for (ll (a)=0;(a)<(c); (a)++)
#define FR_E(a,c)   for (ll (a)=0;(a)<=(c); (a)++)
#define FR_IR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FR_AU(xx,xxs) for(auto (xx):(xxs))
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
ll arr[10];

ll n_digits(ll n){
    ll nd=0;
    while(n){
        nd++;
        n/=10;
    }
    return nd;
}
void pre(){
    arr[0]=1;
    FR_IR(i,1,10){
        arr[i]=arr[i-1];
        while(n_digits(arr[i])<i)arr[i]<<=1;
        //O_ arr[i]<<EL
    }
}
void soln(ll t){
    ll n,k,a,b,c,cnt=0,ans=0;
    I_ a>>b>>c;
    ans=arr[c];
    while(n_digits(ans)<b)ans*=3;
    O_ arr[a]<<" "<<ans<<EL
}

DRIVER
