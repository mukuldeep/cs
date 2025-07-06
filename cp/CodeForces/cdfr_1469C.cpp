//
// Created by me on 09-07-2021.
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


void soln(ll t) {
    ll m, n, k, a, b, c, cnt = 1, ans = 0, mn = LONG_LONG_MAX, mx = LONG_LONG_MIN;
    string str;
    ll ut, lt, put, plt;
    I_ n >> k;
    vll arr(n);
    I_ arr[0];
    plt = arr[0];
    put = arr[0] + k;
    FR_IR(i, 1, n) {
        I_ arr[i];
        if (cnt) {
            lt = max(arr[i], plt + 1 - k);
            ut = put - 1 + k;
            if (lt > put - 1)cnt = 0;
            if (lt > arr[i] + k - 1)cnt = 0;
            plt = lt;
            put = ut;
        }
    }
    if (cnt && lt <= arr[n - 1] && arr[n - 1] <= ut) {
        reverse(arr.begin(),arr.end());
        plt = arr[0];
        put = arr[0] + k;
        FR_IR(i, 1, n) {
            lt = max(arr[i], plt + 1 - k);
            ut = put - 1 + k;
            if (lt > put - 1){cnt = 0;break;}
            if (lt > arr[i] + k - 1){cnt = 0;break;}
            plt = lt;
            put = ut;
        }
        if (cnt && lt <= arr[n - 1] && arr[n - 1] <= ut)
            O_ "YES" << EL
        else O_ "NO"<<EL
    }else O_ "NO"<<EL
}

DRIVER
