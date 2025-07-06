//
// Created by me on 22-08-2021.
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

string next(string num)
{
    int i,l = num.size();
    for (i=l-1; i>=0; i--)
    {
        if (num.at(i) == '0')
        {
            num.at(i) = '1';
            break;
        }else
            num.at(i) = '0';
    }
    if (i < 0)
        num = "1" + num;
    return num;
}

void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n;

    unordered_map<string,ll> mp;
    FR_IR(i,0,n){
        I_ str;
        mp[str]=1;
    }
    str="";
    FR_IR(i,0,n)str+="0";
//    FR_IR(i,0,10)
//    {
//        //O_":"<<str<<EL
//        str=next(str);
//        while(str.size()<n)str="0"+str;
//    }
    while(mp[str]){
        str=next(str);
        while(str.size()<n)str="0"+str;
    }
    O_ str<<EL
}

DRIVER
