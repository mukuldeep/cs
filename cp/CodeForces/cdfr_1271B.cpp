//
// Created by me on 17-08-2021.
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
vll clc(string str,ll n){
    vll an,pp;
    FR_IR(i,0,n-1){
        if(str[i]=='B'){
            an.push_back(i+1);
            str[i]='W';
            if(str[i+1]=='B')str[i+1]='W';
            else str[i+1]='B';
        }
    }
    if(str[n-1]=='W'){
        if(an.empty())an.push_back(-1);
        return an;
    }
    else return pp;
}

void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str,str2;
    I_ n>>str;
    str2=str;
    vll wrr=clc(str,n);
    if(wrr.empty()){
        FR_IR(i,0,n){
            if(str2[i]=='W')str2[i]='B';
            else str2[i]='W';
        }
        vll brr=clc(str2,n);
        if(brr.empty()){
            O_ -1<<EL
        }else{
            if(brr[0]==-1){
                O_ 0<<EL
                return;
            }
            O_ brr.size()<<EL
            FR_AU(xd,brr)O_ xd<<" ";O_ EL
        }
    }else{
        if(wrr[0]==-1){
            O_ 0<<EL
            return;
        }
        O_ wrr.size()<<EL
        FR_AU(xd,wrr)O_ xd<<" ";O_ EL
    }

}

DRIVER
