//
// Created by me on 04-07-2021.
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
    I_ n;
    a=n*n;
    ll x1=1,y1=1,x2=2,y2=1;
    FR_IR(i,0,a){
        I_ b;
        if(b==1){
            if(x2<=n && y2<=n){
                O_ "2 "<<x2<<" "<<y2<<EL
                x2+=2;
                if(x2>n){
                    y2++;
                    if(y2&1)x2=2;
                    else x2=1;
                }
            }else{
                O_ "3 "<<x1<<" "<<y1<<EL
                x1+=2;
                if(x1>n){
                    y1++;
                    if(y1&1)x1=1;
                    else x1=2;
                }
            }
        }else if(b==2){
            if(x1<=n && y1<=n){
                O_ "1 "<<x1<<" "<<y1<<EL
                x1+=2;
                if(x1>n){
                    y1++;
                    if(y1&1)x1=1;
                    else x1=2;
                }
            }else{
                O_ "3 "<<x2<<" "<<y2<<EL
                x2+=2;
                if(x2>n){
                    y2++;
                    if(y2&1)x2=2;
                    else x2=1;
                }
            }
        }else{
            if(x1<=n && y1<=n){
                O_ "1 "<<x1<<" "<<y1<<EL
                x1+=2;
                if(x1>n){
                    y1++;
                    if(y1&1)x1=1;
                    else x1=2;
                }
            }else{
                O_ "2 "<<x2<<" "<<y2<<EL
                x2+=2;
                if(x2>n){
                    y2++;
                    if(y2&1)x2=2;
                    else x2=1;
                }
            }
        }
    }

}

DRIVER
