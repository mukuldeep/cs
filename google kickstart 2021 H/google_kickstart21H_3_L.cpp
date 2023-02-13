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

void soln(ll t){
    cout<<"Case #"<<t<<": ";
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>str;

    uompll next;
    vector<uompll> indl(10);
    FR_IR(i,0,n){
        next[i]=i+1;
        indl[str[i]-'0'][i]=1;
    }

    bool flag=true;
    while(flag){
        flag=false;
        //str=perform_change(lst,flag);
        for(auto i='0';i<='9';i++){
            bool lflag=false;
            for(auto xd:indl[i-'0']){
                if(next[xd.first]<n && str[next[xd.first]]==(i=='9'?'0':i+1)){
                    lflag=true;

                    ll curr_index=xd.first;
                    ll next_index=next[xd.first];
                    char curr_char=str[curr_index];
                    char next_char=str[next_index];

                    indl[i-'0'][curr_index]=0;//removing index
                    indl[(i+2-'0')%10][curr_index]=1;//adding to char+=2 index
                    next[curr_index]=next[next_index];
                    str[curr_index]=((i+2-'0')%10)+'0';
                }
            }
            if(lflag)flag=true;
            string ans_str="";
            ll index=0;
            while(index<n){
                ans_str+=str[index];
                index=next[index];
            }
            O_ ans_str<<EL
        }
    }

    string ans_str="";
    ll index=0;
    while(index<n){
        ans_str+=str[index];
        index=next[index];
    }
    O_ ans_str<<EL

}

TEST_DRIVER
