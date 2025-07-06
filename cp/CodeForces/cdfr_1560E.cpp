//
// Created by me on 18-08-2021.
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


void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str,seq="";
    I_ str;
    n=str.length();
    vll ccnt(26,0),visited(26,0),acnt(26,0);
    FR_IR(i,0,n){
        ccnt[str[i]-'a']++;
    }

    ll char_cnt=0;
    FR_IR(i,0,26){
        if(ccnt[i])char_cnt++;
    }


    for(ll i=n-1;i>=0;i--){
        if(!visited[str[i]-'a']){
            if(ccnt[str[i]-'a']%char_cnt){
                O_ -1<<EL
                return;
            }else{
                seq+=str[i];
                acnt[str[i]-'a']=ccnt[str[i]-'a']/char_cnt;
                visited[str[i]-'a']=1;
                char_cnt--;
            }
        }
    }

    reverse(seq.begin(),seq.end());
    ll str_size=0;
    string temp_ans="",temp_str="",temp_temp_str;

    FR_IR(i,0,26){
        str_size+=acnt[i];
    }
    //simulate
    temp_str=str.substr(0,str_size);
    //O_ temp_str<<EL
    FR_AU(xd,seq){
        temp_ans+=temp_str;
        temp_temp_str="";
        FR_AU(xxd,temp_str){
            if(xxd!=xd)temp_temp_str+=xxd;
        }
        temp_str=temp_temp_str;
    }
    if(temp_ans==str){
        O_ str.substr(0,str_size)<<" "<<seq<<EL
    }else{
        O_ -1<<EL
    }

    //O_ seq<<EL
    //O_ str_size<<EL
}

DRIVER
