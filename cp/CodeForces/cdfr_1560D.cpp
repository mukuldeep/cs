//
// Created by me on 18-08-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();
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
vector<string> p2;
void pre(){
    unsigned long long a;
    a=1;
    p2.push_back("1");
    FR_IR(i,1,64){
        a*=2;
        string str=to_string(a);
        //O_ str<<EL
        p2.push_back(str);
    }
    p2.push_back("18446744073709551616");
    p2.push_back("36893488147419103232");
    p2.push_back("73786976294838206464");
    p2.push_back("147573952589676412928");
    p2.push_back("295147905179352825856");
    p2.push_back("590295810358705651712");
    p2.push_back("1180591620717411303424");
    p2.push_back("2361183241434822606848");
    p2.push_back("4722366482869645213696");
    p2.push_back("9444732965739290427392");
    p2.push_back("18889465931478580854784");
    p2.push_back("37778931862957161709568");
}

ll check_conv(string s1, string s2){
    ll a,b;
    a=s1.size();
    b=s2.size();
    ll curr=0,mtch=0;
    FR_IR(i,0,b){
        while(curr<a && s1[curr]!=s2[i])curr++;
        if(curr==a)
            break;
        else{
            mtch++;
            curr++;
        }
    }
    //O_ s1<<" "<<s2<<" "<<mtch<<EL
    return a+b-2*mtch;
}
void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ str;
    FR_AU(xd,p2){
        mn=min(mn,check_conv(str,xd));
    }
    O_ mn<<EL
}

DRIVER
