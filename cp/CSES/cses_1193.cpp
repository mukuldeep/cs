//
// Created by me on 15-04-2021.
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
typedef int ll;
typedef long double ld;
typedef vector<ll> vll;
typedef stack<ll> skll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef vector<pair<ll, ll>> vprll;
typedef map<ll,ll>  mpll;
typedef unordered_map<ll,ll> uompll;
typedef set<ll> stll;
const ll t9p7=1000000007;

ll bfs(vector<string> &grid,ll st_x,ll st_y,ll en_x,ll en_y,ll n,ll m){
    queue<pair<ll,ll>> qq;
    qq.push(MP_(st_y,st_x));
    //vis[st_y][st_x]=1;
    //par[st_y][st_x]='O';
    pair<ll,ll> curr;
    while(!qq.empty()){
        curr=qq.front();
        qq.pop();

        if(curr.first){
            if(grid[curr.first-1][curr.second]=='.'){
                grid[curr.first-1][curr.second]='D';
                qq.push(MP_(curr.first-1,curr.second));
            }else if(grid[curr.first-1][curr.second]=='B'){
                grid[curr.first-1][curr.second]='D';
                return 1;
            }
        }

        if(curr.second){
            if(grid[curr.first][curr.second-1]=='.'){
                grid[curr.first][curr.second-1]='R';
                qq.push(MP_(curr.first,curr.second-1));
            }else if(grid[curr.first][curr.second-1]=='B'){
                grid[curr.first][curr.second-1]='R';
                return 1;
            }
        }

        if(curr.first<(n-1)){
            if(grid[curr.first+1][curr.second]=='.'){
                grid[curr.first+1][curr.second]='U';
                qq.push(MP_(curr.first+1,curr.second));
            }else if(grid[curr.first+1][curr.second]=='B'){
                grid[curr.first+1][curr.second]='U';
                return 1;
            }
        }

        if(curr.second<(m-1)){
            if(grid[curr.first][curr.second+1]=='.'){
                grid[curr.first][curr.second+1]='L';
                qq.push(MP_(curr.first,curr.second+1));
            } else if(grid[curr.first][curr.second+1]=='B'){
                grid[curr.first][curr.second+1]='L';
                return 1;
            }

        }
    }

    return 0;
}

void soln(ll t){
    ll n,m,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    ll st_x,st_y,en_x,en_y;
    string str;
    I_ n>>m;
    vector<string> grid;

    FR_IR(i,0,n){
        I_ str;
        FR_IR(j,0,m){
            if(str[j]=='A')st_x=j,st_y=i;
            else if(str[j]=='B')en_x=j,en_y=i;
        }
        grid.PB_(str);
    }




    if(bfs(grid,st_x,st_y,en_x,en_y,n,m)){
        O_ "YES"<<EL
        str="";
        while(grid[en_y][en_x]!='A'){
            switch (grid[en_y][en_x]) {
                case 'U':   str+="D";
                    en_y--;
                    break;
                case 'D':   str+="U";
                    en_y++;
                    break;
                case 'L':   str+="R";
                    en_x--;
                    break;
                case 'R':   str+="L";
                    en_x++;
                    break;
            }
        }
        reverse(str.begin(),str.end());
        O_ str.length()<<EL
        O_ str<<EL
    }else{
        O_ "NO"<<EL
    }
}

DRIVER
