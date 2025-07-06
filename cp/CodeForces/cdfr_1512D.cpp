//
// Created by me on 10-04-2021.
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
    ll n,k,a,b,c;
    I_ n;
    vll arr(n+2);
    ll sm=0;
    unordered_map<ll,ll> ump;
    FR_IR(i,0,n+2){
        I_ arr[i];
        ump[arr[i]]=i;
        sm+=arr[i];
    }
    ll flag=0,i1,i2;
    FR_IR(i,0,n+2){
        ll lsm=sm-arr[i];
        if(!(lsm&1)){
            if(ump.find(lsm/2)!=ump.end()){
                i1=ump[lsm/2];
                if(i1==i)continue;
                flag=1;
                i2=i;
                break;
            }
        }
    }


    if(flag){
        if(i1==i2){
            FR_IR(i,0,n+2){
                if(i!=i1 && arr[i]==arr[i1]){
                    i2=i;break;
                }
            }
        }
        FR_IR(i,0,n+2){
            if(i!=i1 && i!=i2){
                O_ arr[i]<<" ";
            }
        }O_ EL
    }else{
        O_ -1<<EL
    }


}

DRIVER
