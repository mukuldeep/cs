//
// Created by me on -0-2021.
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
    ll n,k,a,b,c;
    string str;
    I_ str;
    regex bnum("(R)([0-9]+)(C)([0-9]+)");
    //regex balp("([A-Z]+)([0-9]+)");

    if ( regex_match(str,bnum) ) {
        ll fc=0,cn=0,_10=1;
        while(str[fc]!='C')fc++;
        for(ll i=fc+1;i<str.length();i++){
            cn=cn*10+str[i]-'0';
            _10*=10;
        }
        //cout<<cn<<" ";
        string _26str="";
        while(cn>0){
            ll curch=cn%26;
            //cout<<curch<<" ";
            if(!curch) {
                _26str+='Z';
                cn/= 26;
                cn--;
            }else{
                _26str+=('A'+curch-1);
                cn/=26;
            }
        }
        reverse(_26str.begin(),_26str.end());
        cout<<_26str<<str.substr(1,fc-1)<<endl;
    }else {
        ll fn=0,num=0;
        while(str[fn]>'9')fn++;
        for(ll i=0;i<fn;i++){
            num=num*26+(str[i]-'A'+1);
        }
        cout<<"R"<<str.substr(fn)<<"C"<<num<<endl;
    }
}

DRIVER
/*

2
RZ228
R228C494

 */