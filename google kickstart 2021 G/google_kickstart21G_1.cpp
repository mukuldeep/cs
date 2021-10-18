//
// Created by me on 16-10-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;I_ t;FR_IR(i,1,t+1)soln(i);return 0;}
#define FR_IR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define O_ cout<<
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
    O_ "Case #"<<t<<": ";
    ll m,n,k,a,b,c,d,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>d>>c>>m>>str;
    cnt=n;
    FR_IR(i,0,n){
        if(str[i]=='D'){
            if(d>0){
                d--;
                c+=m;
            }else{
                cnt=i;
                break;
            }
        }else{
            if(c>0){
                c--;
            }else{
                cnt=i;
                break;
            }
        }
    }
    ll f=1;
    for(ll i=cnt;i<n;i++){
        if(str[i]=='D'){
            f=0;
            break;
        }
    }
    if(f)O_ "YES";
    else O_ "NO";

    O_ EL
}

DRIVER

