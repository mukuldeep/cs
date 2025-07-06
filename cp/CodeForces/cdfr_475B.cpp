//
// Created by me on 25-07-2021.
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

ll index_calc(ll r,ll c,ll m){
    return r*m+c;
}
/*
 * graph dfs vertex recursion
 *
 */
void dfs_util(vvll &adjl,ll n, ll s,vll &vis){
    //O_ s<<" ";
    FR_AU(xd,adjl[s]){
        if(!vis[xd]){
            vis[xd]=1;
            dfs_util(adjl,n,xd,vis);
        }
    }
}
bool dfs_vertex(vvll &adjl,vvll &adjlr,ll n, ll s){
    vll vis(n+1,0),visr(n+1,0);
    vis[s]=1;visr[s]=1;
    dfs_util(adjl,n,s,vis);
    dfs_util(adjlr,n,s,visr);
    FR_IR(i,0,n){
        if(visr[i]==0 || vis[i]==0)
            return false;
    }
    return true;
}
void print_vll(vll arr){
    FR_AU(xd,arr)O_ xd<<" ";O_ EL
}
void print_vvll(vvll aarr){
    FR_IR(i,0,aarr.size()){
        O_ i<<": ";
        print_vll(aarr[i]);
    }
}
void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str,col,row;
    I_ n>>m;
    vvll adjl(n*m+1),adjlr(n*m+1);
    I_ row>>col;

    FR_IR(i,0,n){
            FR_IR(j, 1, m) {
                ll a1,a2;
                a1=index_calc(i,j-1,m);
                a2=index_calc(i,j,m);
                if(row[i]=='>') {
                    adjl[a1].push_back(a2);
                    adjlr[a2].push_back(a1);
                }else {
                    adjlr[a1].push_back(a2);
                    adjl[a2].push_back(a1);
                }
            }
    }
    FR_IR(j,0,m){
        FR_IR(i, 1, n) {
            ll a1,a2;
            a1=index_calc(i-1,j,m);
            a2=index_calc(i,j,m);
            if(col[j]=='v') {
                adjl[a1].push_back(a2);
                adjlr[a2].push_back(a1);
            }else {
                adjlr[a1].push_back(a2);
                adjl[a2].push_back(a1);
            }
        }
    }
    //print_vvll(adjl);
    //print_vvll(adjlr);
    if(dfs_vertex(adjl,adjlr,m*n,0))
        O_ "YES"<<EL
    else
        O_ "NO"<<EL
}

DRIVER
