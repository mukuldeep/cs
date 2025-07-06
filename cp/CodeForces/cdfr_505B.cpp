//
// Created by me on 07-07-2021.
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
    ll m,n,k,a,b,c,cnt=0,ans=0,f,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m;//n nodes, m vertices
    vector<vvll> adjl(m+1,vvll(n+1));//1 indexed
    vvll adj_cols(n+1);
    vll collist,col_hash(m+1,0);
    FR_IR(i,0,m){
        I_ a>>b>>c;
        adjl[c][a].PB_(b);
        adjl[c][b].PB_(a);//undirected
        //adj_cols[a].push_back(c);
        //adj_cols[b].push_back(c);
        if(!col_hash[c]){
            col_hash[c]=1;
            collist.push_back(c);
        }
    }
    I_ m;
    FR_IR(i,0,m){
        I_ a>>b;
        cnt=0;
        FR_AU(xd,collist) {
            vll vis(n + 1, 0);
            qll q;
            q.push(a);
            vis[a]=1;
            f=0;
            while(!q.empty()){
                c=q.front();
                q.pop();
                FR_AU(xx,adjl[xd][c]){
                    if(!vis[xx]){
                        if(xx==b){cnt++;f=1;break;}
                        vis[xx]=1;
                        q.push(xx);
                    }
                }
                if(f)break;
            }
        }
        O_ cnt<<EL
    }
}
DRIVER
