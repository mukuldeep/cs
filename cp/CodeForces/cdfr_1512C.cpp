//
// Created by me on 10-04-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define FR_(a,c)   for (ll (a)=0;(a)<(c); (a)++)
#define FR_E(a,c)   for (ll (a)=0;(a)<=(c); (a)++)
#define FR_IR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FR_AU(xx,xxs) for(auto (xx):(xxs))
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
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef vector<pair<ll, ll>> vprll;
typedef map<ll,ll>  mpll;
typedef unordered_map<ll,ll> uompll;
const ll t9p7=1000000007;

void soln(ll t){
    ll n,k,a,b,c,flag=1;
    I_ a>>b;n=a+b;
    string str;
    I_ str;
    ll cnt[]={a,b};
    vll ind_q;
    FR_IR(i,0,n/2){
        if(str[i]=='?' && str[n-1-i]=='?'){

        }else{
            if(str[i]=='?'){
                str[i]=str[n-1-i];
                if(cnt[str[n-1-i]-'0']>1)cnt[str[n-1-i]-'0']-=2;else{flag=0;break;}
            }else if(str[n-1-i]=='?'){
                str[n-1-i]=str[i];
                if(cnt[str[i]-'0']>1)cnt[str[i]-'0']-=2;else{flag=0;break;}
            }else{
                if(str[i]==str[n-1-i]){
                    if(cnt[str[i]-'0']>1)cnt[str[i]-'0']-=2;else{flag=0;break;}
                }else{
                    flag=0;
                    break;
                }
            }
        }
        //O_ str<<EL
    }//O_ EL

    FR_IR(i,0,n/2){
        if(str[i]=='?' && str[n-1-i]=='?'){
            if(cnt[0]>1)str[i]=str[n-1-i]='0',cnt[0]-=2;
            else if(cnt[1]>1)str[i]=str[n-1-i]='1',cnt[1]-=2;
            else{flag=0;break;}
        }
        //O_ str<<EL
    }

    if(n&1){
        if(str[n/2]=='?') {
            if (cnt[0] > 0)str[n / 2] = '0', cnt[0]--;
            else if (cnt[1] > 0)str[n / 2] = '1', cnt[1]--;
            else { flag = 0; }
        }else{
            cnt[str[n/2]-'0']--;
        }
    }
    if(cnt[0]!=0 || cnt[1]!=0){
        flag=0;
    }


    if(flag){
        O_ str<<EL
    }else{
        O_ -1<<EL
    }

}

DRIVER
