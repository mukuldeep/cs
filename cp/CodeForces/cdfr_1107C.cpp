//
// Created by me on 07-07-2021.
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
    I_ n>>k;
    vll arr(n);
    FR_IR(i,0,n){
        I_ arr[i];
    }
    I_ str;
    if(n==1){O_ arr[0]<<EL return;}
    a=1,b=0;
    FR_IR(i,1,n){
        if(str[i]==str[i-1])a++;
        else{
            //O_ i<<" "<<a<<" "<<EL
            if(a>k){sort(arr.begin()+i-a,arr.begin()+i);a=k;}
            //O_ "arr:";FR_AU(xd,arr)O_ xd<<" ";O_ EL
            //O_ i-1<<" to "<<i-a<<EL
            for(ll j=i-1;j>=i-a;j--)ans+=arr[j];
            a=1;
        }
    }
    if(a>k){sort(arr.begin()+n-a,arr.begin()+n);a=k;}
    //O_ "arr:";FR_AU(xd,arr)O_ xd<<" ";O_ EL
    //O_ n-1<<" to "<<n-a<<EL
    for(ll j=n-1;j>=n-a;j--)ans+=arr[j];

    O_ ans<<EL

}
DRIVER
