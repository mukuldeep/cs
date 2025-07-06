//
// Created by me on 24-04-2021.
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
    ll n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    I_ n>>k;
    vector<vll> trails(n),ans_trails(n,vll(k,0));
    vprll all_path;
    FR_IR(i,0,n){
        FR_IR(j,0,k){
            I_ a;
            trails[i].PB_(a);
            all_path.PB_(MP_(a,i));
        }
        sort(trails[i].rbegin(),trails[i].rend());
    }
    sort(all_path.rbegin(),all_path.rend());
    FR_IR(j,0,k){
        ans_trails[all_path.back().second][j]=all_path.back().first;
        trails[all_path.back().second].pop_back();
        all_path.pop_back();
    }

//    FR_IR(i,0,n) {
//        FR_IR(j, 0, k) {
//            O_ ans_trails[i][j]<<" ";
//        }O_ EL
//    }O_ EL
//
//    FR_AU(xd,trails){
//        FR_AU(xxd,xd){
//            O_ xxd<<" ";
//        }O_ EL
//    }O_ EL

    FR_IR(i,0,n) {
        FR_IR(j, 0, k) {
            if(!ans_trails[i][j]){
                O_ trails[i].back()<<" ";
                trails[i].pop_back();
            }else{
                O_ ans_trails[i][j]<<" ";
            }
        }O_ EL
    }

}

DRIVER
