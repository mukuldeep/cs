//
// Created by me on 06-08-2021.
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
/*
 * returns longest palindromic prefix
 * takes the string and a character which is not in the domain of the string
 * returns longest palindromic prefic
 */
string longest_palindromic_prefix(string str,char not_in_str){
    string temp=str;
    reverse(temp.begin(),temp.end());
    temp=str+not_in_str+temp;
    ll n=temp.size();
    vll lps(n,0);

    FR_IR(i,1,n){
        ll len=lps[i-1];
        while(len>0 && temp[i]!=temp[len]) {
            len = lps[len - 1];
        }
        if(temp[i]==temp[len])
            len++;
        lps[i]=len;
    }
    return temp.substr(0,lps[n-1]);
}


void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ str;
    n=str.size();
    a=0;b=n-1;
    while(a<b && str[a]==str[b]){
        cnt++;
        a++;
        b--;
    }
    string temp=str.substr(cnt,n-2*cnt);
    string tempr=temp;
    reverse(tempr.begin(),tempr.end());
    temp=longest_palindromic_prefix(temp,'*');
    tempr=longest_palindromic_prefix(tempr,'*');
    reverse(tempr.begin(),tempr.end());
    string ansstr="",revc;
    ansstr+=str.substr(0,cnt);
    revc=ansstr;
    reverse(revc.begin(),revc.end());
    if(temp.size()>tempr.size()){
        ansstr+=temp;
    }else{
        ansstr+=tempr;
    }
    ansstr+=revc;
    O_ ansstr<<EL

}

DRIVER
