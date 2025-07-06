//
// Created by me on 15-06-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){SYNC ll t=1;W_(t)soln(t);return 0;}
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
typedef int ll;
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

ll find_colors(vector<vvll> &arr,ll r,ll g,ll b){
    if(r==0 && g==0 && b==0)return 0;
    if(r==0 && g==0)return 1;
    if(r==0 && b==0)return 2;
    if(g==0 && b==0)return 4;
    if(arr[r][g][b]!=-1)return arr[r][g][b];

    ll ans=0;
    if(r>0){
        if(g>0)ans|=find_colors(arr,r-1,g-1,b+1);
        if(b>0)ans|=find_colors(arr,r-1,g+1,b-1);
    }
    if(g>0 && b>0)ans|=find_colors(arr,r+1,g-1,b-1);

    if(r>1)ans|=find_colors(arr,r-1,g,b);
    if(g>1)ans|=find_colors(arr,r,g-1,b);
    if(b>1)ans|=find_colors(arr,r,g,b-1);
    return arr[r][g][b]=ans;
}
void soln(ll t){
    ll m,n,k,a=0,b=0,c=0,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>str;
    vector<vvll> arr(303,vvll(303,vll(303,-1)));
    FR_IR(i,0,n){
        switch (str[i]) {
            case 'R':a++;break;
            case 'G':b++;break;
            case 'B':c++;break;
        }
    }
    //O_ a<<" "<<b<<" "<<c<<EL
    ans=find_colors(arr,a,b,c);
    if(ans&1)O_ "B";
    if(ans&2)O_ "G";
    if(ans&4)O_ "R";

    O_ EL
}
DRIVER
