//
// Created by me on 30-04-2021.
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
    I_ n>>m;//n nodes, m vertices
    vvll adjl(n+1);//1 indexed
    FR_IR(i,0,m){
        I_ a>>b;
        adjl[a].PB_(b);
        adjl[b].PB_(a);//undirected
    }

    O_ count_connected_component(adjl,n)<<EL



}

TEST_DRIVER
