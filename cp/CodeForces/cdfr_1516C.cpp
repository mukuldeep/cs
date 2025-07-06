//
// Created by me on 22-04-2021.
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
typedef stack<ll> skll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef vector<pair<ll, ll>> vprll;
typedef map<ll,ll>  mpll;
typedef unordered_map<ll,ll> uompll;
typedef set<ll> stll;
const ll t9p7=1000000007;

bool isPartiion(vll arr, ll n)
{
    ll sum = 0;
    ll i, j;
    for (i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2 != 0)
        return false;

    bool part[sum / 2 + 1];
    for (i = 0; i <= sum / 2; i++) {
        part[i] = 0;
    }
    for (i = 0; i < n; i++) {
        for (j = sum / 2; j >= arr[i];j--) {
            if (part[j - arr[i]] == 1 || j == arr[i])
                part[j] = 1;
        }
    }
    return part[sum / 2];
}
void solutil(vll arr,ll n){
    ll c=0;
    FR_IR(i,0,n) {
        arr[i]>>=1;
        if (arr[i] & 1){
            c = i + 1;
            break;
        }
    }
    if(c>0){
        O_ 1<<endl<<c<<EL
    }else{
        solutil(arr,n);
    }
}

void soln(ll t){
    ll n,k,a,b,c=0,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n;
    vll arr(n);
    FR_IR(i,0,n) {
        I_ arr[i];
        if (arr[i] & 1)c = i + 1;
    }
    if(isPartiion(arr,n)){
        if(c>0){
            O_ 1<<endl<<c<<EL
        }else{
            solutil(arr,n);
        }
    }else{
        O_ 0<<EL;
    }
}

DRIVER
