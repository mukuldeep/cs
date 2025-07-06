//
// Created by me on 26-07-2021.
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
    ll m,n,k=0,a,b,c,cnt=0,ans=0,f=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n;
    vector<vprll> to(n+1),from(n+1);
    FR_IR(i,0,n){
        I_ a>>b>>c;
        k+=c;
        to[b].push_back({a,c});
        from[a].push_back({b,c});
    }
    vll vis(n+1,0);
    vis[1]=1;
    c=1;
    if(from[c].size()){
        FR_AU(xd,from[c]){
            if(!vis[xd.first]){
                c=xd.first;
                vis[c]=1;
                f=1;
                break;
            }
        }

    }
    if(f==0){
        FR_AU(xd,to[c]){
            if(!vis[xd.first]){
                c=xd.first;
                vis[c]=1;
                ans+=xd.second;
                break;
            }
        }
    }
    //O_ c<<" ";
    cnt=1;
    while(c!=1){
        f=0;
        if(from[c].size()){
            FR_AU(xd,from[c]){
                if(!vis[xd.first] || (cnt==n && xd.first==1)){
                    c=xd.first;
                    vis[c]=1;
                    f=1;
                    break;
                }
            }

        }
        if(f==0){
            FR_AU(xd,to[c]){
                if(!vis[xd.first] || (cnt==n && xd.first==1)){
                    c=xd.first;
                    vis[c]=1;
                    ans+=xd.second;
                    break;
                }
            }
        }
        cnt++;
        //O_ c<<" ";
    }
    O_ min(ans,k-ans)<<EL
}

DRIVER
