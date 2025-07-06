//
// Created by me on 16-05-2021.
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
    char ch;
    I_ n>>m;
    vll arr(n);
    vprll o_ar,e_ar;
    uompll ansmp;
    FR_IR(i,0,n){
        I_ arr[i];
    }
    FR_IR(i,0,n){
        I_ ch;
        if(arr[i]&1)o_ar.PB_({arr[i],ch=='L'?0:1});
        else e_ar.PB_({arr[i],ch=='L'?0:1});
    }
    srt(o_ar);
    srt(e_ar);
    stack<pair<ll,ll>> o_st,e_st;
    //for odd
    FR_AU(xd,o_ar){
        if(xd.second==1){
            o_st.push(xd);
        }else{
            if(!o_st.empty()){
                if(o_st.top().second==1){
                    c=(xd.first-o_st.top().first)>>1;
                }else {
                    c = (xd.first + o_st.top().first) >> 1;
                }
                ansmp[xd.first]=c;
                ansmp[o_st.top().first]=c;
                o_st.pop();
            }else{
                o_st.push(xd);
            }
        }
    }
    while(o_st.size()>1){
        pair<ll,ll> ap;
        ap=o_st.top();o_st.pop();
        if(o_st.top().second==1){
            c=(m-ap.first+m-o_st.top().first)>>1;
        }else{
            c=(m-ap.first+m+o_st.top().first)>>1;
        }
        ansmp[ap.first]=c;
        ansmp[o_st.top().first]=c;
        o_st.pop();
    }
    if(!o_st.empty()){
        ansmp[o_st.top().first]=-1;
        o_st.pop();
    }
    //fr enev
    FR_AU(xd,e_ar){
        if(xd.second==1){
            e_st.push(xd);
        }else{
            if(!e_st.empty()){
                if(e_st.top().second==1){
                    c=(xd.first-e_st.top().first)>>1;
                }else {
                    c = (xd.first + e_st.top().first) >> 1;
                }
                ansmp[xd.first]=c;
                ansmp[e_st.top().first]=c;
                e_st.pop();
            }else{
                e_st.push(xd);
            }
        }
    }
    while(e_st.size()>1){
        pair<ll,ll> ap;
        ap=e_st.top();e_st.pop();
        if(e_st.top().second==1){
            c=(m-ap.first+m-e_st.top().first)>>1;
        }else{
            c=(m-ap.first+m+e_st.top().first)>>1;
        }
        ansmp[ap.first]=c;
        ansmp[e_st.top().first]=c;
        e_st.pop();
    }
    if(!e_st.empty()){
        ansmp[e_st.top().first]=-1;
        e_st.pop();
    }

    FR_IR(i,0,n) {
        O_ ansmp[arr[i]]<<" ";
    }O_ EL

}

DRIVER
