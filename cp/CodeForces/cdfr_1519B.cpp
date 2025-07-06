//
// Created by me on 29-04-2021.
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
    I_ m>>n>>k;
    vector<vector<set<ll>>> grid(m+1,vector<set<ll>>(n+1));
    FR_IR(i,1,m+1) {
        grid[i][1].insert(i - 1);
        //FR_AU(xd,grid[i][1])O_ xd<<" ";
    }//O_ EL
    FR_IR(i,1,n+1)
        grid[1][i].insert(i-1);

    FR_IR(i,2,m+1) {
        FR_IR(j, 2, n + 1) {
            FR_AU(xd, grid[i - 1][j]) {
                if (xd + j <= k)
                    grid[i][j].insert(xd + j);
            }
            FR_AU(xd, grid[i][j - 1]) {
                if (xd + i <= k)
                    grid[i][j].insert(xd + i);
            }
//            O_ "[";
//            FR_AU(xd, grid[i][j])O_ xd << ",";
//            O_ "] ";
        }
        //O_ EL
    }
//    FR_AU(xd,grid[m][n])
//        O_ xd<<" ";
//    O_ EL

    if(grid[m][n].find(k)!=grid[m][n].end()){
        O_ "YES"<<EL
    }else{
        O_ "NO"<<EL
    }

}

DRIVER
