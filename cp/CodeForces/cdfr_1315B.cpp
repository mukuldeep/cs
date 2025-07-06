//
// Created by me on 02-07-2021.
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
    I_ a>>b>>c>>str;
    n=str.length();
    ans=n;
    if(str[n-2]=='A'){
        if(a>c){
            O_ n<<EL
            return;
        }else{
            c-=a;
            ans=n-1;
        }
    }else{
        if(b>c){
            O_ n<<EL
            return;
        }else{
            c-=b;
            ans=n-1;
        }
    }
    for(ll i=n-3;i>=0;i--){
        if(str[i]==str[i+1]){
            ans--;
        }else{
            if(str[i]=='A'){
                if(a>c){
                    break;
                }else{
                    c-=a;
                    ans--;
                }
            }else{
                if(b>c){
                    break;
                }else{
                    c-=b;
                    ans--;
                }
            }
        }
    }
    //if(ans<1)ans=1;
    O_ ans<<EL

}
DRIVER
