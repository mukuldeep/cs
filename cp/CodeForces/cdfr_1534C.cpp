//
// Created by me on 13-06-2021.
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


void dfs(vvll &adjl,vll &vis,ll x){
    vis[x]=1;
    FR_AU(xd,adjl[x]){
        if(!vis[xd]){
            dfs(adjl,vis,xd);
        }
    }
}

ll count_connected_component(vvll &adjl,ll n){
    vll vis(n+1,0);
    ll cnt=0;
    FR_IR(i,1,n+1){
        if(!vis[i]){
            cnt++;
            dfs(adjl,vis,i);
        }
    }
    return cnt;
}

void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n;
    vll arr(n);
    vvll adj(n+1);
    FR_IR(i,0,n){
        I_ arr[i];
    }
    FR_IR(i,0,n){
        I_ a;
        adj[a].PB_(arr[i]);
    }
    cnt=count_connected_component(adj,n);
    ans=pow_ex(2,cnt,t9p7);
    //O_ "connected component: "<<cnt<<EL
    O_ ans<<EL;
}

DRIVER
