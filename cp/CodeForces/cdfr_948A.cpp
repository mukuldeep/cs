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
    ll r,c,k,a,b,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ r>>c;
    vector<string> grid(r);
    vector<vector<bool>> vis(r,vector<bool>(c, false));
    queue<pair<ll,ll>> qu;
    FR_IR(i,0,r){
        I_ grid[i];
        FR_IR(j,0,c){
            if(grid[i][j]=='.')grid[i][j]='D';
            else if(grid[i][j]=='W')vis[i][j]=true,qu.push({i,j});
        }
    }
    while(!qu.empty()){
        ll i,j;
        i=qu.front().first;
        j=qu.front().second;
        qu.pop();
        if(i>0)if(grid[i-1][j]=='S'){cnt=1;break;}
        if(i<r-1)if(grid[i+1][j]=='S'){cnt=1;break;}
        if(j>0)if(grid[i][j-1]=='S'){cnt=1;break;}
        if(j<c-1)if(grid[i][j+1]=='S'){cnt=1;break;}
    }
    if(cnt)O_ "No"<<EL
    else{
        O_ "Yes"<<EL
        FR_IR(i,0,r){
            O_ grid[i]<<EL
        }
    }

}

DRIVER
