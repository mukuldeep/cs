//
// Created by me on 04-07-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();
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
typedef long long int ll;
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

vll sq_fac(1e7,0);
void pre(){
    FR_IR(i,2,3163){
        ll sq=i*i;
       for(ll j=sq;j<1e7;j+=sq){
           sq_fac[j]=sq;
       }
    }
//    FR_IR(i,0,100){
//        O_ i<<":";
//        FR_AU(xd,sq_fac[i])O_ xd<<" ";O_ EL
//    }
}
void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>k;
    vll arr(n);
    FR_IR(i,0,n){
        I_ arr[i];
        while(sq_fac[arr[i]]){
            arr[i]/=sq_fac[arr[i]];
        }
        //O_ arr[i]<<" ";
    }//O_ EL
    skll st;
    vector<bool> vis(1e7+5,false);

    FR_IR(i,0,n){
        if(vis[arr[i]]) {
            cnt++;
            while (!st.empty()) {
                vis[st.top()] = false;
                st.pop();
            }
        }
        st.push(arr[i]);
        vis[arr[i]]=true;
    }
    if(!st.empty())cnt++;
    O_ cnt<<EL
}
DRIVER
