//
// Created by me on 12-06-2021.
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


void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    I_ n;
    vvll arr(6);
    FR_IR(i,0,n){
        I_ a;
        switch(a){
            case 4:arr[0].push_back(i);break;
            case 8:arr[1].push_back(i);break;
            case 15:arr[2].push_back(i);break;
            case 16:arr[3].push_back(i);break;
            case 23:arr[4].push_back(i);break;
            case 42:arr[5].push_back(i);break;
        }
    }
    while(1){
        if(arr[0].empty() || arr[1].empty() || arr[2].empty() || arr[3].empty() || arr[4].empty() || arr[5].empty()){
            cnt+=(arr[0].size()+arr[1].size()+arr[2].size()+arr[3].size()+arr[4].size()+arr[5].size());
            break;
        }
        b=arr[5].back();
        arr[5].pop_back();
        for(ll i=4;i>=0;i--){
            while(arr[i].size() && arr[i].back()>b){
                cnt++;
                arr[i].pop_back();
            }
            if(arr[i].empty()){
                cnt+=5-i;
                break;
            }
            b=arr[i].back();
            arr[i].pop_back();
        }
    }
    O_ cnt<<EL

}

DRIVER
