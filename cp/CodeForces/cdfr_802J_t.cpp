//
// Created by me on 27-07-2021.
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


class graph_adjl_weighted{
    vector<vprll> adjl;
    ll n,m;
    public:
    graph_adjl_weighted(ll n,ll m){
        this->m=m;
        this->n=n;
        adjl=vector<vprll> (n+1);
    }

    /*
     * add edges
     */
    void add_undirected_edge(ll a,ll b,ll val){
        adjl[a].push_back({b,val});
        adjl[b].push_back({a,val});
    }
    void add_directed_edge(ll a,ll b,ll val){
        adjl[a].push_back({b,val});
    }

    /*
     * Edges input
     */
    void input_edges(){
        ll a,b,val;
        FR_IR(i,0,m) {
            I_ a >> b>>val;
            add_undirected_edge(a,b,val);
        }
    }

    /*
     * graph dfs vertex recursion
     * tree: maximum sum among all paths from root to leaf
     */
    void dfs_util_msul(ll s,vll &vis,ll &mx,ll sm){
        //O_ s<<" "<<sm<<endl;
        ll f=1;
        FR_AU(xd,adjl[s]){
            if(!vis[xd.first]){
                vis[xd.first]=1;
                dfs_util_msul(xd.first,vis,mx,sm+xd.second);
                f=0;
            }
        }
        if(f){
            mx=max(mx,sm);
        }
    }
    ll max_among_sum_from_root_to_leaf(ll s){
        ll mx=LONG_LONG_MIN;
        vll vis(n+1,0);
        vis[s]=1;
        dfs_util_msul(s,vis,mx,0);
        return mx;
    }



};



void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n;//n nodes, m vertices
    graph_adjl_weighted gr(n,n-1);
    gr.input_edges();
    O_ gr.max_among_sum_from_root_to_leaf(0)<<EL
}

DRIVER
