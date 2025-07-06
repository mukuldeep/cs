//
// Created by me on 03-10-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();
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

void pre(){

}

class graph_adjl_unweighted{
    vvll adjl;
    vll vl;
    ll n,m,xr_val;
public:
    graph_adjl_unweighted(ll n,ll m){
        this->m=m;
        this->n=n;
        vl=vll(n+1);
        adjl=vvll (n+1);
        xr_val=0;
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
        FR_IR(i,1,n+1){
            I_ vl[i];
            xr_val^=vl[i];
        }
        FR_IR(i,0,m) {
            I_ a >> b;
            add_undirected_edge(a,b);
        }

    }

    /*
     * graph dfs vertex recursion
     *
     */
    ll dfs_util(ll s,vll &vis,ll &f){
        //O_ s<<EL;
        ll xr_v=vl[s];
        FR_AU(xd,adjl[s]){
            if(f)break;
            if(!vis[xd]){
                vis[xd]=1;
                ll xr_ch=dfs_util(xd,vis,f);
                if(f)break;
                xr_v^=xr_ch;
                if(xr_ch==xr_val){
                    f=1;
                    for (auto it = adjl[s].begin(); it != adjl[s].end(); ++it){
                        if(*it==xd){
                            adjl[s].erase(it);
                            break;
                        }
                    }
                    for (auto it = adjl[xd].begin(); it != adjl[xd].end(); ++it){
                        if(*it==s){
                            adjl[xd].erase(it);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return xr_v;
    }

    ll dfs_vertex(ll k){
        ll s=1;
        vll vis(n+1,0);
        ll f=0;
        vis[s]=1;
        dfs_util(s,vis,f);
        if(f){
            f=0;
            vll vis2(n+1,0);
            dfs_util(s,vis2,f);
            if(f && k>2){
                return 1;
            }else{
                return 0;
            }
        }else{
            return 0;
        }

    }



    bool is_possible(ll k){
        if(!xr_val)return true;
        return dfs_vertex(k);
    }


};





void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>k;
    graph_adjl_unweighted gr(n,n-1);
    gr.input_edges();
    if(gr.is_possible(k)){
        O_ "YES"<<EL
    }else{
        O_ "NO"<<EL
    }
}

DRIVER
