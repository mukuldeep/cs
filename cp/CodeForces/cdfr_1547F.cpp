//
// Created by me on 10-07-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();
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


ll const prime_upto=1000005;
vector<vll> d_prime_factors(prime_upto + 1,vll(0));
void distinct_prime_factors(ll n=prime_upto)
{   //ll cnt=0;
    for (ll p = 2; p<= n; p++)
        if (!(d_prime_factors[p].size()))
            for (ll i = p; i <= n; i += p)
                d_prime_factors[i].PB_(p);//,cnt++;

    //O_ "O("<<cnt<<")"<<EL
}
void pre(){
    distinct_prime_factors();
}

void soln(ll t){
    ll m,n,k,a,b,c,g,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n;
    vll arr(n);
    I_ arr[0];
    g=arr[0];
    FR_IR(i,1,n){
        I_ arr[i];
        g=__gcd(g,arr[i]);
    }
    FR_IR(i,0,n)arr[i]/=g;

    //O_ "done factors"<<EL
    mx=0;
    FR_IR(i,0,n){
        vll factors=d_prime_factors[arr[i]];
        ll lcnt,curr_prime;
        //O_ "i:"<<i<<EL
        while(!factors.empty()){
            curr_prime=factors.back();
            //O_ "  curr_p:"<<curr_prime<<EL
            lcnt=0;
            ll lpos=i;
            while(arr[lpos]%curr_prime==0){
                lcnt++;
                arr[lpos]/=curr_prime;
                lpos++;
                if(lpos==n)lpos=0;
                if(lpos==i)break;
            }
            if(!factors.empty() && arr[i]%factors.back())factors.pop_back();
            //FR_AU(xd,arr)O_ xd<<" ";O_ EL
            //if(!factors.empty())FR_AU(xd,factors)O_ xd<<" ";O_ EL
            ll fpos=i==0?n-1:i-1;
            if(lpos!=i){
                while(fpos!=lpos && arr[fpos]%curr_prime==0){
                    lcnt++;
                    arr[fpos]/=curr_prime;
                    fpos--;
                    if(fpos==-1)fpos=n-1;
                }
            }
            mx=max(mx,lcnt);
        }

    }

    O_ mx<<EL


}

TEST_DRIVER
