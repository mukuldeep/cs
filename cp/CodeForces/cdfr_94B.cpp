//
// Created by me on 24-07-2021.
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
    I_ m;//n nodes, m vertices
    vvll adjm(6,vll(6,0));//1 indexed
    FR_IR(i,0,m){
        I_ a>>b;
        adjm[a][b]=1;
        adjm[b][a]=1;//undirected
    }
    FR_IR(i,1,6){
        FR_IR(j,1,6){
            if(i==j)continue;
            FR_IR(l,1,6){
                if(l==j || l==i)continue;
                //O_ i<<" "<<j<<" "<<l<<" :"<<adjm[i][j]<<" "<<adjm[j][l]<<" "<<adjm[l][i]<<EL
                if(adjm[i][j]==adjm[j][l] && adjm[j][l]==adjm[l][i]){
                    O_ "WIN"<<EL
                    return;
                }
            }
        }
    }
    O_ "FAIL"<<EL
}

DRIVER
