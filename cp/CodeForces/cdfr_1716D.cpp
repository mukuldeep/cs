/*
 * Created by me on 14-08-2022.
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
#define ll long
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
#define t9m7  998244353
#define INF 100000000000000000 //1e17
using namespace std;

void pre(){

}


void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    I n>>k;
    V(ll) pre(n+1,0);
    for(ll i=k;i<=n;i+=k){
        pre[i]=1;
    }
//    O 0<<": ";
//    Fa(x,pre){
//        O x<<" ";
//    }O El
    V(ll) tot(pre.begin(),pre.end());
    V(ll) post(n+1,0);

    for(ll i=k+1;((i-1)*i-(k-1)*k)/2<=n;i++){
        //cout<<i<<": ";
        //post.assign(post.size(),0);
        for(ll j=0;j<=n;j++){
            post[j]=0;
            if(j-i>0) {
                post[j] = (pre[j - i] + post[j - i]) % t9m7;
                tot[j] += post[j];
                tot[j] %= t9m7;
            }
        }
//        Fa(x,post){
//            O x<<" ";
//        }O El
        //pre.insert(pre.begin(),post.begin(),post.end());
        pre=post;

    }

    /* O "t: ";
     Fa(x,tot){
         O x<<" ";
     }O El
     */

    Fi(i,1,n+1){
        O tot[i]<<" ";
    }O El

}

Dr
