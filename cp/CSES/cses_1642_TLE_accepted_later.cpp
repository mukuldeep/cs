/*
 * Created by me on 25-12-2021.
 */
#include <bits/stdc++.h>
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1;  //I t;
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
#define ll int
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


void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    I n>>k;
    V(ll) arr(n);
    F(i,n){
        I arr[i];
    }

    Mp(ll,V(P(ll))) mp;
    Fi(i,0,n){
        Fi(j,i+1,n){
            //O i<<" "<<j<<" "<<mp[(k-arr[i]-arr[j])].first<<El
            ll sm=arr[i]+arr[j];
            if(mp.find(k-sm)!=mp.end()) {
                V(P(ll)) vpr=mp[(k - sm)];
                ll cnts=0;
                Fa(pr,vpr) {
                    //P(ll) pr=
                    if (pr.first != i + 1 && pr.first != j + 1 && pr.second != i + 1 && pr.second != j + 1) {
                        O pr.first << " " << pr.second << " " << i + 1 << " " << j + 1 << El
                        return;
                    }
                    cnts++;
                    if(cnts>5)break;
                }
            }else{
                mp[arr[i]+arr[j]].push_back({i+1,j+1});
            }
        }
    }
    O "IMPOSSIBLE"<<El
}

Dr
