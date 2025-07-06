//
// Created by me on 14-08-2021.
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
    ll m,n,k,a=-1,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str,str2;
    I_ n>>m>>str>>str2;
    FR_IR(i,0,n){
        if(str[i]=='*'){
            a=i;
            break;
        }
    }
    if(a==-1){
        if(str==str2)O_ "YES"<<EL
        else O_ "NO"<<EL
    }else{
        if(m<n-1)O_ "NO"<<EL
        else{
//            O_ str.substr(0,a)<<EL
//            O_ str2.substr(0,a)<<EL
//            O_ str.substr(a+1,n-a)<<EL
//            O_ str2.substr(m-n+a+1,n-a)<<EL

            if(str.substr(0,a)==str2.substr(0,a) && str.substr(a+1,n-a)==str2.substr(m-n+a+1,n-a))
                O_ "YES"<<EL
            else
                O_ "NO"<<EL
        }
    }

}

DRIVER
