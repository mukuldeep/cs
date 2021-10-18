//
// Created by me on 16-10-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;I_ t;FR_IR(i,1,t+1)soln(i);return 0;}
#define FR_IR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FR_AU(xx,xxs) for(auto (xx):(xxs))
#define O_ cout<<
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
    O_ "Case #"<<t<<": ";
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>a;
    ll amin=n-2;
    if(a<amin){
        O_ "IMPOSSIBLE"<<EL
        return;
    }else{
        O_ "POSSIBLE"<<EL
    }
    if(n==3 && a==1000000000){
        O_ "0 0\n0 2\n500000000 0"<<EL
        return;
    }
    ll base_size=a-(n-3);
    vprll lar,rar;
    FR_IR(i,0,n/2){
        lar.push_back({((i&1)?0:1),i});
        rar.push_back({((i&1)?1:2),i});
    }
    if(n&1){
        lar.push_back({1,(n/2)});
    }
    rar[0].first=base_size+1;
    reverse(rar.begin(),rar.end());
    FR_AU(xd,lar){
        O_ xd.first<<" "<<xd.second<<EL
    }
    FR_AU(xd,rar){
        O_ xd.first<<" "<<xd.second<<EL
    }
}

DRIVER
