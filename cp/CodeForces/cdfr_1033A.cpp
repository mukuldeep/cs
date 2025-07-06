//
// Created by me on 09-05-2021.
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
    I_ n;
    vector<vector<bool>> vis(n+1,vector<bool>(n+1, false));
    I_ a>>b;
    FR_IR(i,1,n+1){
        vis[a][i]=true;
        vis[i][b]=true;
    }
    m=a,k=b;
    while(m>0 && k>0){
        vis[m][k]=true;
        m--;k--;
    }
    m=a,k=b;
    while(m<=n && k<=n){
        vis[m][k]=true;
        m++;k++;
    }
    m=a,k=b;
    while(m>0 && k<=n){
        vis[m][k]=true;
        m--;k++;
    }
    m=a,k=b;
    while(m<=n && k>0){
        vis[m][k]=true;
        m++;k--;
    }

    I_ a>>b;
    queue<pair<ll,ll>> qu;
    qu.push({a,b});
    I_ a>>b;
    while(!qu.empty()){
        m=qu.front().first;
        k=qu.front().second;
        qu.pop();
        if(m==a && k==b){
            O_ "YES"<<EL
            return;
        }
        if(m+1<=n){//d
            if(!vis[m+1][k]){
                qu.push({m+1,k});
                vis[m+1][k]=true;
            }
            if(k+1<=n){//r
                if(!vis[m+1][k+1]){
                    qu.push({m+1,k+1});
                    vis[m+1][k+1]=true;
                }
            }
            if(k-1>0){//l
                if(!vis[m+1][k-1]){
                    qu.push({m+1,k-1});
                    vis[m+1][k-1]=true;
                }
            }
        }
        if(m-1>0){//u
            if(!vis[m-1][k]){
                qu.push({m-1,k});
                vis[m-1][k]=true;
            }
            if(k+1<=n){//r
                if(!vis[m-1][k+1]){
                    qu.push({m-1,k+1});
                    vis[m-1][k+1]=true;
                }
            }
            if(k-1>0){//l
                if(!vis[m-1][k-1]){
                    qu.push({m-1,k-1});
                    vis[m-1][k-1]=true;
                }
            }
        }
        if(k+1<=n){//r
            if(!vis[m][k+1]){
                qu.push({m,k+1});
                vis[m][k+1]=true;
            }
        }
        if(k-1>0){//l
            if(!vis[m][k-1]){
                qu.push({m,k-1});
                vis[m][k-1]=true;
            }
        }


    }
    O_ "NO"<<EL
}

DRIVER
