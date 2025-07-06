//
// Created by me on 15-05-2021.
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
ll inf=1e18;

void soln(ll t){
    ll m,n,k,a,b,c,c_ind,tr,cnt=0,ans=inf,mn=inf,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m>>k;tr=m*n-1;
    vll weight(n*m+5),portal;
    vvll adj(n*m+5);
    FR_IR(i,0,n){
        FR_IR(j,0,m) {
            I_ a;
            c_ind = i * m + j;
            weight[c_ind] = a;
        }
    }
    FR_IR(i,0,n){
        FR_IR(j,0,m) {
            c_ind = i * m + j;
            a=weight[c_ind];
            if(a==-1)continue;
            if(a>0)portal.PB_(c_ind);
            if(j>0 && weight[c_ind-1]!=-1)adj[c_ind].PB_(c_ind-1);
            if(j+1<m && weight[c_ind+1]!=-1)adj[c_ind].PB_(c_ind+1);
            if(i>0 && weight[c_ind-m]!=-1)adj[c_ind].PB_(c_ind-m);
            if(i+1<n && weight[c_ind+m]!=-1)adj[c_ind].PB_(c_ind+m);
        }
    }

    //from source
    qll q;
    vector<bool> vis(n*m+5,false);
    vll dist(n*m+5,inf);
    q.push(0);
    dist[0]=0;
    vis[0]=true;
    while (!q.empty()){
        ll ind=q.front();
        q.pop();
        FR_AU(xd,adj[ind]) {
            if (!vis[xd]) {
                vis[xd]=true;
                dist[xd]=dist[ind]+k;
                q.push(xd);
            }
        }
    }

    //from destination
    qll dq;
    vector<bool> dvis(n*m+5,false);
    vll ddist(n*m+5,inf);
    dq.push(tr);
    ddist[tr]=0;
    dvis[tr]=true;
    while (!dq.empty()){
        ll ind=dq.front();
        dq.pop();
        FR_AU(xd,adj[ind]) {
            if (!dvis[xd]) {
                dvis[xd]=true;
                ddist[xd]=ddist[ind]+k;
                dq.push(xd);
            }
        }
    }

    //minm tunnel from source
    ll mn_t_ind=-1,mn_t_dis=LONG_LONG_MAX;
    FR_AU(xd,portal){
        if(dist[xd]!=inf && dist[xd]+weight[xd]<mn_t_dis){
            mn_t_dis=dist[xd]+weight[xd];
            mn_t_ind=xd;
        }
    }

    //min tunnel to other tunnel
    if(mn_t_ind>-1){
        FR_AU(xd,portal){
            if(xd!=mn_t_ind){
                if(ddist[xd]!=inf){
                    mn=min(mn,dist[mn_t_ind]+weight[mn_t_ind]+weight[xd]+ddist[xd]);
                }
            }
        }
    }

    if(dist[tr]<inf)mn=min(mn,dist[tr]);

    if(mn==inf)mn=-1;
    O_ mn<<EL
}

DRIVER
