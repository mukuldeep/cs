/*
 * Created by me on 17-09-2021.
 */
#include <bits/stdc++.h>
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1; // I t;
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


void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=1,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str,str2,an;
    I str;
    n=str.size();
    V(ll) arr(n+1,0);
    Fi(i,1,n+1){
        arr[i]=arr[i-1]+str[i-1]-'0';
    }
    mx=arr[n];
    an=str;
    for(ll i=n-1;i>=0;i--){
        if(str[i]!='0'){
            k=arr[i+1]-1+9*(n-1-i);
            if(k>mx){
                mx=k;
                an=str;
                an[i]--;
                for(ll j=i+1;j<n;j++){
                    an[j]='9';
                }
            }
        }
    }
    a=0;
    while(an[a]=='0')a++;
    str2=an.substr(a,an.size()-a+1);
    O str2<<El
}

Dr
