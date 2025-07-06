//
// Created by me on 02-05-2021.
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
typedef int ll;
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
void print_path(ll x,ll n,vvll &p,ll dth){
    O_ dth<<EL
    vll path;
    ll cur=x;
    path.PB_(n);
    path.PB_(x);
    x=n;
    while(p[cur][x]){
        path.PB_(p[cur][x]);
        x=cur;
        cur=path.back();
    }
    reverse(path.begin(),path.end());
    FR_AU(xd,path)O_ xd<<" ";O_ EL
    //O_ "path"<<EL

}

void bfs_path(vvll &adjl,map<pair<pair<ll,ll>,ll>,bool> &tpl,ll n){
    queue<pair<ll,ll>> q;
    //map<pair<ll,ll>,bool> vis;
    vvll d(n+1,vll(n+1)),p(n+1,vll(n+1));
    q.push({0,1});

    while(!q.empty()){
        pair<ll,ll> cur_v=q.front();
        q.pop();

        if(cur_v.second==n){
            print_path(cur_v.first,n,p,d[cur_v.first][n]);
            return;
        }
        FR_AU(xd,adjl[cur_v.second]){
            if(d[cur_v.second][xd] || tpl[{cur_v,xd}]==1)continue;
                q.push({cur_v.second,xd});
                d[cur_v.second][xd]=d[cur_v.first][cur_v.second]+1;
                p[cur_v.second][xd]=cur_v.first;
        }
    }

    O_ -1<<EL
}
void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m>>k;//n nodes, m vertices
    vvll adjl(n+1);//1 indexed
    map<pair<pair<ll,ll>,ll>,bool> tpl;
    FR_IR(i,0,m){
        I_ a>>b;
        adjl[a].PB_(b);
        adjl[b].PB_(a);//undirected
    }
    FR_IR(i,0,k){
        I_ a>>b>>c;
        tpl[{{a,b},c}]=1;
    }

    bfs_path(adjl,tpl,n);
}

DRIVER
