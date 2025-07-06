/*
 * Created by me on 28-09-2021.
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
bool isin(ll a,ll b,ll c,ll d){
    if(a<0 || b<0 || a>=c || b>=d) return false;
    return true;
}
ll tick_len(V(S) &ar,ll i,ll j,ll n, ll m){
    ll h=0;
    while(1){
        //O "h"<<h<<El
        if(isin(i-h-1,j-h-1,n,m) && isin(i-h-1,j+h+1,n,m)){
            if(ar[i-h-1][j-h-1] != '.' && ar[i-h-1][j+h+1]!='.'){
                h++;
            }else{
                break;
            }
        }else{
            break;
        }
    }
    return h;
}

void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    I n>>m>>k;
    V(S) arr(n);
    F(i,n){
        I arr[i];
    }
    //O "fdk"<<El
    for(ll i=n-1;i>=0;i--){
        for(ll j=0;j<m;j++){
            //O arr[i][j]<<El
            if(arr[i][j]!='.'){
                ll oo=tick_len(arr,i,j,n,m);
                //O "oo"<<oo<<El
                if(oo>=k){
                    for(ll jk=0;jk<=oo;jk++){
                        arr[i-jk][j-jk]='s';
                        arr[i-jk][j+jk]='s';
                    }
                }
            }
        }
    }
    ll fl=true;
    F(i,n){
        F(j,m){
            if(arr[i][j]=='*'){
                fl= false;
                break;
            }
        }
    }
    p_bin(fl)
}

Dr
