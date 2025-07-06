//
// Created by me on 07-04-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){SYNC ll t=1;W_(t)soln(t);return 0;}
#define FR_(a,c)   for (ll (a)=0;(a)<(c); (a)++)
#define FR_E(a,c)   for (ll (a)=0;(a)<=(c); (a)++)
#define FR_IR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FR_AU(xx,xxs) for(auto (xx):(xxs))
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
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef vector<pair<ll, ll>> vprll;
typedef map<ll,ll>  mpll;
typedef unordered_map<ll,ll> uompll;
const ll t9p7=1000000007;

vector<vll> apsp_floydWarshall (vector<vll> graph,ll v)
{
    ll i, j, k;
    vector<vll> dist(v,vll(v,0));
    FR_IR(i,0,v)
        FR_IR(j,0,v)
            dist[i][j] = graph[i][j];

    FR_IR(k,0,v)
        FR_IR(i,0,v)
            FR_IR(j,0,v)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    return dist;
}

void soln(ll t){
    ll n,m,q,k,a,b,c;
    I_ n>>m>>q;
    vector<vll> adjm(n,vll(n));
    FR_IR(i,0,n)
        FR_IR(j,0,n)
            adjm[i][j]=10000000000000000;
    FR_IR(i,0,n)adjm[i][i]=0;
    FR_IR(i,0,m){
        I_ a>>b>>c;
        adjm[a-1][b-1]=min(c,adjm[a-1][b-1]);
        adjm[b-1][a-1]=min(c,adjm[b-1][a-1]);
    }
    vector<vll> cost;
    cost=apsp_floydWarshall(adjm,n);

    FR_IR(i,0,q){
        I_ a>>b;
        ll ans=min(cost[a-1][b-1],cost[b-1][a-1]);
        if(ans==10000000000000000)
            ans=-1;
        O_ ans<<EL
    }

}

DRIVER
