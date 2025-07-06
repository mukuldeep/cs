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
     * prims algo for minimum spanning tree
     */
    vprll mst_prims(){
        ll cost=0,cnt=0;
        vll added(n+1,0);
        vprll an;
        priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>> pq;
        added[1]=1;
        FR_AU(xd,adjl[1]){
            pq.push({xd.second,{xd.first,1}});
        }
        cnt=1;
        while(cnt<n && !pq.empty()){
            pair<ll,pair<ll,ll>> fr=pq.top();
            pq.pop();
            if(!added[fr.second.first]){
                an.push_back({fr.second.first,fr.second.second});
                cost+=fr.first;
                added[fr.second.first]=1;
                cnt++;
                FR_AU(xd,adjl[fr.second.first]){
                    if(!added[xd.first]){
                        pq.push({xd.second,{xd.first,fr.second.first}});
                    }
                }
            }
        }
        return an;

    }

};

void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m;
    graph_adjl_weighted gr(n,m);
    gr.input_edges();
    vprll an=gr.mst_prims();
    FR_AU(xd,an){
        O_ xd.first<<" "<<xd.second<<EL
    }
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