//
// Created by me on 23-06-2021.
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
ll dfs(vvll &adj,vll &sub,vll &h, ll node, ll par, ll hei){
    hei++;sub[node]=1;
    FR_AU(xd,adj[node]){
        if(xd!=par){
            sub[node]+=dfs(adj,sub,h,xd,node,hei);
        }
    }h[node]=sub[node]-hei;
    return sub[node];
}

void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>k;
    vvll adj(n+1);
    vll sub(n+1,0),h(n+1);
    FR_IR(i,1,n){
        I_ a>>b;
        adj[a].PB_(b);
        adj[b].PB_(a);
    }
    dfs(adj,sub,h,1,0,0);
    sort(h.begin()+1,h.end(),greater<ll>());
    FR_IR(i,1,n-k+1){
        ans+=h[i];
    }
    O_ ans<<EL

}

DRIVER
