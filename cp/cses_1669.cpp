/*
 * Created by me on 02-07-2023.
 */
#include <bits/stdc++.h>
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1; // I t;
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
     * graph dfs vertex using stack<vertex >
     */
    ll dfs_vertex_stack(){
        V(ll) vis(n+1,0);
        V(ll) par(n+1,0);
        stack<ll> st; // vertex stack replacing recursion
        Fi(ss,1,n+1) { // iterating over all vertices. in case for disconnected graph
            if(!vis[ss]) { // if not visited, new disconnected graph found
                st.push(ss);// starting dfs from that vertex
                par[ss] = -1;// parent as -1
                while (!st.empty()) { // until there is vertex in the stack
                    ll curr = st.top();
                    st.pop();

                    if (!vis[curr]) {// visit if not visited
                        vis[curr] = par[curr];// updating vis[] with latest parent
                        Fa(ch, adjl[curr]) { // iterating over children nodes
                            if (!vis[ch]) {// the child vertex still not processed
                                st.push(ch);
                                par[ch] = curr; // updating parent as current parent
                            } else if (vis[curr] != ch) {// not parent # cycle found
                                V(ll) cycle;
                                ll x = curr;
                                cycle.push_back(ch);// starting vertex of the cycle
                                while (vis[x] != ch) {// back tracking to generate cycle, using parent information stored in vis[]
                                    cycle.push_back(x);
                                    x = vis[x];
                                }
                                cycle.push_back(x);
                                cycle.push_back(vis[x]);//ending vertex of the cycle
                                O cycle.size() << El
                                Fa(xx, cycle)O xx << " ";
                                O El
                                return 0;
                            }
                        }
                    }
                }
            }
        }
        return -1;//no cycle found
    }


};


void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    I n>>m;
    graph_adjl_unweighted gr=graph_adjl_unweighted(n,m);
    gr.input_edges();
    if(gr.dfs_vertex_stack()==-1){ // no cycle found
        O "IMPOSSIBLE"<<El
    }
}

Dr
