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
bool is_overlap(ll l1,ll r1,ll l2,ll r2 ){
    l1++;l2++;
    if((l2<=l1 && l1<=r2)||(l2<=r1 && r1<=r2) || (l1<=l2 && l2<=r1)||(l1<=r2 && r2<=r1))
        return true;
    return false;
}

void soln(ll t){
    O_ "Case #"<<t<<": ";
    ll m,n,k,a,b,c,cnt=0,ans=1e18,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>k;
    vll brr(n+1),psm_b(n+2);
    psm_b[0]=0;
    FR_IR(i,0,n){
        I_ brr[i];
        psm_b[i+1]=psm_b[i]+brr[i];
    }
    unordered_map<ll,vector<pair<ll,ll>>> mp;
    FR_IR(i,1,n+1){
        for(ll j=0;j<=n-i;j++){

            ll tot_b=psm_b[j+i]-psm_b[j];
            //O_ "("<<j<<","<<j+i<<")="<<tot_b<<" ";
            if(tot_b<=k){
                if(tot_b==k)ans=min(ans,i);
                FR_AU(xd,mp[k-tot_b]){//
                    if(!is_overlap(j,j+i,xd.first,xd.second)){
                        ans=min(ans,xd.second-xd.first+i);
                        break;
                    }
                    if(xd.second-xd.first+i>=ans)break;
                }
                mp[tot_b].push_back({j,j+i});
            }
        }
        //O_ EL
    }
    if(ans==1e18)ans=-1;
    O_ ans<<EL
}

DRIVER
