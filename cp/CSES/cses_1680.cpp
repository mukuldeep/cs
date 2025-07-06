//
// Created by me on 22-12-2021.
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
            add_directed_edge(a,b);
        }
    }

            /*
             * prints one topo sort for directed forest
             */
            void dfs_topo(ll v,vll &visited,vll &ans) {
                visited[v] = true;
                for (ll u : adjl[v]) {
                    if (!visited[u])
                        dfs_topo(u,visited,ans);
                }
                ans.push_back(v);
            }

            vll topological_sort() {
                    vll ans;
                    vll visited(n + 1, 0);
                    ans.clear();
                    for (int i = 1; i <= n; ++i) {
                        if (!visited[i])
                            dfs_topo(i, visited, ans);
                    }
                    reverse(ans.begin(),ans.end());
                    return ans;
            }


            /*
             * prints one topo sort for directed forest
             */
            void topo2(ll v,vll &parent,vll &cnt) {
                for (ll u : adjl[v]) {
                    if(cnt[v]+1>cnt[u]){
                        cnt[u]=cnt[v]+1;
                        parent[u]=v;
                    }
                }
            }

            void topological_sort2() {
                vll topo=topological_sort();
                vll parent(n + 1, 0);
                vll cnt(n+1,0);

                ll f=1;
                cnt[1]=1;
                for(ll i :topo) {
                    if(f){
                        if(i!=1)continue;
                        else f=0;
                    }
                    topo2(i, parent, cnt);
                }

                vll ansarr;
                if(cnt[n]){
                    ll cur=n;
                    O_ cnt[n]<<EL
                    while(cur!=1){
                        ansarr.push_back(cur);
                        cur=parent[cur];
                    }
                    ansarr.push_back(1);
                    reverse(ansarr.begin(),ansarr.end());
                    FR_AU(xd,ansarr){
                        O_ xd<<" ";
                    }O_ EL
                }else{
                    O_ "IMPOSSIBLE"<<EL
                }
                //return paths[n]%t9p7;
            }
};


void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m;
    graph_adjl_unweighted gr(n,m);
    gr.input_edges();
    gr.topological_sort2();
}
DRIVER

