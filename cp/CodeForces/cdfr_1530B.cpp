//
// Created by me on 17-07-2021.
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

void print_ar(vvll arr){
    FR_AU(xd,arr){
        FR_AU(xxd,xd){
            O_ xxd;
        }O_ EL
    }
    O_ EL
}
void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ a>>b;
    ll ca=0,cb=0;
    vvll arr(a,vll(b,0)),brr(a,vll(b,0));
    FR_IR(i,0,b){
        if(i&1){arr[0][i]=1;ca++;}
        else{brr[0][i]=1;cb++;}
    }
    FR_IR(i,1,a){
        if(!arr[i-1][b-2] && !arr[i-1][b-1]){arr[i][b-1]=1;ca++;}
        if(!brr[i-1][b-2] && !brr[i-1][b-1]){brr[i][b-1]=1;cb++;}
    }
    for(ll i=b-2;i>=0;i--){
        if(!arr[a-2][i+1] && !arr[a-1][i+1]){arr[a-1][i]=1;ca++;}
        if(!brr[a-2][i+1] && !brr[a-1][i+1]){brr[a-1][i]=1;cb++;}
    }
    for(ll i=a-2;i>0;i--){
        if(!arr[i+1][1] && !arr[i+1][0] && !arr[i-1][1] && !arr[i-1][0]){arr[i][0]=1;ca++;}
        if(!brr[i+1][1] && !brr[i+1][0] && !brr[i-1][1] && !brr[i-1][0]){brr[i][0]=1;cb++;}
    }

    if(ca>cb){
        print_ar(arr);
    }else{
        print_ar(brr);
    }

}

DRIVER
