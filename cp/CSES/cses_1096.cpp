/*
 * Created by me on 25-12-2021.
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
ll pow_ex(ll a,ll b, ll p=t9p7){
    ll res=1;
    a%=p;
    if(b==0)return 1;
    if(a==0)return 0;
    Wh(b){
        if(b&1)res=(res*a)%p;
        b>>=1;
        a=(a*a)%p;
    }
    return res;
}
template <typename T>
class matrix{
public:
    ll row,col;
    V(V(T)) mat;

    matrix(ll row,ll col,V(V(T)) mat){
        this->row=row;
        this->col=col;
        this->mat=mat;
    }

    V(V(T)) matrix_multiplication(V(V(T)) mat1,V(V(T)) mat2){
        V(V(T)) ans(mat1.size(),V(T)(mat2[0].size()));
        if(mat1[0].size()!=mat2.size()){
            O "error: mismatches in dimensions of the matrices"<<El
        }else{
            for (ll i = 0; i < mat1.size(); i++)
            {
                for (ll j = 0; j < mat1[0].size(); j++)
                {
                    ans[i][j] = 0;
                    for (ll x = 0; x < mat1[0].size() ; x++)
                    {
                        ans[i][j]+= (mat1[i][x] * mat2[x][j])%t9p7;
                        ans[i][j]%=t9p7;
                    }
                }
            }
        }
        return ans;
    }

    V(V(T)) matrix_binary_exponentiation(ll n){
        V(V(T)) res = mat,a=mat;
        n--;

        while (n > 0) {
            if (n & 1)
                res =matrix_multiplication(res,a);
            a=matrix_multiplication(a,a);
            n >>= 1;
        }
        return res;
    }
};

ll ways_cnt(ll n){
    V(ll) dp(n+1,0);
    dp[0]=1;
    Fi(i,1,n+1){
        Fi(j,1,7){
            if(i-j>=0){
                dp[i]+=dp[i-j]%t9p7;
            }
        }
    }

    //*
     Fi(i,1,n+1){
        O dp[i]<<" ";
    }O El
     //*/

    return dp[n];
}

void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    I n;
    if(n==1){
        O 1<<El
        return;
    }
    /*k=n/60;
    a=n%60;
    ans=pow_ex(4661099806,k)*ways_cnt(a);
    ans%=t9p7;
    O ans<<El
     */

    V(V(ll)) arr={
            {0,0,0,0,0,1},
            {1,0,0,0,0,1},
            {0,1,0,0,0,1},
            {0,0,1,0,0,1},
            {0,0,0,1,0,1},
            {0,0,0,0,1,1}
    };
    matrix<ll> mat(6,6,arr);

    //for(ll i=1;i<=n;i++){
        V(V(ll)) res = mat.matrix_binary_exponentiation(n-1);
        V(V(ll)) res2 = mat.matrix_multiplication({{1,2,4,8,16,32}}, res);
        O res2[0][0]<<" ";
//        Fa(xd, res2) {
//            Fa(xxd, xd) {
//                O xxd << " ";
//            }
//            O El
//        }
    //}

    //ways_cnt(n);
}

Dr
