//
// Created by me on 02-05-2021.
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
    ll m,n,k,a=0,b=0,c=0,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ str;
    vvll ar(3);
    FR_IR(i,0,str.length()){
        if('A'<=str[i] && str[i]<='Z'){
            a++;
            ar[0].PB_(i);
        }else if('a'<=str[i] && str[i]<='z'){
            b++;
            ar[1].PB_(i);
        }else{
            c++;
            ar[2].PB_(i);
        }
    }
    //O_ a<<" "<<b<<" "<<c<<EL
    if(a==str.length())str[1]='a',str[2]='1';
    else if(b==str.length())str[1]='A',str[2]='1';
    else if(c==str.length())str[1]='a',str[2]='A';

    else if(a==0){
        if(ar[1].size()>1){
            str[ar[1][1]]='A';
        }else{
            str[ar[2][1]]='A';
        }
    }else if(b==0){
        if(ar[0].size()>1){
            str[ar[0][1]]='a';
        }else{
            str[ar[2][1]]='a';
        }
    }else if(c==0){
        if(ar[0].size()>1){
            str[ar[0][1]]='1';
        }else{
            str[ar[1][1]]='1';
        }
    }
    O_ str<<EL

}
DRIVER
