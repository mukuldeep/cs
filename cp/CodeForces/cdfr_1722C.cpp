/*
 * Created by me on 22-10-2022.
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
string soll(int n,string str){
    vector<vector<int>> dp(n+1,vector<int>(26,0));

    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        dp[i][str[i-1]-'a']++;
    }
    string ans="";
    for(int i=2;i<=n;i++){
        double cc=i/2.0;
        for(int j=0;j<=n-i;j++){
            string sstr=str.substr(j,i);
            int flag=0;
            for(int kk=0;kk<26;kk++) {
                if (dp[j + i][kk] - dp[j][kk] > cc) {
                    flag=1;
                    break;
                }
            }
            if(flag){
                if(ans==""){
                    ans=sstr;
                }else if (ans > sstr) {
                    ans = sstr;
                }
            }
        }
        if(ans!="")
            return ans;
    }
    return "ZERO";
}

void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str,xx;
    I n>>str;
    xx=soll(n,str);
    O xx<<El
}

Drt
