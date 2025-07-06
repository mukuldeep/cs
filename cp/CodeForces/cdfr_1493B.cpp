//
// Created by me on 20-05-2021.
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

bool is_valid(ll a,ll b){
    while(a){
        if(a%10!=0 && a%10!=1 && a%10!=2 && a%10!=5 && a%10!=8)return false;
        a/=10;
    }
    while(b){
        if(b%10!=0 && b%10!=1 && b%10!=2 && b%10!=5 && b%10!=8)return false;
        b/=10;
    }
    return true;
}
ll rev_n(ll n){
    ll ans=0;
    FR_IR(i,0,2){
        ans*=10;
        if(n%10==2)ans+=5;
        else if(n%10==5)ans+=2;
        else ans+=n%10;
        n/=10;
    }
    return ans;
}
bool is_valid_time(ll h,ll m, ll a, ll b){
    //O_ "n:"<<a<<" "<<b<<EL
    a=rev_n(a);
    b=rev_n(b);
    //O_ "rev:"<<a<<" "<<b<<EL
    if(a<m && b<h){
        //O_ (a<10?"0":"")<<a<<":"<<(b<10?"0":"")<<b<<EL;
        return true;
    }
    return false;
}
void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m>>str;
    a=(str[0]-'0')*10+(str[1]-'0');
    b=(str[3]-'0')*10+(str[4]-'0');
    //O_ a<<" "<<b<<EL

    while(1){
        if(is_valid(a,b)){
            //O_ "valid"<<a<<" "<<b<<EL
            if(is_valid_time(n,m,a,b)){
                O_ (a<10?"0":"")<<a<<":"<<(b<10?"0":"")<<b<<EL
                return;
            }
        }
        b++;
        if(b==m)b=0,a++;
        if(a==n)a=0;
    }
}

DRIVER
