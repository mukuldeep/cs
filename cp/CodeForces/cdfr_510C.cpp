//
// Created by me on 06-10-2021.
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




class graph_adjl_unweighted{
    vvll adjl;
    ll n,m;
public:
    graph_adjl_unweighted(ll n,ll m){
        this->m=m;
        this->n=n;
        adjl=vvll (n+1);
    }

    /*
     * add edges
     */
    void add_undirected_edge(ll a,ll b){
        adjl[a].push_back(b);
        adjl[b].push_back(a);
    }
    void add_directed_edge(ll a,ll b){
        adjl[a].push_back(b);
    }

    /*
    * Edges input
    */
    void input_edges(){
        ll a,b;
        FR_IR(i,0,m) {
            I_ a >> b;
            add_undirected_edge(a,b);
        }
    }


};


pair<char,char> first_diff(string &s1,string &s2){
    ll i1=0,i2=0;
    pair<char,char> ans;
    ans.first='0';
    ans.second='0';
    while(i1<s1.size() && i2<s2.size() && s1[i1]==s2[i2]){
        i1++;
        i2++;
    }
    if(i1<s1.size() && i2<s2.size()){
        ans.first=s1[i1];
        ans.second=s2[i2];
    }
    return  ans;
}

void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str,prestr;
    pair<char,char> cnr;
    graph_adjl_unweighted gr(26,25);
    I_ n>>prestr;
    FR_IR(i,1,n){
        I_ str;
        cnr=first_diff(prestr,str);
        O_ str <<" "<<cnr.first<<" "<<cnr.second<<EL
        if(cnr.first!='0'){
            gr.add_directed_edge(1+cnr.first-'a',1+cnr.second-'a');
        }
        prestr=str;
    }

}

TEST_DRIVER
