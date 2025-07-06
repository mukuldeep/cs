//
// Created by me on 04-04-2021.
//
#include <bits/stdc++.h>
#define DRIVER int main(){ll t=1;I_ t;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){ll t=1;I_ t;W_(t)soln(t);return 0;}
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

void soln(ll t){
    ll n,k,a,b=0,c,zc=0;
    string str;
    I_ str;
    n=str.length();
    vll consdr(n,0);
    ll strt=0;
    for(auto cch:str){
        if(cch=='0')zc++;
    }
    if(zc==n){
        O_ 1<<EL
        //return "1";
    }
    while(str[strt]=='0')strt++;
    strt++;
    vprll pr_ind;
    char pre_ch=str[strt];strt++;
    FR_IR(i,strt,n){
        if(pre_ch!=str[i]){
            b++;
            pr_ind.PB_(MP_(i-1,i));
            consdr[i-1]=b;
            consdr[i]=b;
            i++;
            pre_ch=str[i];
        }
    }

//    for(auto x:consdr){
//        O_ x;
//    }O_ EL
//    for(auto x:pr_ind){
//        O_ x.first<<" "<<x.second<<EL
//    }O_ EL

    string ans="";
    if(zc){
        ans="1";
        ll pre01x=-5,pre01xcnt=0;
        for(auto x:pr_ind){
            if(str[x.second]=='0'){
                ans+='0';
                pre01xcnt=0;
            }else{
                if((str[x.first-1]=='0' && consdr[x.first-1]==0) || (x.second!=n-1 && str[x.second+1]=='0' && consdr[x.second+1]==0)){

                    if(pre01x==x.first-2 && ans[ans.length()-1]=='0'){
                        ll all010strt=ans.length()-1;
                        //O_ all010strt<<":"<<pre01xcnt<<" ";
                        for(ll xx=all010strt;pre01xcnt;xx--,pre01xcnt--)
                            ans[xx]='1';
                    }

                    ans+='1';
                    pre01xcnt=0;
                }else{
                    pre01x=x.first;
                    ans+='0';
                    pre01xcnt++;
                }
            }
        }
        if(consdr[n-1]){
            ans+='0';
        }else{
            if(str[n-1]=='0'){
                ans+='1';
            }else{
                ans+='0';
            }
        }
    }else{
        ans="0";
    }
    O_ ans<<EL

}

TEST_DRIVER
