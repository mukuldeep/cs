//
// Created by me on 11-08-2021.
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
ll calc2(string &str,vll &arr,ll n){
    for(ll i=2*n+3;i>=0;i--){
        if(i>=n)arr[i]=1;
        else arr[i]=arr[(i<<1)+2]*(str[i]!='1')+arr[(i<<1)+1]*(str[i]!='0');
    }
}
void update(string &str,vll &arr, ll pos,ll &n) {

    if (str[pos] == '0') {
        arr[pos] = (((pos << 1) + 2) >= n ? 1 : arr[(pos << 1) + 2]);
    } else if (str[pos] == '1') {
        arr[pos] = (((pos << 1) + 1) >= n ? 1 : arr[(pos << 1) + 1]);
    } else {
        arr[pos] = (((pos << 1) + 1) >= n ? 1 : arr[(pos << 1) + 1]) + (((pos << 1) + 2) >= n ? 1 : arr[(pos << 1) + 2]);
    }
    pos=(pos-1)/2;

    while (pos){
        //ll temp = arr[pos];
        if (str[pos] == '0') {
            arr[pos] = arr[(pos << 1) + 2];
        } else if (str[pos] == '1') {
            arr[pos] = arr[(pos << 1) + 1];
        } else {
            arr[pos] =arr[(pos << 1) + 1]+arr[(pos << 1) + 2];
        }
        pos=(pos-1)/2;
    }
    if (str[pos] == '0') {
        arr[pos] = (((pos << 1) + 2) >= n ? 1 : arr[(pos << 1) + 2]);
    } else if (str[pos] == '1') {
        arr[pos] = (((pos << 1) + 1) >= n ? 1 : arr[(pos << 1) + 1]);
    } else {
        arr[pos] =(((pos << 1) + 1) >= n ? 1 : arr[(pos << 1) + 1]) + (((pos << 1) + 2) >= n ? 1 : arr[(pos << 1) + 2]);
    }

}

void soln(ll t){
    ll m,n,k,a,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>str;
    reverse(str.begin(),str.end());
    n=(1<<n)-1;
    vll arr(2*n+5);
//    calc(str,arr,0,n);
    calc2(str,arr,n);
    //FR_IR(i,0,n)O_ str[i]<<":"<<arr[i]<<" ";O_ EL
    I_ m;
    char b;
    FR_IR(i,0,m){
        I_ a>>b;
        str[n-a]=b;
        ll pos=n-a;
        do{
            arr[pos]=arr[(pos<<1)+2]*(str[pos]!='1')+arr[(pos<<1)+1]*(str[pos]!='0');
            pos=(pos-1)/2;
        }while(pos);
        arr[pos]=arr[(pos<<1)+2]*(str[pos]!='1')+arr[(pos<<1)+1]*(str[pos]!='0');

        //update(str,arr,n-a,n);
        //FR_IR(j,0,n)O_ str[j]<<":"<<arr[j]<<" ";O_ EL
        O_ arr[0]<<EL
    }


}

DRIVER
