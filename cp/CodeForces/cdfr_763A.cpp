//
// Created by me on 06-10-2021.
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
public:
    vvll adjl;
    ll n,m;
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


};
/*
 * graph dfs vertex recursion
 *
 */
void dfs_util(vvll &adjl,ll s,vll &vis,vll &colr, ll col,bool &ans){
    //O_ s<<" ";
    FR_AU(xd,adjl[s]){
        if(!vis[xd]){
            vis[xd]=1;
            if(col!=colr[xd])ans=false;
            if(ans)dfs_util(adjl,xd,vis,colr,col,ans);
        }
        if(!ans)break;
    }
}





void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n;
    vprll arr(n-1);
    vll col(n+1);
    graph_adjl_unweighted gr(n,n-1);
    FR_IR(i,0,n-1){
        I_ arr[i].first>>arr[i].second;
        gr.add_undirected_edge(arr[i].first,arr[i].second);
    }
    FR_IR(i,1,n+1){
        I_ col[i];
    }
    a=0;b=0;
    FR_IR(i,0,n-1){
        if(col[arr[i].first]!=col[arr[i].second]){
            a=arr[i].first;
            b=arr[i].second;
            break;
        }
    }
    //O_ "ab: "<<a<<" "<<b<<EL
    if(!a){
        O_ "YES\n1"<<EL
    }else{
        vll vis(n+1,0);
        vis[a]=1;
        bool xx=true;
        FR_AU(xd,gr.adjl[a]) {
            vis[xd]=1;
            dfs_util(gr.adjl, xd, vis, col, col[xd], xx);
        }
        if(!xx){
            xx=true;
            vll vis2(n+1,0);
            vis2[b]=1;
            FR_AU(xd,gr.adjl[b]) {
                vis2[xd]=1;
                dfs_util(gr.adjl, xd, vis2, col, col[xd], xx);
            }
            if(xx){
                O_ "YES\n"<<b<<EL
            }else{
                O_ "NO"<<EL
            }
        }else{
            O_ "YES\n"<<a<<EL
        }

    }

}

DRIVER
