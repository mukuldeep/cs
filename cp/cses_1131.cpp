/*
 * Created by me on 26-06-2023.
 * Problem: finding diameter of a tree. Diameter is the maximum distance between two nodes amongst all pair of nodes.
 * Time complexity: O(2n) (as every node visited twice), = O(n) where n is number of nodes.
 */
#include <bits/stdc++.h>
//#define DEBUG
//#define DEBUG_LOG
//#define TESTCASES

#ifdef TESTCASES
#define TEST_ENABLE I t;
#else
#define TEST_ENABLE
#endif
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1; TEST_ENABLE // I t;

#ifndef DEBUG
#define Drt int main(){Sync W(t)soln(t);return 0;}
#else
#define Drt int cc_main(){Sync W(t)soln(t);return 0;}
#endif

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

#ifdef DEBUG_LOG
#define D(x) O x
#else
#define D(x)
#endif
//functions
#define p_bin(x) if(x)O "YES"<<El else O "NO"<<El

//constants
#define t9p7 1000000007
#define INF 100000000000000000 //1e17
using namespace std;

void pre(){

}

class graph_adjl_unweighted{
    V(V(ll)) adjl;
    ll n,m;
    public:
    V(ll) height;
    ll diameter=-1;
    graph_adjl_unweighted(ll n,ll m){
        this->m=m;
        this->n=n;
        adjl=vector<V(ll)> (n+1);
        height=V(ll) (n+1,0);
    }

    /*
     * add edges
     */
    void add_undirected_edge(ll a,ll b,ll val){
        adjl[a].push_back(b);
        adjl[b].push_back(a);
    }
    void add_directed_edge(ll a,ll b,ll val){
        adjl[a].push_back(b);
    }

    /*
     * Edges input
     */
    void input_edges(){
        ll a,b,val=0;
        Fi(i,0,m) {
            I a >> b;
            add_undirected_edge(a,b,val);
        }
    }
    /*
     * Prints height stored in height[] for all nodes
     * for Debug only
     */
    void print_height(){
#ifdef DEBUG
        Fi(i,1,n+1) {
            D("\t" << i;)
        }
        D( El)
        Fi(i,1,n+1) {
            D("\t" << height[i];)
        }
        D( El)
#endif
    }
/*
 * graph dfs vertex recursion
 *
 */
    void dfs_util(ll s,V(ll) &vis){
        D( "visiting:"<<s<<El)

        Fa(xd,adjl[s]){
            if(!vis[xd]){
                vis[xd]=1;
                dfs_util(xd,vis);
            }
        }

        ll mx1=-1,mx2=-1;
        Fa(xd,adjl[s]){
            if(height[xd]>mx1) {
                mx2 = mx1;
                mx1=height[xd];
            }else if(height[xd]>mx2){
                mx2=height[xd];
            }
        }

        if(adjl[s].empty()){
            // s is leaf node. update height as 1.
            height[s]=1;
        }else{
            // height is maximum of all children +1
            height[s]=mx1+1;
        }
        // If the current node the topmost node in the diameter,
        // then two children with max height will form diameter
        diameter=max(diameter,((mx1!=-1)?mx1:0) + ((mx2!=-1)?mx2:0));
        D( "diam:"<<s<<"->"<<diameter<<" mx1:"<<mx1<<" mx2:"<<mx2<<El)
        print_height();
    }
    void dfs_vertex(ll s){
        V(ll) vis(n+1,0);
        vis[s]=1;
        dfs_util(s,vis);
    }
};




void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    I n;
    graph_adjl_unweighted gr=graph_adjl_unweighted(n,n-1);
    gr.input_edges();
    gr.dfs_vertex(1);
    D("diameter:"<<gr.diameter<<El)
    O gr.diameter<<El
}

Drt
/*
 5
1 2
1 3
3 4
3 5

ans: 3

12
1 2
1 3
3 4
3 5
5 12
5 11
4 6
4 7
6 8
6 9
6 10
ans: 5


15
1 3
3 4 3 5
5 12 5 11
4 6 4 7
6 8 6 9 6 10
7 2
2 13 2 14
13 15
ans: 7

15
1 3
3 4 3 5
5 11
4 6 4 7
6 8 6 9 6 10
9 12
7 2
2 13 2 14
13 15
ans: 7
 */
