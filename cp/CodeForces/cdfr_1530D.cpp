//
// Created by me on 17-07-2021.
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


void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n;//n nodes, m vertices
    vvll adj(n+1),adj2(n+1);//1 indexed
    FR_IR(i,1,n+1){
        I_ a;
        adj[a].PB_(i);
        adj2[i].push_back(a);
    }
    vll assig(n+1,-1),assig2(n+1,-1),giver(n+1,0),taker(n+1,0);
    FR_IR(i,1,n+1){
        FR_AU(xd,adj[i]){
            if(assig[xd]==-1){
                assig[xd]=i;
                assig2[i]=xd;
                giver[xd]=1;
                taker[i]=1;
                cnt++;
                break;
            }
        }
    }
    vll rest_giver,rest_taker;

    FR_IR(i,1,n+1){
        if(!giver[i])rest_giver.push_back(i);
        if(!taker[i])rest_taker.push_back(i);
    }
    if(rest_giver.size()>1){
        if(rest_giver[0]==rest_taker[0]){
            swap(rest_giver[0],rest_giver[1]);
        }
    }
    FR_IR(i,1,rest_giver.size()){
        if(rest_giver[i]==rest_taker[i]){
            swap(rest_giver[i],rest_giver[i-1]);
        }
    }
    FR_IR(i,0,rest_giver.size()){
        if(rest_giver[i]==rest_taker[i]){

            FR_IR(j,0,adj[adj2[rest_taker[i]][0]].size()){
                if(assig[adj[adj2[rest_giver[i]][0]][j]]!=-1){
                    //swap old with new
                    ll o_g,o_t,n_g,n_t;
                    o_g=adj[adj2[rest_giver[i]][0]][j];
                    o_t=assig[adj[adj2[rest_giver[i]][0]][j]];
                    n_g=rest_taker[i];
                    n_t=o_t;

                    assig[o_g]=-1;
                    rest_giver[i]=o_g;
                    assig[n_g]=n_t;
                    assig2[n_t]=n_g;
                    break;
                }
            }
        }
    }

    while(!rest_giver.empty()){
        assig[rest_giver.back()]=rest_taker.back();
        rest_giver.pop_back();
        rest_taker.pop_back();
    }
    O_ cnt<<EL
    FR_IR(i,1,n+1){
        O_ assig[i]<<" ";
    }O_ EL
}
DRIVER
