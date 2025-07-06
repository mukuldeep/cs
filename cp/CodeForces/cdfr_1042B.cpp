//
// Created by me on 08-06-2021.
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
const ll inf=1e17;


void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=inf,mx=LONG_LONG_MIN;
    string str;
    I_ n;
    vll arr(8,inf);
    FR_IR(i,0,n){
        I_ c>>str;
        a=str.length();
        b=0;
        FR_IR(j,0,a){
            b+=1<<(str[j]-'A');
        }
        arr[b]=min(arr[b],c);
    }
    arr[0]=0;
    FR_IR(i,0,8){
        FR_IR(j,0,8){
            FR_IR(h,0,8){
                if((i|j|h)==7){
                    if((i==j)&&(i!=0) || (j==h)&&(j!=0) || (i==h)&&(i!=0))continue;

                    if(arr[i]!=inf && arr[j]!=inf && arr[h]!=inf) {
                        //O_ i<<" "<<j<<" "<<h<<" :"<<arr[i] + arr[j] + arr[h]<<EL
                        mn = min(mn, arr[i] + arr[j] + arr[h]);
                    }
                }
            }
        }
    }
    if(mn==inf)mn=-1;
    O_ mn<<EL




}

DRIVER
