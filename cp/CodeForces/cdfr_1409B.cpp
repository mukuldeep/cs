//
// Created by me on 15-04-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define FR_(a,c)   for (ll (a)=0;(a)<(c); (a)++)
#define FR_E(a,c)   for (ll (a)=0;(a)<=(c); (a)++)
#define FR_IR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FR_AU(xx,xxs) for(auto (xx):(xxs))
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
typedef stack<ll> skll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef vector<pair<ll, ll>> vprll;
typedef map<ll,ll>  mpll;
typedef unordered_map<ll,ll> uompll;
typedef set<ll> stll;
const ll t9p7=1000000007;


void soln(ll t){
    ll n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    ll dn,dk,da,db,dc;
    string str;
    I_ a>>b>>c>>k>>n;
    dn=n,dk=k,da=a,db=b,dc=c;
    if(k==1 && b-1==n)mn=a;
    if(c==1 && a-1==n)mn=min(mn,b);

    if(n>a-c){
        n-=a-c;
        a=c;
    }else{
        a-=n;
        n=0;
    }
    if(n>b-k){
        b=k;
    }else{
        b-=n;
    }
    mn=min(mn,a*b);

    if(dn>db-dk){
        dn-=db-dk;
        db=dk;
    }else{
        db-=dn;
        dn=0;
    }
    if(dn>da-dc){
        da=dc;
    }else{
        da-=dn;
    }
    mn=min(mn,da*db);
    O_ mn<<EL

}

DRIVER
