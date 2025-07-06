//
// Created by me on 24-06-2021.
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
ll dfs(vll &arr,vvll &adj,vll &vis,ll node, ll mn){
    mn=min(arr[node],mn);
    vis[node]=1;
    FR_AU(xd,adj[node]){
        if(!vis[xd]){
            mn=min(mn,dfs(arr,adj,vis,xd,mn));
        }
    }
    return mn;
}

void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m;
    vll arr(n+1);
    FR_IR(i,1,n+1){
        I_ arr[i];
    }
    vvll adj(n+1);
    FR_IR(i,0,m){
        I_ a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vll vis(n+1,0);
    FR_IR(i,1,n+1){
        if(!vis[i]){
            mn=min(mn,dfs(arr,adj,vis,i,arr[i]));
            ans+=mn;
            mn=LONG_LONG_MAX;
        }
    }
    O_ ans<<EL

}

DRIVER
