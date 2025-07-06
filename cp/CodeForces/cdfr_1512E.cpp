//
// Created by me on 11-04-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
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
typedef long long ll;
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
    ll n,l,r,s,a,b,c;
    I_ n>>l>>r>>s;
    a=r-l+1;
    if(s<((a*(a+1))/2) || s>((n*(n+1))/2-((n-a)*(n-a+1))/2)) {
        O_ "-1"<<EL
    }else{
        vll arr(a,0);
        FR_IR(i, 1, a + 1)arr[i-1]=i;
        s-=(a*(a+1))/2;

        for (ll i = a-1; i >= 0; i--) {
            if (s <= 0)break;
            if (s >= (n - a + i+1 - arr[i])) {
                s -= (n - a + i+1 - arr[i]);
                arr[i] += (n - a + i+1 - arr[i]);
            } else {
                arr[i] += s;
                s = 0;
                break;
            }
        }

        ll hsh[505] = {0};
        vll darr;
        FR_AU(x, arr)hsh[x] = 1;
        FR_IR(i, 1, n + 1)if (!hsh[i])darr.PB_(i);
        FR_IR(i, 0, l-1)O_ darr[i] << " ";
        FR_AU(x, arr)O_ x << " ";
        FR_IR(i, l-1, darr.size())O_ darr[i] << " ";
        O_ EL
    }
}

DRIVER
