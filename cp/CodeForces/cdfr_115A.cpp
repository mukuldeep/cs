//
// Created by me on 08-05-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;W_(t)soln(t);return 0;}
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
    ll m,n,k,a,b,c,cnt=0,ans=1,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n;//n nodes, m vertices
    vvll adjl(n+1);//1 indexed
    vll vis(n+1,0);
    queue<pair<ll,ll>> qu;
    FR_IR(i,1,n+1){
        I_ a;
        if(a==-1){qu.push({i,1});mx=1;vis[i]=1;}
        else{
            adjl[a].PB_(i);
        }
    }

    while(!qu.empty()){
        ll em,de;
        em=qu.front().first;
        de=qu.front().second;
        qu.pop();
        mx=max(mx,de);
        FR_AU(xd,adjl[em]){
            if(!vis[xd]){
                qu.push({xd,de+1});
                vis[xd]=1;
            }
        }
    }
//    FR_IR(i,1,n+1){
//        if(!vis[i]){
//            qu.push({i,1});
//            vis[i]=1;
//            mx=max(mx,ans);
//            while(!qu.empty()){
//                ll em,de;
//                em=qu.front().first;
//                de=qu.front().second;
//                qu.pop();
//                mx=max(mx,de);
//                FR_AU(xd,adjl[em]){
//                    if(!vis[xd]){
//                        qu.push({xd,de+1});
//                        vis[xd]=1;
//                    }
//                }
//            }
//        }
//    }
    O_ mx<<EL


}

DRIVER
