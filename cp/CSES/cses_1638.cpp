//
// Created by me on 07-04-2021.
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
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef vector<pair<ll, ll>> vprll;
typedef map<ll,ll>  mpll;
typedef unordered_map<ll,ll> uompll;
const ll t9p7=1000000007;



void soln(ll t){
    ll n,k,a,b,c=0;
    I_ n;
    string str;
    vector<string> grid;
    FR_IR(i,0,n){
        cin>>str;
        grid.PB_(str);
    }
    vector<vll> pthsm(n+1,vll(n+1,0));

    FR_IR(i,0,n){
        if(grid[0][i]=='.')pthsm[0][i]=1;else break;
    }
    FR_IR(i,0,n){
        if(grid[i][0]=='.')pthsm[i][0]=1; else break;
    }

//    FR_IR(i,0,n){
//        FR_IR(j,0,n){
//            O_ pthsm[i][j]<<" ";
//        }O_ EL
//    }

    FR_IR(i,1,n){
        FR_IR(j,1,n){
            if(grid[i][j]=='*')continue;
            pthsm[i][j]=pthsm[i-1][j]+pthsm[i][j-1];
            pthsm[i][j]%=t9p7;
        }
    }
//    FR_IR(i,0,n){
//        FR_IR(j,0,n){
//            O_ pthsm[i][j]<<" ";
//        }O_ EL
//    }

    O_ pthsm[n-1][n-1]<<EL
}

DRIVER