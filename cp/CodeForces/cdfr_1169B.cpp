//
// Created by me on 07-05-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;W_(t)soln(t);return 0;}
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
    string str;
    I_ n>>m;//n nodes, m vertices
    vector<vector<pair<ll,ll>>> adjl(n+1);//1 indexed
    vprll vrtx(m+1);
    FR_IR(i,0,m){
        I_ a>>b;
        vrtx[i+1]={a,b};
        adjl[a].PB_({b,i+1});
        adjl[b].PB_({a,i+1});//undirected
    }

    stll aset1,aset2,bset1,bset2;
    ll f=0;
    ll na=0;
    ll x=vrtx[1].first;
    FR_AU(xd,adjl[x]){
        aset1.insert(xd.second);
    }

    aset2.insert(aset1.begin(),aset1.end());
    FR_IR(i,1,m+1){
        if(aset1.find(i)==aset1.end()){
            na=i;break;
        }
    }
    if(na) {
        x = vrtx[na].first;
        FR_AU(xd, adjl[x]) {
            aset1.insert(xd.second);
        }
        x = vrtx[na].second;
        FR_AU(xd, adjl[x]) {
            aset2.insert(xd.second);
        }
    }

    ll nb=0;
    ll y=vrtx[1].second;
    FR_AU(xd,adjl[y]){
        bset1.insert(xd.second);
    }
    bset2.insert(bset1.begin(),bset1.end());
    FR_IR(i,1,m+1){
        if(bset1.find(i)==bset1.end()){
            nb=i;break;
        }
    }
    if(nb) {
        y = vrtx[nb].first;
        FR_AU(xd, adjl[y]) {
            bset1.insert(xd.second);
        }
        y = vrtx[nb].second;
        FR_AU(xd, adjl[y]) {
            bset2.insert(xd.second);
        }
    }




    if(aset1.size()==m || aset2.size()==m || bset1.size()==m || bset2.size()==m)
        O_ "YES"<<EL
    else
        O_ "NO"<<EL
}

DRIVER
