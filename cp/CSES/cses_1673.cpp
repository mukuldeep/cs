//
// Created by me on 20-12-2021.
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
    uompll pos_sl;
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
        if(a==b && val>0){
            pos_sl[a]=1;
        }else {
            adjl[a].push_back({b, val});
        }
    }

    /*
     * Edges input
     */
    void input_edges(){
        ll a,b,val;
        FR_IR(i,0,m) {
            I_ a >> b>>val;
            add_directed_edge(a,b,val);
        }
    }

    bool is_reachable(uompll mp){
        //if(mp[n]==1)return true;
        vll visited(n+1,0);
        qll qu;
        FR_AU(x,mp){
            //O_ x.first<<"+->";
            qu.push(x.first);
            visited[x.first]=1;
        }//O_ EL

        while(!qu.empty()){
            ll fr=qu.front();
            if(fr==n)return true;
            qu.pop();
            FR_AU(xd,adjl[fr]){
                if(!visited[xd.first]){
                    visited[xd.first]=1;
                    qu.push(xd.first);
                }
            }
        }
        return false;
    }

    ll max_score(){
        if(is_reachable(pos_sl))
            return -1;
        ll ans;
        vll max_score_ar(n+1,LONG_LONG_MIN),max_score_pre;
        uompll mp,changingnodes;
        mp[1]=1;
        max_score_ar[1]=0;
        ll flag=0;
        FR_IR(i,0,m+5){
            uompll mp_new;
            ll updated=0;
            FR_AU(xd,mp){
                FR_AU(xxd,adjl[xd.first]){
                    if(max_score_ar[xxd.first]==LONG_LONG_MIN){
                        max_score_ar[xxd.first]=max_score_ar[xd.first]+xxd.second;updated=1;
                    }else{
                        if(max_score_ar[xd.first] + xxd.second>max_score_ar[xxd.first]) {
                            max_score_ar[xxd.first] = max_score_ar[xd.first] + xxd.second;updated=1;
                        }
                    }
                    mp_new[xxd.first]=1;
                }
            }
            if(!updated)
                break;
            mp=mp_new;

           //O_ "map after round "<<i<<": ";
           //FR_AU(xx,mp)O_ xx.first<<" ";O_ EL

            if(i==m-1){
                max_score_pre=max_score_ar;
                flag=1;
            }
        }

        if(flag)
        FR_IR(x, 1, n + 1) {
            if (max_score_ar[x] != max_score_pre[x]) {
                //O_ max_score_pre[x]<<"->"<<max_score_ar[x]<<EL
                changingnodes[x] = 1;
            }
        }

        //O_ is_reachable(changingnodes)<<EL
        if(max_score_ar[n]==LONG_LONG_MIN || is_reachable(changingnodes))
            ans=-1;
        else
            ans=max_score_ar[n];
        return ans;
    }
};

void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m;
    graph_adjl_weighted gr(n,m);
    gr.input_edges();
    O_ gr.max_score()<<EL
}

DRIVER

