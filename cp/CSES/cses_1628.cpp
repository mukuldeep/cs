/*
 * Created by me on 19-12-2021.
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

void allSubsetSums(V(ll) &arr, ll l, ll r, ll sum,Uom(ll,ll) &mp,ll &k)
{   if(sum>k)return;
    if (l > r) {
        mp[sum]++;
        return;
    }
    allSubsetSums(arr, l + 1, r, sum + arr[l],mp,k);
    allSubsetSums(arr, l + 1, r, sum,mp,k);
}

void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    I n>>k;
    V(ll) arr(n);
    Uom(ll,ll) fs,ss;
    F(i,n){
        I arr[i];
        cnt+=arr[i];
    }
    Rsrt(arr);
    if(cnt<k){
        O 0<<El
        return;
    }
    ll h=n/2;
    allSubsetSums(arr,0,h,0,fs,k);
    allSubsetSums(arr,h+1,n-1,0,ss,k);

    //O fs.size()<<El
    Fa(xx,fs){
        if(xx.first<=k && ss[k-xx.first]){
            ans+=(xx.second * ss[k-xx.first]);
        }
    }
    O ans<<El
}

Dr
