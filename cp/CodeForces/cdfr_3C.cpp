/*
 * Created by me on 11-09-2021.
 */
#include <bits/stdc++.h>
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1;//  I t;
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
ll whowins(V(S) &ar){
    ll cntx=0,cnt0=0,winner=-1;
    F(i,3){
        if(ar[i][0]=='X' && ar[i][1]=='X' && ar[i][2]=='X'){
            cntx++;
            winner=1;
        }
        if(ar[i][0]=='0' && ar[i][1]=='0' && ar[i][2]=='0'){
            cnt0++;
            winner=2;
        }
    }
    F(i,3){
        if(ar[0][i]=='X' && ar[1][i]=='X' && ar[2][i]=='X'){
            cntx++;
            winner=1;
        }
        if(ar[0][i]=='0' && ar[1][i]=='0' && ar[2][i]=='0'){
            cnt0++;
            winner=2;
        }
    }

    if(ar[0][0]=='X' && ar[1][1]=='X' && ar[2][2]=='X'){
        cntx++;winner=1;
    }
    if(ar[2][0]=='X' && ar[1][1]=='X' && ar[0][2]=='X'){
        cntx++;winner=1;
    }
    if(ar[0][0]=='0' && ar[1][1]=='0' && ar[2][2]=='0'){
        cnt0++;winner=2;
    }
    if(ar[2][0]=='0' && ar[1][1]=='0' && ar[0][2]=='0'){
        cnt0++;winner=2;
    }
    if(cnt0 && cntx)return 0;
    return winner;
}

void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    V(S) arr(3);
    a=0;b=0;
    F(i,3){
        I arr[i];
        Fa(ch,arr[i]){
            if(ch=='X')a++;
            else if(ch=='0')b++;
        }
    }
    if(a!=b && a-b!=1){
        O "illegal"<<El
    }else{
        ans=whowins(arr);
        switch (ans) {
            case 0: O "illegal"<<El break;
            case -1: if(a==b){O "first"<<El }else{if(a+b==9)O "draw"<<El else O "second"<<El }break;
            case 1: if(a-b==1)O "the first player won"<<El else O "illegal"<<El break;
            case 2: if(a==b)O "the second player won"<<El else O "illegal"<<El break;
        }
    }

}

Dr
