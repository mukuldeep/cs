//
// Created by me on 26-07-2021.
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
    string str,str2;
    I_ n>>str2>>str;
    vll fc1(26,0),fc2(26,0);
    FR_IR(i,0,n){
        fc1[str[i]-'a']++;
        fc2[str2[i]-'a']++;
    }
    FR_IR(i,0,26){
        if(fc1[i]!=fc2[i]){
            O_ -1<<EL
            return;
        }
    }
    vll an;
    FR_IR(i,0,n){
        if(str[i]==str2[i])
            continue;
        ll pos=i+1;
        FR_IR(j,pos,n){
            if(str2[j]==str[i]){
                pos=j;
                break;
            }
        }
        for(ll j=pos-1;j>=i;j--){
            swap(str2[j],str2[j+1]);
            an.push_back(j+1);
        }
    }
    O_ an.size()<<EL
    FR_AU(xd,an)O_ xd<<" ";O_ EL

}
DRIVER
