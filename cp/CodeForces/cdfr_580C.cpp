//
// Created by me on 27-06-2021.
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


void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m;//n nodes, m vertices
    vvll adjl(n+1);//1 indexed
    vll cat(n+1),con_cat(n+1,0),mx_con_cat(n+1,0),vis(n+1,0);
    FR_IR(i,1,n+1){
        I_ cat[i];
    }
    FR_IR(i,0,n-1){
        I_ a>>b;
        adjl[a].PB_(b);
        adjl[b].PB_(a);//undirected
    }
    qll q;
    q.push(1);
    vis[1]=1;
    if(cat[1])con_cat[1]++;
    mx_con_cat[1]=con_cat[1];
    while(!q.empty()){
        a=q.front();
        q.pop();
        b=0;
        FR_AU(xd,adjl[a]){
            if(!vis[xd]){
                vis[xd]=1;
                q.push(xd);
                b++;
                if(cat[xd]){
                    con_cat[xd]=con_cat[a]+1;
                }
                mx_con_cat[xd]=max(mx_con_cat[a],con_cat[xd]);
            }
        }
        if(!b){
            if(mx_con_cat[a]<=m)cnt++;
        }

    }
//    FR_IR(i,1,n+1){
//        O_ con_cat[i]<<" ";
//    }O_ EL
//    FR_IR(i,1,n+1){
//        O_ mx_con_cat[i]<<" ";
//    }O_ EL

    O_ cnt<<EL




}
DRIVER
