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


void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    unsigned long long an=0;
    I_ n>>k>>m;
    vll arr(n);
    FR_IR(i,0,n){
        I_ arr[i];
    }
    rsrt(arr);
    while(arr.size()>2*k){
        an+=arr.back();
        arr.pop_back();
    }
    a=0;
    dqll q(arr.begin(),arr.end());
    while(!q.empty()){
        if(q.size()==1){
            a+=q.front();
            q.pop_front();
            continue;
        }
        if(q.front()+q.back()>=m){
            a+=m;
            q.pop_back();
            q.pop_front();
        }else{
            a+=q.front();
            q.pop_front();
        }
    }
    b=0;
    reverse(arr.begin(),arr.end());
    while(arr.size()>1){
        if(arr.back()+arr[arr.size()-2]>=m){
            b+=m;
            arr.pop_back();
            arr.pop_back();
        }else{
            break;
        }
    }
    FR_AU(xd,arr)b+=xd;
    an+=min(a,b);
    O_ an<<EL
}

DRIVER
