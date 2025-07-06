//
// Created by me on 23-06-2021.
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
    string str,str2="";
    I_ n>>str;
    vvll arr(n+1,vll(3,0)),par(n+1,vll(3,0));
    FR_IR(i,1,n+1){
        if(arr[i-1][1]<arr[i-1][2]){
            arr[i][0]=arr[i-1][1]+1;
            par[i][0]=1;
        }else{
            arr[i][0]=arr[i-1][2]+1;
            par[i][0]=2;
        }
        if(arr[i-1][0]<arr[i-1][2]){
            arr[i][1]=arr[i-1][0]+1;
            par[i][1]=0;
        }else{
            arr[i][1]=arr[i-1][2]+1;
            par[i][1]=2;
        }
        if(arr[i-1][0]<arr[i-1][1]){
            arr[i][2]=arr[i-1][0]+1;
            par[i][2]=0;
        }else{
            arr[i][2]=arr[i-1][1]+1;
            par[i][2]=1;
        }
        if(str[i-1]=='R')arr[i][0]--;
        else if(str[i-1]=='B')arr[i][1]--;
        else arr[i][2]--;

        //O_ arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<EL

    }
    if(arr[n][0]<=arr[n][1] && arr[n][0]<=arr[n][2]){
        mx=arr[n][0];
        a=0;
    }else if(arr[n][1]<=arr[n][0] && arr[n][1]<=arr[n][2]){
        mx=arr[n][1];
        a=1;
    }else{
        mx=arr[n][2];
        a=2;
    }
    O_ mx<<EL
    for(ll i=n;i>0;i--){
        if(a==0){
            str2+="R";
            a=par[i][0];
        }else if(a==1){
            str2+="B";
            a=par[i][1];
        }else{
            str2+="G";
            a=par[i][2];
        }
    }
    reverse(str2.begin(),str2.end());
    O_ str2<<EL

}

DRIVER
