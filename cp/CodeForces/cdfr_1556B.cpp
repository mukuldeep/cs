//
// Created by me on 29-08-2021.
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

ll cnt_swap(vll od,ll n){
    ll ans=0;
    for(ll i=n-1;i>=0;i-=2){
        if(od.empty())break;
        if(i!=od.back()){
            ans+=abs(i-od.back());
        }
        od.pop_back();
    }

    return ans;
}
void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n;
    vll arr(n);
    ll c_o=0,c_e=0;
    vll oddpos,evenpos;
    FR_IR(i,0,n){
        I_ arr[i];
        if(arr[i]&1){
            c_o++;
            oddpos.push_back(i);
        }else{
            c_e++;
            evenpos.push_back(i);
        }
    }

    if(abs(c_e-c_o)>1){
        O_ -1<<EL
        return;
    }
    if(c_e==c_o){
        ans=min(cnt_swap(oddpos,n),cnt_swap(evenpos,n));
    }else if(c_e>c_o){
        ans=cnt_swap(evenpos,n);
    }else{
        ans=cnt_swap(oddpos,n);
    }
    O_ ans<<EL

}

DRIVER
