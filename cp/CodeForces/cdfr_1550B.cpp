//
// Created by me on 14-07-2021.
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
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>a>>b>>str;
    ll c_0=0,c_1=0,l_0=0,l_1=0;
    vll l0,l1;
    if(str[0]-'0'){
        c_1++;
        l_1++;
    }else{
        c_0++;
        l_0++;
    }
    FR_IR(i,1,n){
        if(str[i]-'0'){
            c_1++;
            if(str[i-1]==str[i]){
                l_1++;
            }else{
                l_1=1;
                l0.push_back(l_0);
                l_0=0;
            }
        }else{
            c_0++;
            if(str[i-1]==str[i]){
                l_0++;
            }else{
                l_0=1;
                l1.push_back(l_1);
                l_1=0;
            }
        }
    }
//    O_ "c_0:"<<c_0<<EL
//    O_ "c_1:"<<c_1<<EL
//    O_ "c0:";FR_AU(xd,l0)O_ xd<<" ";O_ EL
//    O_ "c1:";FR_AU(xd,l1)O_ xd<<" ";O_ EL

    if(l_0)l0.push_back(l_0);
    if(l_1)l1.push_back(l_1);

    //if(2*(a+b)>=2*a+b){
        ans=n*(a+b);
        mx=ans;
    //}else{
        //if(c_1>c_0){
        ans=0;
            FR_AU(xd,l0)
                ans+=(a*xd+b);
            if(c_1)ans+=a*c_1+b;
            mx=max(mx,ans);
        //}else{
        ans=0;
            FR_AU(xd,l1)
                ans+=(a*xd+b);
            if(c_0)ans+=a*c_0+b;
            mx=max(mx,ans);
        //}
    //}
    O_ mx<<EL

}

DRIVER
