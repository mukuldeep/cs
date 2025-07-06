/*
 * Created by me on 05-12-2021.
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


void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    I n;
    V(P2(ll,P(ll))) arr(n);
    V(ll) ar1(n);
    F(i,n)I ar1[i];
    F(i,n){
        I a;
        arr[i]={ar1[i]-a,{ar1[i],a}};
    }
    arr.push_back({0,{1,1}});
    Srt(arr)
    ll pre_x=1,pre_diff=0;
    Fa(a,arr){
        //O a.first<<":"<<a.second.first<<" "<<a.second.second<<El
        if(a.first % 2==0){//even row
            if(pre_diff==a.first){
                ans+=(a.second.second-pre_x);
            }else {
                ans+=ceil((ld)(a.first-pre_diff)/2.0);
            }
        }else{//odd row
            ans+=(a.first-pre_diff)/2;
        }
        pre_x=a.second.second;
        pre_diff=a.first;
    }

    O ans<<El
}

Dr
/*
1
6
3 10 5 8 4 6
2 5  2 4 3 5



 */