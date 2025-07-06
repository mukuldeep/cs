//
// Created by me on 21-12-2021.
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
typedef unordered_map<ll,bool> uompll;
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
     * detect cycle in directed forest
     * O(n+m)
     */
    bool detect_cycle_digraph_util(ll curr, vector<bool> &visited,uompll &c_stk){
        if(!visited[curr]) {
            c_stk[curr]=1;
            visited[curr]=1;
            FR_AU(xd, adjl[curr]) {
                if ( c_stk[xd] || (!visited[xd] && detect_cycle_digraph_util(xd, visited, c_stk))) {
                    return true;
                }
            }
        }
        c_stk[curr]=0;
        return false;
    }
    bool detect_cycle_digraph_forest(){
        vector<bool> visited(n,0);
        uompll c_stk;
        FR_IR(i,1,n+1){
            if(detect_cycle_digraph_util(i,visited,c_stk))
                return true;
        }
        return false;
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

    void topological_sort() {
        vll ans;
        vll visited(n+1,0);
        ans.clear();
        for (int i = 1; i <=n; ++i) {
            if (!visited[i])
                dfs_topo(i,visited,ans);
        }
        for(ll i=n-1;i>=0;i--){
            O_ ans[i]<<" ";
        }O_ EL
    }


};




void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m;
    graph_adjl_unweighted gr(n,m);
    gr.input_edges();
    if(gr.detect_cycle_digraph_forest()){
        O_ "IMPOSSIBLE"<<EL
    }else{
        //O_ "possible"<<EL
        gr.topological_sort();
    }
}

DRIVER
