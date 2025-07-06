//
// Created by me on 31-07-2021.
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


/*
 * Disjoint set union by height with path compression
 * #### position is 0 to n ###
 */
class disjoint_set_ubheight_pc{
        vll parent;
        vll height;
        vll size;
        ll n;
    public:
    /*
     * constructor
     */
    disjoint_set_ubheight_pc(){}
    disjoint_set_ubheight_pc(ll n){
        this->n=n;
        parent=vll(n);
        height=vll(n,1);
        size=vll(n,1);
        FR_IR(i,0,n){
            parent[i]=i;
        }
    }
    /*
     * find parent or representative of the set where a belongs to
     * with path compression
     */
    ll find_set(ll a){
        if(parent[a]==a)
            return a;
        return parent[a]=find_set(parent[a]);
    }
    /*
     * union by height
     */
    void union_bheight(ll a,ll b){
        a=find_set(a);
        b=find_set(b);
        if(a!=b){
            if(height[a]<height[b])
                swap(a,b);
            parent[b]=a;
            size[a]+=size[b];
            if(height[a]==height[b])
                height[a]++;
        }
    }
    /*
     * whether a and b belongs to same set or not
     */
    bool is_same_set(ll a, ll b){
        a=find_set(a);
        b=find_set(b);
        if(a==b)return true;
        return false;
    }

    /*
     * no of disjoint set
     */
    ll no_of_disjoint_set(){
        ll cnt=0;
        FR_IR(i,0,n){
            if(parent[i]==i)cnt++;
        }
        return cnt;
    }
    /*
     * prints all the sets
     * can be little faster
     */
    void print_sets(){
        map<ll,vll> mp;
        FR_IR(i,0,n){
            find_set(i);
            mp[parent[i]].push_back(i);
        }

        FR_AU(xd,mp){
            O_ "set "<<xd.first<<": ";
            FR_AU(xxd,xd.second)O_ xxd<<" ";O_ EL
        }
    }

    /*
     * others
     */
    ll get_parent(ll i)
    {
        return parent[i];
    }
    ll get_size(ll i){
        return size[i];
    }
};


class graph_adjl_unweighted{
    vvll adjl;
    ll n,m;
    disjoint_set_ubheight_pc dsu;
public:
    graph_adjl_unweighted(ll n,ll m){
        this->m=m;
        this->n=n;
        adjl=vvll (n+1);
        dsu=disjoint_set_ubheight_pc(n);
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
            dsu.union_bheight(a-1,b-1);
        }
    }

    bool is_every_component_fully_connected(){
        ll ans=0;
        map<ll,vll> mp;
        FR_IR(i,0,n){
            dsu.find_set(i);
            mp[dsu.get_parent(i)].push_back(i);
        }
        FR_AU(xd,mp){
            ll flag=1,sz;
            sz=dsu.get_size(xd.first);
            if(adjl[xd.first+1].size()!=sz-1)flag=0;
            FR_AU(xxd,xd.second){
                if(adjl[xxd+1].size()!=sz-1)flag=0;
            }
            ans+=flag;
        }
//        O_ "ans"<<ans;
//        O_ " mpsize"<<mp.size()<<EL
        return ans==mp.size();
    }

//    bool dfs_visit(vll &vis,ll x,ll par){
//        bool ans=false;
//        vis[x]=1;
//        FR_AU(xd,adjl[x]){
//            if(!vis[xd]){
//                ans|=dfs_visit(vis,xd,x);
//            }else if(xd!=par){
//                ans=true;
//            }
//        }
//        return ans;
//    }
//
//    ll count_cyclic_connected_component(){
//        vll vis(n+1,0);
//        ll cnt=0;
//        FR_IR(i,1,n+1){
//            if(!vis[i]){
//                //cnt++;
//                if(dfs_visit(vis,i,-1))cnt++;
//            }
//        }
//        return cnt;
//    }

};



void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m;
    graph_adjl_unweighted gr(n,m);
    gr.input_edges();
    if(gr.is_every_component_fully_connected())
        O_ "YES"<<EL
    else
        O_ "NO"<<EL

}

DRIVER
