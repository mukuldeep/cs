//
// Created by me on 01-07-2021.
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


void soln(ll t){
    ll m,n,k,ar,ap,as,cr=0,cp=0,cs=0,mr,mp,ms,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str,str2;
    I_ n>>ar>>ap>>as>>str;
    FR_IR(i,0,n){
        if(str[i]=='R')cr++;
        else if(str[i]=='P')cp++;
        else cs++;
    }
    mr=min(ar,cs);
    mp=min(ap,cr);
    ms=min(as,cp);

    if((mr+mp+ms)>=ceil((ld)n/2.0)){
        O_ "YES"<<EL
        FR_IR(i,0,n){
            if(str[i]=='R'){
                if(mp){
                    mp--;
                    ap--;
                    str2+="P";
                }else if(ar>mr){
                    ar--;
                    str2+="R";
                }else{
                    as--;
                    str2+="S";
                }
            }else if(str[i]=='P'){
                if(ms){
                    ms--;
                    as--;
                    str2+="S";
                }else if(ap>mp){
                    ap--;
                    str2+="P";
                }else{
                    ar--;
                    str2+="R";
                }
            }else{
                if(mr){
                    mr--;
                    ar--;
                    str2+="R";
                }else if(as>ms){
                    as--;
                    str2+="S";
                }else{
                    ap--;
                    str2+="P";
                }
            }
        }
        O_ str2<<EL
    }else{
        O_ "NO"<<EL
    }



}

DRIVER
