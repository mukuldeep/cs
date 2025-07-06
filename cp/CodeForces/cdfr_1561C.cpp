//
// Created by me on 24-08-2021.
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
bool sortcustom(const pair<ll,ll> &a,const pair<ll,ll> &b) {
    if (a.first < b.first){
        return true;
    }else if(a.first==b.first){
        return (a.second > b.second);
    }
    return false;
}

void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n;
    vector<pair<ll,ll>> arr;
    //vvll adj(n+1);
    FR_IR(i,0,n){
        I_ k;
        mx=0;
        FR_IR(j,0,k){
            I_ a;
            //adj[i].push_back(a);
            mx=max(mx,a+1-j);
        }
        arr.push_back({mx,k});
    }
    sort(arr.begin(),arr.end());//,sortcustom);
//    FR_AU(xd,arr){
//        O_ xd.first<<" "<<xd.second<<EL
//    }
    ll strt=arr[0].first,extr=0;
    ll curr=strt+arr[0].second;
    FR_IR(i,1,n){
        if(arr[i].first>curr){
            extr+=(arr[i].first-curr);
            curr=arr[i].first;
        }
        curr+=arr[i].second;
    }
    ans=strt+extr;
    O_ ans<<EL
}

DRIVER
