//
// Created by me on 19-07-2021.
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
    I_ n>>m;
    vector<string> grid(n);
    vll an;
    FR_IR(i,0,n){
        I_ grid[i];
    }

    FR_IR(i,0,n-1){
        FR_IR(j,0,m-1){
            if(grid[i][j]=='1'){
                an.push_back(i);an.push_back(j);
                grid[i][j]='0';
                grid[i][j+1]=grid[i][j+1]=='0'?'1':'0';
                grid[i+1][j]=grid[i+1][j]=='0'?'1':'0';
                an.push_back(i);an.push_back(j+1);
                an.push_back(i+1);an.push_back(j);
            }
        }
        if(grid[i][m-1]=='1'){
            an.push_back(i);an.push_back(m-1);
            an.push_back(i+1);an.push_back(m-1);
            an.push_back(i+1);an.push_back(m-2);
            grid[i][m-1]='0';
            grid[i+1][m-1]=grid[i+1][m-1]=='0'?'1':'0';
            grid[i+1][m-2]=grid[i+1][m-2]=='0'?'1':'0';
        }
    }
    FR_IR(j,0,m-1){
        if(grid[n-1][j]=='0')continue;
        if(grid[n-1][j+1]=='1'){
            an.push_back(n-1);an.push_back(j+1);
            an.push_back(n-2);an.push_back(j+1);
            an.push_back(n-2);an.push_back(j);

            an.push_back(n-1);an.push_back(j);
            an.push_back(n-2);an.push_back(j+1);
            an.push_back(n-2);an.push_back(j);

            grid[n-1][j]='0';
            grid[n-1][j+1]='0';

        }else{
            an.push_back(n-1);an.push_back(j+1);
            an.push_back(n-1);an.push_back(j);
            an.push_back(n-2);an.push_back(j+1);

            an.push_back(n-1);an.push_back(j+1);
            an.push_back(n-1);an.push_back(j);
            an.push_back(n-2);an.push_back(j);

            an.push_back(n-2);an.push_back(j+1);
            an.push_back(n-2);an.push_back(j);
            an.push_back(n-1);an.push_back(j);

            grid[n-1][j]='0';
        }
    }
    if(grid[n-1][m-1]=='1'){
        an.push_back(n-1);an.push_back(m-1);
        an.push_back(n-1);an.push_back(m-2);
        an.push_back(n-2);an.push_back(m-1);

        an.push_back(n-1);an.push_back(m-1);
        an.push_back(n-1);an.push_back(m-2);
        an.push_back(n-2);an.push_back(m-2);

        an.push_back(n-2);an.push_back(m-1);
        an.push_back(n-2);an.push_back(m-2);
        an.push_back(n-1);an.push_back(m-1);
    }
    b=an.size()/6;
    O_ b<<EL
    a=0;
    FR_IR(j,0,b){
        FR_IR(i,0,6){
            O_ an[j*6+i]+1<<" ";
        }O_ EL
    }

}
DRIVER
