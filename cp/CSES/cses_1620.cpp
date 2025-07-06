/*
 * Created by me on 29-08-2024.
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
#define t9p7 1000000007
#define INF 100000000000000000 //1e17
using namespace std;

void pre(){

}

ll yields(V(ll)&arr, ll time){
    ll ans = 0;
    Fa(xxx,arr){
        ans+=(time/xxx);
    }
    return ans;
}

ll binSrc(V(ll)& arr,ll l,ll h,ll el){

    ll mid = (l+h)/2;
    ll y_l = yields(arr,l);
    //ll y_h = yields(arr,h);
    ll y_mid = yields(arr,mid);

    //cout<<"l:"<<l<<" h:"<<h<<" el:"<<el<<" yield l:"<<y_l<<" mid:"<<y_mid<<El


    if(y_l==el){
        return l;
    }

    if(l==h){
        return l;
    }

    if(el<=y_mid){
        return binSrc(arr,l,mid,el);
    }
    return binSrc(arr,mid+1,h,el);
}


void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    I n>>t;
    V(ll) arr(n);
    F(i,n){
        I arr[i];
    }
    Srt(arr)


    ll low = 1, high = 2;
    if(yields(arr,1)>=t){
        O 1<<El
        return;
    }

    while(yields(arr,high)<t){
        //O "yield at "<<high<<" : "<<yields(arr,high)<<El
        high = (high<<1);
        low = (low<<1);
    }

    //O "Low-high:"<<low<<"-"<<high<<El


    //O "ans:"<<binSrc(arr,low,high,t);
    O binSrc(arr,low,high,t);
}

Dr
