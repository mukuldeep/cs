/*
 * Created by me on 12-01-2022.
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

ll find_nexts(S str,ll pre){
    //O "find_next:"<<str<<" pre:"<<pre<<El
    ll fd=(str[0]-'0');
    if(str.size()<2){
        ll ans=(fd+1)-(pre<=fd?1:0);
        //O "one digit:"<<ans<<El
        return ans;
    }
    /*if(fd==pre) {
        //O "fd==pre 0"<<El
        return 0;
    }*/
    if(pre<fd){
        ll ans=(fd-1)*(ll)pow(9,(str.size()-1))+(pre==fd?0:find_nexts(str.substr(1),fd));
        //O "pre<=fd:"<<ans<<El
        return ans;
    }else{
        ll ans=(fd-((pre==10)?1:0))*(ll)pow(9,(str.size()-1))+(pre==fd?0:find_nexts(str.substr(1),fd));
        //O "pre>fd:"<<ans<<El
        return ans;
    }
}

ll find_bet_0_n(ll n){
    if(n<11)return n;

    ll digit_cnt=0,tempn=n,pow9=1,bef10xcnt=0;
    ll ans=0;

    tempn/=10;
    digit_cnt++;
    while(tempn){
        pow9*=9;
        digit_cnt++;
        bef10xcnt+=pow9;
        tempn/=10;
        //O digit_cnt<<":"<<pow9<<El
    }

    S str=to_string(n);
    //O str<<El
    ans=find_nexts(str,10);
    //O "from bef10cnt:"<<bef10xcnt<<" af10cnt:"<<ans<<" total:"<<ans+bef10xcnt<<El
    return ans+bef10xcnt;
}

void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    I a>>b;
    c=find_bet_0_n(a-1);
    d=find_bet_0_n(b);
    O d-c<<El
}

Dr
