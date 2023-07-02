/*
 * Created by me on 02-07-2023.
 * Time complexity O(C*10^n) = O(10^n) where n is 1 to 6
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

void pre(){

}
ll sta_ar[]={0,1,10,100,1000,10000,100000,1000000,10000000};
ll end_ar[]={0,9,99,999,9999,99999,999999,9999999,99999999};
ll nno_ar[]={0,9,90,900,9000,90000,900000,9000000,90000000};
bool is_valid(ll a,ll b, ll c ,ll k){
    if(a<b)
        swap(a,b);
    if(c != a && c != a+1)
        return false;
    ll n_a_1;

    n_a_1=((nno_ar[b]*(nno_ar[b]+1))/2)+(nno_ar[b-1]*nno_ar[b]);
    //O n_a_1<<" ";
    if(a==b){
        n_a_1-=((end_ar[a-1]*(end_ar[a-1]+1))/2);
    }
    //O n_a_1<<" :";

    if(c==a+1 && n_a_1>=k)
        return true;
    if(c==a && (nno_ar[a]*nno_ar[b]-n_a_1)>=k)
        return true;
    return false;
}
ll n_intersection(ll a, ll b, ll c, ll d){
    if(d<a || c>b){ // no intersection
        return 0;
    }else if(c<=a){//c outside a-b (before a)
        if(d<=b){ // d is in a-b
            return d-a+1;
        }else{ // d is outside a-b
            return b-a+1;
        }
    }else if(c <= b){// c in a-b
        if(d<=b){//d in in a-b
            return d-c+1;
        }else{//d outside a-b
            return b-c+1;
        }
    }

    return 0;
}
ll find_nth_c(ll a, ll b, ll c, ll d,ll nth_c){
    if(c<=a){//c outside a-b (before a)
        return a+nth_c-1;
    }else if(c <= b){// c in a-b
        return c+nth_c-1;
    }
}

void single_soln(ll a,ll b, ll c ,ll k){
    ll k_sum=0;
    Fi(i,sta_ar[a],end_ar[a]+1){
        ll sb=i+sta_ar[b], eb=i+end_ar[b], sc=sta_ar[c],ec=end_ar[c];
        ll loc_in=n_intersection(sc,ec,sb,eb);
        if(k_sum+loc_in<k){
            k_sum+=loc_in;
        }else{
            ll nth_c=find_nth_c(sc,ec,sb,eb,k-k_sum);
            O i<<" + "<<(nth_c-i)<<" = "<<nth_c<<El
            return;
        }
    }
    O -1<<El
}

void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    I a>>b>>c>>k;
    if(!is_valid(a,b,c,k)){
        O -1<<El
        return;
    }
    //O "some ans ";
    single_soln(a,b,c,k);

}

Dr
