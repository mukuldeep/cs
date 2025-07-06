//
// Created by me on 1-4-2021.
//
#include <bits/stdc++.h>
#define DRIVER int main(){ll t=1;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){ll t=1;W_(t)soln(t);return 0;}
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
#define I_ cin>>
#define EL endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef vector<pair<ll, ll>> vprll;
typedef map<ll,ll>  mpll;
typedef unordered_map<ll,ll> uompll;
typedef vector<vll> vvll;

void max_ber(ll arr[][6],ll h,ll w,ll c_h,ll c_w,ll c_cnt, ll &mx_cnt,ll dir=0){
    if(c_h>=h || c_w>=w)return;
    c_cnt+=arr[c_h][c_w];
    mx_cnt=max(mx_cnt,c_cnt);
    if(dir==0){
        max_ber(arr,h,w,c_h+1,c_w,c_cnt,mx_cnt,1);
        max_ber(arr,h,w,c_h,c_w+1,c_cnt,mx_cnt,2);
    }else{
        if(dir==1)max_ber(arr,h,w,c_h,c_w+1,c_cnt,mx_cnt,2);
        else max_ber(arr,h,w,c_h+1,c_w,c_cnt,mx_cnt,1);
    }
}
ll next_found(vvll &arr,ll h,ll w,ll &x, ll &y){
    vector<pair<ll,pair<ll,ll>>> mp;
    FR_IR(i,x,h){
        FR_IR(j,y,w){
            if(arr[i][j]){
                mp.push_back({abs(x-i)+abs(y-j),{i,j}});
            }
        }
    }
    sort(mp.begin(),mp.end());
    if(mp.empty())return 0;
    if(mp[0].first==0){
        if(mp.size()==1)return 0;
        x=mp[1].second.first;
        y=mp[1].second.second;
    }else{
        x=mp[0].second.first;
        y=mp[0].second.second;
    }
    return 1;
}
ll max_calc(vvll arr,ll h, ll w){
    ll cnt=0,x=0,y=0;
    if(arr[0][0])cnt++;
    while(next_found(arr,h,w,x,y)){
        cnt++;
    }
    return cnt;
}

void soln(ll t){
    ll n,k,a,b,c=0,h,w;
    vvll arr(6,vll(6,0));
    string str;
    I_ h>>w;
    FR_IR(i,0,h){
        I_ str;
        FR_IR(j,0,w){
            if(str[j]=='*')arr[i][j]=1;
        }
    }
    c=max_calc(arr,h,w);
    O_ c<<EL

}

DRIVER
