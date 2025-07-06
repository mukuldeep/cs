/*
 * Created by me on 27-09-2021.
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
#define t9p7 1e9+7
#define INF 1e17
using namespace std;

void pre(){

}

ll calc(V(ll) &ar,ll n,ll a,ll b){
    ll ca=0,pos=0;
    //O "ab:"<<a<<" "<<b<<El
    while(pos<n){
        if(ca&1){
            while(pos<n && ar[pos]!=b)pos++;
        }else{
            while(pos<n && ar[pos]!=a)pos++;
        }
        if(pos<n){
            //O ar[pos];
            ca++;
        }

    }
    if(ca && (ca&1))ca--;
    return ca;
}


void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    I str;
    n=str.size();
    V(ll) arr,cn(10,0),pr;
    Fa(i,str){
        arr.push_back(i-'0');
        cn[arr.back()]++;
    }
    Fi(i,0,10){
        mx=max(mx,cn[i]);
        if(cn[i])pr.push_back(i);
    }
    //O "prsize:"<<pr.size()<<El
    //Fa(xd,pr)O xd<<" ";O El

    F(i,pr.size()){
        Fi(j,i+1,pr.size()){
            mx=max(mx,calc(arr,n,pr[i],pr[j]));
            mx=max(mx,calc(arr,n,pr[j],pr[i]));
        }
    }
    ans=n-mx;
    O ans<<El
}

Dr
