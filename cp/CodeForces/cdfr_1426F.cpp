//
// Created by me on 27-04-2021.
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
    string str;
    I_ n>>str;
    vector<vll> arr(n+1,vll(3,0));
    c=1;
    FR_IR(i,1,n+1){
        if(str[i-1]=='a'){
            arr[i][0]=arr[i-1][0]+c;
            arr[i][1]=arr[i-1][1];
            arr[i][2]=arr[i-1][2];
        }else if(str[i-1]=='b'){
            arr[i][1]=arr[i-1][1]+arr[i-1][0];
            arr[i][0]=arr[i-1][0];
            arr[i][2]=arr[i-1][2];
        }else if(str[i-1]=='c'){
            arr[i][2]=arr[i-1][2]+arr[i-1][1];
            arr[i][0]=arr[i-1][0];
            arr[i][1]=arr[i-1][1];
        }else if(str[i-1]=='?'){
            arr[i][0]=3*arr[i-1][0]+c;
            arr[i][1]=3*arr[i-1][1]+arr[i-1][0];
            arr[i][2]=3*arr[i-1][2]+arr[i-1][1];
            c*=3;
        }

        arr[i][0]%=t9p7;
        arr[i][1]%=t9p7;
        arr[i][2]%=t9p7;
        c%=t9p7;
    }
    O_ arr[n][2]<<EL

}

DRIVER
