/*
 * Created by me on 28-02-2022.
 */
#include <bits/stdc++.h>
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1;  //I t;
#define Dr int main(){Sync W(t)soln(t);return 0;}
#define Drt int cc_main(){Sync W(t)soln(t);return 0;}
#define F(a,c) for (ll a=0;a<c; a++)
#define Fe(a,c) for(ll a=0;a<=c; a++)
#define Fi(i,s,e) for(ll i=s;i<e;i++)
#define Rfi(i,s,e) for(ll i=s;i>e;i--)
#define Fa(xx,xxs) for(auto xx:xxs)
#define Srt(x) sort(x.begin(),x.end());
#define Rsrt(x) sort(x.rbegin(),x.rend());
#define Rev(x) reverse(x.begin(),x.end());
#define W(n) while(n--)
#define Wh while
#define Il while(1)
#define Pb push_back
#define O cout<<
#define Prcn fixed<<setprecision(20)
#define I cin>>
#define El endl;
//ds
#define ll long long
#define ld long double
#define S string
#define Ch char
#define V(x) vector<x>
#define Vv(x) V(V(x))
#define Sk(x) stack<x>
#define St(x) set<x>
#define Q(x) queue<x>
#define Dq(x) deque<x>
#define P(x) pair<x,x>
#define P2(x,y) pair<x,y>
#define Mp(x,y) map<x,y>
#define Uom(x,y) unordered_map<x,y>

//functions
#define p_bin(x) if(x)O "YES"<<El else O "NO"<<El

//constants
#define t9p7 1000000007
#define INF 100000000000000000 //1e17
using namespace std;

void pre(){

}



class graph_adjl_unweighted{
    Vv(ll) adjl;
    ll n,m;
public:
    graph_adjl_unweighted(ll n,ll m){
        this->m=m;
        this->n=n;
        adjl=Vv(ll) (n+1);
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
        Fi(i,0,m) {
            I a >> b;
            add_undirected_edge(a,b);
        }
    }



        /*
         * finds all the bridges
         * 1-indexed nodes input
         */
        void find_bridges_dfs(ll curr,V(bool) &visited,V(ll) &t_in,V(ll) &t_min,ll &timer,V(P(ll)) &bridges, ll p = -1) {
            visited[curr] = true;
            t_in[curr] = t_min[curr] = timer++;
            Fa(to,adjl[curr]) {
                if (to == p) continue;//if to is parent don't go
                if (visited[to]) {//if to already visited
                    t_min[curr] = min(t_min[curr], t_in[to]);//update low of curr ver with time in of to if smaller
                } else {
                    find_bridges_dfs(to,visited,t_in,t_min,timer,bridges, curr);//
                    t_min[curr] = min(t_min[curr], t_min[to]);//low of curr vertex = min (low of curr_vertex & to_vertex)
                    if (t_min[to] > t_in[curr])//no back edge, if back edge t_low(to_ver) reach smaller than t_in[curr_v)
                        if(curr<to) {
                            bridges.push_back({curr, to});//pushing back answers
                        }else{
                            bridges.push_back({to, curr});//pushing back answers
                        }
                }
            }
        }
        V(P(ll)) find_bridges() {
            ll timer = 0;
            V(bool) visited;
            V(ll) t_in, t_low;
            V(P(ll)) bridges;

            visited.assign(n+1, false);
            t_in.assign(n+1, -1);
            t_low.assign(n+1, -1);

            Fi(i,1,n+1) {
                if (!visited[i])
                    find_bridges_dfs(i,visited,t_in,t_low,timer,bridges);
            }

            /*Fa(xx,bridges){
                O xx.first<<" "<<xx.second<<El
            }*/

            return bridges;
        }



};



void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    while(cin>>n) {
        //O k<<El
        S s;
        graph_adjl_unweighted gr(n, 1);
        F(i, n) {
            I a >> s;
            S ss = s.substr(1, s.size() - 2);
            ll m = stoi(ss);
            Fi(i, 0, m) {
                I b;
                gr.add_undirected_edge(a + 1, b + 1);
            }
        }
        V(P(ll)) bd = gr.find_bridges();
        Srt(bd);
        O bd.size() << " critical links" << El
        Fa(xx, bd) {
            O xx.first - 1 << " - " << xx.second - 1 << El
        }
        O El
    }
 }

Drt



