//
// Created by me on 14-05-2021.
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
    vector<pair<ld,ll>> arr;
    FR_IR(i,0,n){
        I_ a>>b;
        ld angle = atan2(b,a);
        if(angle<0)angle+=2*atan2(0,-1);
        arr.PB_({angle,i+1});
    }
    srt(arr);
//    FR_AU(xd,arr){
//        O_ xd.first<<" "<<xd.second<<EL
//    }
    ld mnd=arr[0].first+2*atan2(0,-1)-arr[n-1].first;
    a=arr[0].second;
    b=arr[n-1].second;
    FR_IR(i,1,n){
        if(arr[i].first-arr[i-1].first<mnd){
            mnd=arr[i].first-arr[i-1].first;
            a=arr[i].second;
            b=arr[i-1].second;
        }
    }
    O_ a<<" "<<b<<EL

}


DRIVER
/*

 10
2 0
2 1
0 2
-1 1
-2 0
-2 1
-2 -1
-1 -2
0 -3
2 -2



 */