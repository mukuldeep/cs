//
// Created by me on 24-08-2021.
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


class graph_adjl_unweighted{
    vvll adjl;
    ll n,m;
public:
    graph_adjl_unweighted(ll n,ll m){
        this->m=m;
        this->n=n;
        adjl=vvll (n+1);
    }

    /*
     * add edges
     */
    void add_undirected_edge(ll a,ll b){
        adjl[a].push_back(b);
        adjl[b].push_back(a);
    }
    void add_directed_edge(ll a,ll b){
        adjl[a].push_back(b);
    }

    /*
    * Edges input
    */
    void input_edges(){
        ll a,b;
        FR_IR(i,0,m) {
            I_ a >> b;
            add_undirected_edge(a,b);
        }
    }

    /*
     * bfs vertex finds shortest path between s to t
     * 1 based indexing
     */
    vll bfs_vertex_path(ll s,ll to){
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
            //reverse(path.begin(), path.end());
        }
        return path;
    }

    /*
     * graph dfs vertex recursion
     *
     */
    void dfs_util(ll s,vll &vis,ll &mx, ll h){
        if(adjl[s].size()==1){
            mx=max(mx,h);
            return;
        }
        FR_AU(xd,adjl[s]){
            if(!vis[xd]){
                vis[xd]=1;
                dfs_util(xd,vis,mx,h+1);
            }
        }
    }


};



void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m;
    graph_adjl_unweighted gr(n,n-1);
    gr.input_edges();
    vll path=gr.bfs_vertex_path(1,m);
    ll pos=(path.size()-2)/2;
    ll node=path[pos];
    vll vis(n+1,0);
    vis[path[pos+1]]=1;
    vis[path[pos]]=1;
    //O_ "node:"<<node<<EL
    gr.dfs_util(node,vis,mx,0);
    //O_ "mx:"<<mx<<EL
    ans=(mx+path.size()-pos-1)*2;
    O_ ans<<EL
}
DRIVER
