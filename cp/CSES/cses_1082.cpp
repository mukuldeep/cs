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
#define t9p7 1000000007
#define INF 1e17
using namespace std;

void pre(){

}
ll mod_inv(ll a, ll m)
{
    ll m0 = m;
    ll y=0,x=1;
    if (m==1)
        return 0;
    while (a>1) {
        ll q=a/m;
        ll t=m;
        m=a%m,a=t;
        t=y;
        y=x-q*y;
        x=t;
    }
    if(x<0)
        x+=m0;
    return x;
}

/*
 * Count total no of factor of n in T=O(sqrt(n)) S=O(1)
 */
ll sumFactors(ll n)
{   ll cnt=0,cnt1=0;
//    for (ll i=1; i<=n; i++) {
//        ll x=n/i;
//        //O i<<":"<<x<<El
//        cnt1+=x*i;
//    }

    ll sqn=sqrt(n);
    ll last=n;
    cnt+=n;cnt%=t9p7;
    for (ll i=2; i<=sqn; i++){
        ll next=n/i;
        cnt+=(next*i)%t9p7;
        //if(cnt<0)O cnt<<"->1 ";
        cnt%=t9p7;

        cnt+=((((((last%t9p7)*((last+1)%t9p7))%t9p7)*mod_inv(2,t9p7))%t9p7)*(i-1)%t9p7)%t9p7;
        //if(cnt<0)O cnt<<"->3 ";
        cnt%=t9p7;

        cnt-=((((((next%t9p7)*((next+1)%t9p7))%t9p7)*mod_inv(2,t9p7))%t9p7)*((i-1)%t9p7))%t9p7;
        cnt+=t9p7;cnt%=t9p7;
        //if(cnt<0)O cnt<<"->2 ";cnt%=t9p7;

        last=next;
    }
    //O cnt<<El
    ll next=n/sqn;
    cnt+=((last*(last+1))/2-(sqn*(sqn+1))/2)*(sqn);cnt%=t9p7;

//    if(cnt1!=cnt){
//        O "F:"<<n<<" expected:"<<cnt1<<" found:"<<cnt<<El
//    }

    cnt%=t9p7;
    return cnt;
}


void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    I n;
    O sumFactors(n)<<El
}

Dr
