/*
 * Created by me on 04-01-2022.
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

/*
 *
 * binary search based optimization using optimizationn function
 * compute_for_bin_search is optimization function
 * bin_search_in_function execute binary search to find suitable value
 */

ll compute_for_bin_search(V(ll) &arr, ll v) {
    ll n = arr.size();
    ll val = 0;
    for (ll i = 0; i < n; i++) {
        val += v/arr[i];
    }
    return val;
}
ll bin_search_in_function(V(ll) &arr, ll l,ll r,ll h) {
    //O "lrh "<<l<<" "<<r<<" "<<h<<El
    if (r - l < 10) {//for small number
        //O "smaller"<<El
        ll ans = l;
        for (ll i = r; i >= l; i--) {//smallest ans greater than h
            ll val = compute_for_bin_search(arr, i);
            //O "sm_lp:"<<i<<" "<<val<<El
            if (val >= h)ans = i;//smallest ans greater than h
        }
        return ans;
    }
    if (r >= l) {
        ll mid = l + (r - l) / 2;
        ll mid_val = compute_for_bin_search(arr, mid);
        //O "mid midval "<<mid<<" "<<mid_val<<El


        if (h <= mid_val)
            return bin_search_in_function(arr, l, mid, h);//mid-1  mid-> smallest ans greater equals h
        return bin_search_in_function(arr, mid, r, h);//mid+1 mid-> greater ans smaller equals h
    }
}


ll find_binary_search_range(V(ll) arr,ll k){
    ll x=0;
    //unsigned ll xl=1
    while(compute_for_bin_search(arr,1LL<<x)<k){
        //O "x:"<<x<<" "<<(1LL<<x)<<El
        x++;

    }
    return x;
}

void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    I n>>k;
    V(ll) arr(n);
    F(i,n){
        I arr[i];
    }
    a=find_binary_search_range(arr,k);
    ans=bin_search_in_function(arr,1LL<<(a-1),1LL<<a,k);
    O ans<<El

}

Dr
