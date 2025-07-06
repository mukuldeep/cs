/*
 * Created by me on 29-09-2021.
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
#define t9p7 1e9+7
#define INF 1e17
using namespace std;

void pre(){

}
ll tot_cal(V(ll) arr){
    ll cnt=0,n=arr.size();
    Fi(i,1,n-1){
        if((arr[i-1]<arr[i] && arr[i]>arr[i+1])|| (arr[i-1]>arr[i] && arr[i]<arr[i+1]))
            cnt++;
    }
    return cnt;
}

void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    I n;
    V(ll) arr(n);
    F(i,n){
        I arr[i];
    }
    cnt=tot_cal(arr);
    mx=0;
    Fi(i,1,n-1){
        ll lcnt=0,lpcnt=0;
        ll strt,ennd;
        strt=i-2;
        ennd=i+2;
        if(strt<0)strt=0;
        if(ennd>n-1)ennd=n-1;
        V(ll) tar(arr.begin()+strt,arr.begin()+ennd+1);
        //Fa(xd,tar)O xd<<" ";O El
        ll before=tot_cal(tar);

        ll temp=arr[i];//
        arr[i]=arr[i-1];
        V(ll) tar2(arr.begin()+strt,arr.begin()+ennd+1);
        ll after_1=tot_cal(tar2);

        arr[i]=arr[i+1];
        V(ll) tar3(arr.begin()+strt,arr.begin()+ennd+1);
        ll after_2=tot_cal(tar3);

        arr[i]=temp;

        mx=max(mx,max(before-after_1,before-after_2));
    }
    ans=cnt-mx;
    O ans<<El

}

Dr
