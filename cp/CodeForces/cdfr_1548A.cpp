//
// Created by me on 07-09-2021.
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
    ll n,m,ini_cnt,lcnt;
    vll edges,smaller;
public:
    graph_adjl_unweighted(ll n,ll m){
        this->m=m;
        this->n=n;
        adjl=vvll (n+1);
        edges=vll(n+1,0);
        smaller=vll(n+1,0);
        ini_cnt=lcnt=0;

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

    void calc(){
        FR_IR(i,1,n+1){
            edges[i]=adjl[i].size();
            ll cnt=0;
            FR_AU(xd,adjl[i]){
                if(xd<i)cnt++;
            }
            smaller[i]=cnt;
            if(smaller[i]==edges[i])ini_cnt++;
        }
        lcnt=ini_cnt;
    }
    void q3(){
        O_ lcnt<<EL
    }
    void q2(ll u, ll v){
        ll isuadded,isvadded;
        if(edges[u]==smaller[u])isuadded=1;else isuadded=0;
        if(edges[v]==smaller[v])isvadded=1;else isvadded=0;

        edges[u]--;
        edges[v]--;
        if(u<v){
            smaller[v]--;
            if(isuadded)lcnt--;
            else if(edges[u]==smaller[u])lcnt++;
        }else{
            smaller[u]--;
            if(isvadded)lcnt--;
            else if(edges[v]==smaller[v])lcnt++;
        }
    }
    void q1(ll u, ll v){
        ll isuadded,isvadded;
        if(edges[u]==smaller[u])isuadded=1;else isuadded=0;
        if(edges[v]==smaller[v])isvadded=1;else isvadded=0;

        edges[u]++;
        edges[v]++;
        if(u<v){
            smaller[v]++;
            if(isuadded)lcnt--;
            else if(edges[u]==smaller[u])lcnt++;
        }else{
            smaller[u]++;
            if(isvadded)lcnt--;
            else if(edges[v]==smaller[v])lcnt++;
        }
    }


};


void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    I_ n>>m;
    graph_adjl_unweighted gr(n,m);
    gr.input_edges();
    gr.calc();
    I_ k;
    W_(k){
        I_ a;
        if(a==3){
            gr.q3();
        }else{
            I_ b>>c;
            if(a==1){
                gr.q1(b,c);
            }else{
                gr.q2(b,c);
            }
        }
    }
}

DRIVER
