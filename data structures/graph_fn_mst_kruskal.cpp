//
// Created by me on 23-08-2021.
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
 * Disjoint set union by height with path compression
 * #### position is 0 to n ###
 */
class disjoint_set_ubheight_pc{
        vll parent;
        vll height;
        ll n;
    public:
    /*
     * constructor
     */
    disjoint_set_ubheight_pc(ll n){
        this->n=n;
        parent=vll(n);
        height=vll(n,1);
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
};

class graph_adjl_weighted{
    vector<vprll> adjl;
    vector<pair<ll,pair<ll,ll>>> edges; //###
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
            edges.push_back({val,{a,b}});//###
        }
    }

    vector<pair<ll,ll>> mst_kruskal(){
        vector<pair<ll,ll>> an;
        srt(edges);
        ll cost=0;
        disjoint_set_ubheight_pc dsu(n);
        FR_AU(xd,edges){
            ll from,to;
            from=xd.second.first;
            to=xd.second.second;
            if(!dsu.is_same_set(from-1,to-1)){
                dsu.union_bheight(from-1,to-1);
                cost+=xd.first;
                an.push_back({from,to});
            }
        }
        //O_ "cost:"<<cost<<EL
        return an;
    }



};




void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m;
    graph_adjl_weighted gr(n,m);
    gr.input_edges();
    vprll an=gr.mst_kruskal();
    FR_AU(xd,an)O_ xd.first<<" "<<xd.second<<EL
}

TEST_DRIVER

/*


 1
5 9
1 2 4
1 5 3
1 4 7
4 2 1
4 5 2
2 5 9
2 3 4
3 4 7
3 5 6



 */