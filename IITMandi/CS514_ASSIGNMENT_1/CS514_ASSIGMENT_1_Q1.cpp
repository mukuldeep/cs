/*
 * Created by mukul on 03-09-2024.
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
#define INF 100000000000000000 //1e17
using namespace std;

void pre(){

}

ll gcd(ll a, ll b) {
    if(b>a){
        swap(a,b);
    }
    if(b==0)
        return a;
    return gcd(b,a%b);
}

ll gcd_ex(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd_ex(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll mod_inverse(ll a, ll m){
    ll g, x,y;
    g = gcd_ex(a,m,x,y);
    if(g==1){
        return (x+m)%m;
    }else{
        O "NO SOLUTION EXISTS!"<<El
        return -1;
    }
}

void soln(ll t){
    ll m,n,x,y,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;

    a = 10;
    m = 47;

    //I a>>m;
    //b = 41;



    ll a_p = mod_inverse(a,m);

    O "gcd("<<a<<","<<m<<"):"<<gcd(a,m)<<El
    O "gcd_ex("<<a<<","<<m<<"):"<<gcd_ex(a,m,x,y)<<El
    O "mod_inv("<<a<<","<<m<<"):"<<a_p<<El

    O "a' = "<<a_p<<El
}

Dr


/**
 * Problem statement
 * Given two positive integers a and x, such their gcd is 1, find an integer a'
 * smaller than x such that a ∗ a' has remainder 1 when divided by m. a
 * and m are integers in decimal system having at most 9 digits.
 *
 */


/**
 *  HOW TO RUN
 *  1. Consider soln() as main function for the program
 *  change iff any changes in test cases are required
 *
 */
