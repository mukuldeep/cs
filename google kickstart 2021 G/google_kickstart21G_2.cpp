//
// Created by me on 16-10-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;I_ t;FR_IR(i,1,t+1)soln(i);return 0;}
#define FR_IR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FR_AU(xx,xxs) for(auto (xx):(xxs))
#define O_ cout<<
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
ll calc_dist(vprll &arr,ll m){
    ll dist=0;
    FR_AU(xd,arr){
        if(m<xd.first){
            dist+=(xd.first-m);
        }else if(m>xd.second){
            dist+=(m-xd.second);
        }
    }
    return dist;
}

ll ternarySearch(ll l,ll r,vprll &ar)
{
    if(l==r)return l;
    uompll mp;
    ll temp;
    temp=calc_dist(ar,l);
    mp[l]=temp==0?1e18:temp;
    temp=calc_dist(ar,r);
    mp[r]=temp==0?1e18:temp;

    while (r > l) {
        ll mid1 = l + (r - l) / 3;
        ll mid2 = r - (r - l) / 3;

        if(!mp[mid1]){
            temp=calc_dist(ar,mid1);
            mp[mid1]=temp==0?1e18:temp;
        }
        if(!mp[mid2]){
            temp=calc_dist(ar,mid2);
            mp[mid2]=temp==0?1e18:temp;
        }

        if (mp[mid1]==mp[l]){
            return l;
        }

        if ((mp[mid1]==1e18?0:mp[mid1])> (mp[mid2]==1e18?0:mp[mid2])) {
            l = mid1;
        }else{
            r=mid2;
        }
        if((r-l)<10){
            ll mnm=l-1,mn_vl=calc_dist(ar,l-1);
            for(ll i=l;i<=r;i++){
                ll xx=calc_dist(ar,i);
                if(mn_vl>xx){
                    mn_vl=xx;
                    mnm=i;
                }
            }
            return mnm;
        }
    }
    return l;
}

void soln(ll t){
    O_ "Case #"<<t<<": ";
    ll m,n,k,a,b,c,d,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ k;
    vprll xar,yar;
    ll mn_x=1e10,mn_y=1e10,mx_x=-1e10,mx_y=-1e10;
    FR_IR(i,0,k){
        I_ a>>b>>c>>d;
        xar.push_back({a,c});
        yar.push_back({b,d});
        mn_x=min(mn_x,a);
        mn_y=min(mn_y,b);
        mx_x=max(mx_x,c);
        mx_y=max(mx_y,d);
    }

    //O_ mn_x<<" "<<mn_y<<" - "<<mx_x<<" "<<mx_y<<EL
    ll an_x=ternarySearch(mn_x,mx_x,xar);
    ll an_y=ternarySearch(mn_y,mx_y,yar);

    O_ an_x<<" "<<an_y<<EL
}

DRIVER
