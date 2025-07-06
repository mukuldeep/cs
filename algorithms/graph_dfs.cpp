//
// Created by me on 02-05-2021.
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
 * graph dfs vertex recursion
 *
 */
void dfs_util(vvll &adjl,ll n, ll s,vll &vis){
    O_ s<<" ";
    FR_AU(xd,adjl[s]){
        if(!vis[xd]){
            vis[xd]=1;
            dfs_util(adjl,n,xd,vis);
        }
    }
}
void dfs_vertex(vvll &adjl,ll n, ll s){
    vll vis(n+1,0);
    vis[s]=1;
    dfs_util(adjl,n,s,vis);

}

/*
 * graph dfs vertex using stack pair<vertex,adj no>
 *
 */
void dfs_vertex_stack_old(vvll &adjl,ll n, ll s){
    vll vis(n+1,0);
    stack<pair<ll,ll>> st;
    O_ s<<" ";
    vis[s]=1;
    st.push({s,0});
    while(!st.empty()){
        pair<ll,ll> curr=st.top();
        st.pop();
        if(adjl[curr.first].size()>curr.second+1){
            st.push({curr.first,curr.second+1});
        }
        if(!vis[adjl[curr.first][curr.second]]){

            vis[adjl[curr.first][curr.second]]=1;
            if(adjl[adjl[curr.first][curr.second]].size()>0){
                st.push({adjl[curr.first][curr.second],0});
            }
            O_ st.top().first<<" ";
        }
    }

}

/*
 * graph dfs vertex using stack< adjl of a vertex >
 * may differ travarsal result
 */
void dfs_vertex_stack(vvll &adjl,ll n, ll s){
    vll vis(n+1,0);
    stack<vll> st;
    O_ s<<" ";
    vis[s]=1;
    st.push(adjl[s]);
    while(!st.empty()){
        ll curr=st.top().back();
        st.top().pop_back();
        if(st.top().empty())
            st.pop();

        if(!vis[curr]){
            vis[curr]=1;
            O_ curr<<" ";
            if(!adjl[curr].empty())
                st.push(adjl[curr]);
        }
    }

}

void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m;//n nodes, m vertices
    vvll adjl(n+1);//1 indexed
    FR_IR(i,0,m){
        I_ a>>b;
        adjl[a].PB_(b);
        adjl[b].PB_(a);//undirected
    }
    dfs_vertex(adjl,n,3);
    O_ EL
    dfs_vertex_stack(adjl,n,3);
    O_ EL
}

TEST_DRIVER
/*
1
5 5
1 2
1 3
1 4
2 3
3 5


 1
5 6
1 2
1 3
1 4
2 3
2 4
3 5

1
 15 14
 1 9
 1 12
 9 3
 3 10
 10 7
 10 8
 7 5
 5 2
 8 13
 13 6
 13 14
 13 15
 15 4
 15 11
 */