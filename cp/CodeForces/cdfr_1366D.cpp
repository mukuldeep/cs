/*
 * Created by me on 24-11-2021.
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

ll const prime_upto=10000005;
ll prime[prime_upto + 1]={0};
void SieveOfEratosthenes(ll n=prime_upto)
{
    //memset(prime, 0, sizeof(prime));
    for (ll p = 2; p * p <= n; p++)
    {
        if (!prime[p])
        {
            for (ll i = p * p; i <= n; i += p)
                if(!prime[i])prime[i]=p;
        }
    }
}


void pre(){
    SieveOfEratosthenes();
}


void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    I n;
    V(ll) arr(n+1),arr2(n+1);
    F(i,n){
        I a;
        if(!prime[a]){
            arr[i]=-1;
            arr2[i]=-1;
        }else{
            b=a;
            while(b%prime[a]==0){
                cnt++;
                b/=prime[a];
            }
            if(b==1){
                arr[i]=-1;
                arr2[i]=-1;
            }else{
                arr[i]=b;
                arr2[i]=a/b;
            }
        }
    }

    F(i,n)O arr[i]<<" ";O El
    F(i,n)O arr2[i]<<" ";O El
}

Dr
