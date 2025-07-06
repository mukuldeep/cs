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
    ll n,k,a,b,c;
    I_ n>>k;
    vll coins(n);
    vector<vll> sum_arr(n+1,vll(k+1,0));
    FR_IR(i,0,n){
        I_ coins[i];
    }
    coins.PB_(0);
    sort(coins.begin(),coins.end());
    FR_IR(ci,0,n+1)sum_arr[ci][0]=1;
    //FR_IR(sumi,1,k+1)sum_arr[0][sumi]=0;

//    FR_IR(ci,0,n+1) {
//        O_ "C:"<<coins[ci]<<" ";
//        FR_IR(sumi, 0, k + 1) {
//            O_ sum_arr[ci][sumi]<<" ";
//        }O_ EL
//    }

    FR_IR(ci,1,n+1){
        FR_IR(sumi,1,k+1){
            sum_arr[ci][sumi]=sum_arr[ci-1][sumi];
            if(sumi-coins[ci]>=0){
                sum_arr[ci][sumi]+=sum_arr[ci][sumi-coins[ci]];
                sum_arr[ci][sumi]%=t9p7;
            }

        }
    }


//    FR_IR(ci,0,n+1) {
//        O_ "C:"<<coins[ci]<<" ";
//        FR_IR(sumi, 0, k + 1) {
//            O_ sum_arr[ci][sumi]<<" ";
//        }O_ EL
//    }

    O_ sum_arr[n][k]<<EL
}

DRIVER
