//
// Created by me on 21-06-2021.
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
    I_ n;
    vll odd,even;
    FR_IR(i,1,n+1){
        if(i&1)odd.push_back(i);
        else even.push_back(i);
    }
    O_ "2\n";
    while(odd.size()+even.size()>1){
        if(odd.size()>1 && even.size()>1){
            if(odd.size()>even.size()){
                O_ odd.back()<<" "; a=odd.back();odd.pop_back();
                O_ odd.back()<<" \n";a+=odd.back();odd.pop_back();
                a/=2;
            }else{
                O_ even.back()<<" "; a=even.back();even.pop_back();
                O_ even.back()<<" \n";a+=even.back();even.pop_back();
                a/=2;
            }
            if(a&1)odd.push_back(a);else even.push_back(a);
        }else if(odd.size()>1){
            O_ odd.back()<<" "; a=odd.back();odd.pop_back();
            O_ odd.back()<<" \n";a+=odd.back();odd.pop_back();
            a/=2;
            if(a&1)odd.push_back(a);else even.push_back(a);
        }else if(even.size()>1){
            O_ even.back()<<" "; a=even.back();even.pop_back();
            O_ even.back()<<" \n";a+=even.back();even.pop_back();
            a/=2;
            if(a&1)odd.push_back(a);else even.push_back(a);
        }else if(even.size()==1 && odd.size()==1){
            O_ even.back()<<" "<<odd.back()<<EL
            even.pop_back();
            odd.pop_back();
        }
    }

}

DRIVER
