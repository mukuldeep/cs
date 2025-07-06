/*
 * Created by me on 18-11-2022.
 */
#include <bits/stdc++.h>
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1;  I t;
#define Dr int main(){Sync W(t)soln(t);return 0;}
#define Drt int cc_main(){Sync W(t)soln(t);return 0;}
#define F(a,c) for (ll a=0;a<c; a++)
#define Fe(a,c) for(ll a=0;a<=c; a++)
#define Fi(i,s,e) for(ll i=s;i<e;i++)
#define Rfi(i,s,e) for(ll i=s;i>e;i--)
#define Fa(xx,xxs) for(auto xx:xxs)
#define Srt(x) sort(x.begin(),x.end());
#define Rsrt(x) sort(x.rbegin(),x.rend());
#define Rev(x) reverse(x.begin(),x.end());
#define W(n) while(n--)
#define Wh while
#define Il while(1)
#define Pb push_back
#define O cout<<
#define Prcn fixed<<setprecision(20)
#define I cin>>
#define El endl;
//ds
#define ll long long
#define ld long double
#define S string
#define Ch char
#define V(x) vector<x>
#define Vv(x) V(V(x))
#define Sk(x) stack<x>
#define St(x) set<x>
#define Q(x) queue<x>
#define Dq(x) deque<x>
#define P(x) pair<x,x>
#define P2(x,y) pair<x,y>
#define Mp(x,y) map<x,y>
#define Uom(x,y) unordered_map<x,y>

//functions
#define p_bin(x) if(x)O "YES"<<El else O "NO"<<El

//constants
#define t9p7 1000000007
#define INF 100000000000000000 //1e17
using namespace std;

void pre(){

}

void rec(St(ll) st,ll depth,ll l,ll r,ll x,ll b){
//    O "depth:"<<depth<<" st:";
//    for(auto xx:st){
//        O xx<<",";
//    }O El

    if(depth==4)
    {
        O -1<<El
        return;
    }
    St(ll) st2;
    for(auto xx:st){
        if(abs(xx-b)>=x){
            O depth<<El
            return;
        }
        if(xx-x>=l) st2.insert(xx-x);
        if(abs(xx-l)>=x) st2.insert(l);
        if(xx+x<=r) st2.insert(xx+x);
        if(abs(r-xx)>=x) st2.insert(r);
    }
    rec(st2,depth+1,l,r,x,b);
}

void soln(ll t){
    ll m,x,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;

    I l>>r>>x>>a>>b;
    if(a==b)
    {
        O 0<<El
    }else{
        St(ll) st;
        st.insert(a);
        rec(st,1,l,r,x,b);
    }
}

Dr
