//
// Created by me on 24-07-2021.
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
    ll m,n,k,a=0,b=0,c=0,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m;//n nodes, m vertices
    vvll adjl(n+1);//1 indexed
    FR_IR(i,0,m){
        I_ a>>b;
        adjl[a].PB_(b);
        adjl[b].PB_(a);//undirected
    }
    a=0;b=0;
    FR_IR(i,1,n+1){
        k=adjl[i].size();
        //O_ k<<EL
        if(k==1)a++;
        else if(k==2)b++;
        else if(k==n-1)c++;
        else cnt++;
    }
    //O_ a<<" "<<b<<" "<<c<<" "<<cnt<<EL
    if(a==2 && b==n-2){
        O_ "bus topology"<<EL
    }else if(b==n){
        O_ "ring topology"<<EL
    }else if(c==1 && a==n-1){
        O_ "star topology"<<EL
    }else{
        O_ "unknown topology"<<EL
    }
}
DRIVER
