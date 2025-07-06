//
// Created by me on 30-03-2021.
//
#include <bits/stdc++.h>
#define DRIVER int main(){ll t=1;while(t--)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){ll t=1;W_(t)soln(t);return 0;}
#define FR_(a,c)   for (ll (a)=0;(a)<(c); (a)++)
#define FR_E(a,c)   for (ll (a)=0;(a)<=(c); (a)++)
#define FR_IR(a,s,e) for(ll (a)=(s);(a)<(e);(a)++)
#define FR_AU(xx,xxs) for(auto (xx):(xxs))
#define W_(n) while((n)--)
#define WH_ while
#define IL_ while(1)
#define PB_ push_back
#define MP_(a,b) make_pair((a),(b))
#define O_ cout<<
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
typedef map<ll,pair<ll, ll>>  mpllp;
typedef unordered_map<ll,ll> uompll;
typedef unordered_map<ll,pair<ll, ll>> uompllp;
typedef hash<ll> hll;

void soln(ll t){
    ll n,k,a,b,c,f=0;
    I_ n;
    vll arr;
    vll hshx(5000005,0),hshy(5000005,0);
    FR_(i,n){
        I_ k;
        arr.PB_(k);
    }

    FR_IR(i,0,n){
        FR_IR(j,i+1,n){
            a=arr[i]+arr[j];
            if(hshx[a]){
                if(hshy[a]!=i+1 && hshy[a]!=j+1 && hshx[a]!=i+1 && hshx[a]!=j+1) {
                    b = i+1;
                    c = j+1;
                    k = hshx[a];
                    a = hshy[a];
                    //cout << " mp[a].sec:" << mp[a].second << endl;
                    f = 1;
                    break;
                }
            }else{
                hshx[a]=i+1;
                hshy[a]=j+1;
            }
        }
        if(f)break;
    }
    if(f) {
        O_ "YES" << EL;
        O_ a<<" "<<k<<" "<<b<<" "<<c<<EL;
    }else {
        O_ "NO" << EL;
    }

}

DRIVER
