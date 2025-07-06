//
// Created by me on 07-07-2021.
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
#define vll vector<ll>

#define ll long long
#define t9p7 1000000007
using namespace std;



void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n;
    vll arr(n);
    FR_IR(i,0,n){
        I_ arr[i];
    }
    a=0;b=n-1;c=0;
    while(a<=b){
        if(arr[a]>arr[b]){
            if(c&1)ans+=arr[a];
            else cnt+=arr[a];
            a++;
        }else{
            if(c&1) ans+=arr[b];
            else cnt+=arr[b];
            b--;
        }
        c++;
    }
    O_ cnt<<" "<<ans<<EL

}

DRIVER
