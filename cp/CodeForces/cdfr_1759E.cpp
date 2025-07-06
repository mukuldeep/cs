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
Uom(ll,V(ll)) states;
void pre(){
    states[2]={2};
    states[3]={3};
    states[4]={2,4};
    states[6]={2,3,6};
    states[12]={2,3,4,6,12};
}
ll max_rec(V(ll) &arr,ll n,ll i,ll state,ll cnt,ll p){
    if(i==n)
        return cnt;
    if(arr[i]<p)
        return max_rec(arr,n,i+1,state,cnt+1,p+(arr[i]/2));
    ll mx_cnt=cnt;
    if(state>1)
    Fa(mul,states[state]){
        if(p*mul>arr[i])
            mx_cnt=max(mx_cnt,max_rec(arr,n,i+1,state/mul,cnt+1,(p*mul)+arr[i]/2));
        else
            mx_cnt=max(mx_cnt,max_rec(arr,n,i,state/mul,cnt,p*mul));
    }
    return mx_cnt;
}

void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    ll state=12;
    I n>>k;
    V(ll) arr(n);
    F(i,n){
        I arr[i];
    }
    Srt(arr)
    cnt=max_rec(arr,n,0,state,0,k);
    //
    /*
     Fa(x,arr){
        if(x<k){
            k+=(x/2);
            cnt++;
        }else{
            if(state>1)
            Fa(mul,states[state]){
                if(k*mul>x){
                    k*=mul;
                    state/=mul;
                    break;
                }
            }
            if(k>x){
                k+=(x/2);
                cnt++;
            }
        }
    }
     */

    O cnt<<El
}

Dr
