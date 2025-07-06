//
// Created by me on 30-07-2021.
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

bool is_valid(ll x,ll y,ll n,ll m){
    if(0<=x && x<m && 0<=y && y<=n)
        return true;
    return false;
}


long long min_time_to_infect(vector<vector<long long int>> &grid,queue<pair<ll,pair<ll,ll>>> &qu, ll n, ll m, ll cnt){
    if(!cnt){
        return 0;
    }
    if(qu.empty())
        return -1;
    ll time=-1;
    while(!qu.empty()){
        pair<ll,pair<ll,ll>> curr_pos=qu.front();
        qu.pop();
        ll i,j,depth;
        i=curr_pos.first;
        j=curr_pos.second.first;
        depth=curr_pos.second.second;

        if(is_valid(i-1,j,n,m)){//up
            if(grid[i-1][j]==1){
                qu.push({i-1,{j,depth+1}});
                grid[i-1][j]=2;
                time=max(time,depth+1);
            }
        }

        if(is_valid(i+1,j,n,m)){//down
            if(grid[i+1][j]==1){
                qu.push({i+1,{j,depth+1}});
                grid[i+1][j]=2;
                time=max(time,depth+1);
            }
        }

        if(is_valid(i,j-1,n,m)){//left
            if(grid[i][j-1]==1){
                qu.push({i,{j-1,depth+1}});
                grid[i][j-1]=2;
                time=max(time,depth+1);
            }
        }
        if(is_valid(i,j+1,n,m)){//right
            if(grid[i][j+1]==1){
                qu.push({i,{j+1,depth+1}});
                grid[i][j+1]=2;
                time=max(time,depth+1);
            }
        }
    }

    bool flag=1;
    for(ll i=0;i<n;i++) {
        if(flag)
        for (ll j = 0; j < m; j++) {
            if(grid[i][j]==1){
                flag=0;
                break;
            }
        }
    }
    if(flag)return time;
    return -1;

}
void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    cin>>n>>m;
    vector<vector<long long int>> grid(n,vector<long long int>(m));
    queue<pair<ll,pair<ll,ll>>> qu;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]==2){
                qu.push({i,{j,0}});
            }else if(grid[i][j]==1){
                cnt++;
            }
        }
    }

    ans=min_time_to_infect(grid,qu,n,m,cnt);
    cout<<ans<<endl;
}

TEST_DRIVER
/*
 3 3
2 1 1
0 1 2
0 0 1

 3 3
 2 1 1
 0 1 1
 0 0 1

 3 3
 2 1 1
 0 1 2
 1 0 1

 */