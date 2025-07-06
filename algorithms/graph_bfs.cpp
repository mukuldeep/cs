//
// Created by me on 02-05-2021.
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

/*
 * bfs vertex general
 * 1 based indexing
 */
void bfs_vertex(vvll &adjl,ll n,ll s){
    qll q;
    vector<bool> vis(n+1);
    vll d(n+1),p(n+1);

    q.push(s);
    vis[s]=1;
    p[s]=-1;
    while(!q.empty()){
        ll cur_v=q.front();
        q.pop();
        FR_AU(xd,adjl[cur_v]){
            if(!vis[xd]){
                vis[xd]=1;
                q.push(xd);
                d[xd]=d[cur_v]+1;
                p[xd]=cur_v;
            }
        }
    }

    FR_IR(i,1,n+1)O_ d[i]<<" ";O_ EL
    FR_IR(i,1,n+1)O_ p[i]<<" ";O_ EL
}

/*
 * bfs vertex finds shortest path between s to t
 * 1 based indexing
 */
vll bfs_vertex_path(vvll &adjl,ll n,ll s,ll to){
    qll q;ll t=1;
    vector<bool> vis(n+1);
    vll d(n+1),p(n+1);

    q.push(s);
    vis[s]=1;
    p[s]=-1;
    while(!q.empty() && t){
        ll cur_v=q.front();
        q.pop();
        FR_AU(xd,adjl[cur_v]){
            if(!vis[xd]){
                vis[xd]=1;
                q.push(xd);
                d[xd]=d[cur_v]+1;
                p[xd]=cur_v;
                if(xd==to){
                    t=0;
                    break;
                }
            }
        }
    }

    vll path;
    if(vis[to]){
        for (ll v = to; v!=-1;v=p[v])
            path.PB_(v);
        reverse(path.begin(), path.end());
    }
    return path;
}

/*
 * bfs edge print depth and shortest path
 * 1 based indexing
 */
void print_path(ll x,ll n,vvll &p,ll dth){
    O_ dth<<EL//depth
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
    FR_AU(xd,path)O_ xd<<" ";O_ EL//path
}
void bfs_edge_path(vvll &adjl,ll n){
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
            if(d[cur_v.second][xd])continue;
            q.push({cur_v.second,xd});
            d[cur_v.second][xd]=d[cur_v.first][cur_v.second]+1;
            p[cur_v.second][xd]=cur_v.first;
        }
    }
    O_ -1<<EL//nothing found
}

void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m;//n nodes, m vertices
    vvll adjl(n);//0 indexed
    FR_IR(i,0,m){
        I_ a>>b;
        adjl[a-1].PB_(b-1);
        adjl[b-1].PB_(a-1);//undirected
    }
    bfs_vertex(adjl,n,1);
    vll path=bfs_vertex_path(adjl,n,0,3);
    FR_AU(xd,path)O_ xd+1<<" ";O_ EL
}

TEST_DRIVER
/*
1
5 5
1 2
1 3
1 4
2 3
3 5


 1
5 6
1 2
1 3
1 4
2 3
2 4
3 5

 */