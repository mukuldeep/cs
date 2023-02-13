//
// Created by me on 14-11-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){pre();SYNC ll t=1;I_ t;for(int i=1;i<=t;i++){soln(i);}return 0;}
#define TEST_DRIVER int cc_main(){pre();SYNC ll t=1;I_ t;for(int i=1;i<=t;i++){soln(i);}return 0;}
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

vector<pair<string,char>> mp;
void pre(){
    mp.push_back({"01",'2'});
    mp.push_back({"12",'3'});
    mp.push_back({"23",'4'});
    mp.push_back({"34",'5'});
    mp.push_back({"45",'6'});
    mp.push_back({"56",'7'});
    mp.push_back({"67",'8'});
    mp.push_back({"78",'9'});
    mp.push_back({"89",'0'});
    mp.push_back({"90",'1'});
}

string replace_all(string str,string key,char rep,bool &flag){
    string ans="";
    flag=false;
    for(auto xd:str){
        if(ans.empty()){
            ans.push_back(xd);
        }else if(xd==key[1] && ans.back()==key[0]){
            ans.pop_back();
            ans.push_back(rep);
            flag=true;
        }else{
            ans.push_back(xd);
        }
    }
    //O_ str<<" "<<key<<" "<<rep<<flag<<EL
    return ans;
}
string perform_change(string str,bool &flag,vll &char_cnt) {
    string str2="";
    flag=false;
    //vll new_changed(10,0);
    FR_IR(i,0,mp.size()){
        //if(!changed[(i==0?9:i-1)])continue;
        auto xd=mp[i];
        bool lflag=false;
        str2=replace_all(str,xd.first,xd.second,lflag);

        if(lflag) {
            //new_changed[i] = 1;
            str = str2;
            flag = true;
        }
//        }else{
//            changed[i]=0;
//        }
    }
    //changed=new_changed;
    return str;
}
void soln(ll t){
    cout<<"Case #"<<t<<": ";
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>str;

    vll changed(10,1);
    bool flag=true;
    while(flag){
        flag=false;
        str=perform_change(str,flag,changed);
    }
    O_ str<<EL

}

TEST_DRIVER
