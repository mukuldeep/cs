/*
 * Created by me on 26-09-2021.
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
#define t9p7 1e9+7
#define INF 1e17
using namespace std;

void pre(){

}

/*
 * exploding string by delimiter
 */
vector<string> explode(string const & s, char delim)
{
    vector<string> result;
    istringstream iss(s);
    for (string token; getline(iss, token, delim); )
        result.push_back(move(token));
    return result;
}

void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    I str;
    if(str[0]=='.' || str.back()=='.'){
        O "NO"<<El
        return;
    }
    a=0;
    F(i,str.size()){
        if(str[i]=='.'){
            if(a){
                O "NO"<<El
                return;
            }else{
                a=1;
            }
        }else{
            a=0;
        }
    }

    V(S) arr(explode(str,'.'));
    if(arr.size()<=1){
        O "NO"<<El
        return;
    }
    cnt=1;
    if(arr[0].size()>8)cnt=0;
    Fi(i,1,arr.size()-1){
        if(arr[i].size()>11 || arr[i].size()<2){
            cnt=0;
            break;
        }
    }

    if(arr.back().size()>3)cnt=0;
    if(cnt){
        O "YES"<<El
        O arr[0];
        Fi(i,1,arr.size()-1){
            if(arr[i].size()>8){
                O "."<<arr[i].substr(0,arr[i].size()-8)<<El
                O arr[i].substr(arr[i].size()-8);
            }else{
                O "."<<arr[i].substr(0,1)<<El
                O arr[i].substr(1);
            }
        }
        O "."<<arr.back()<<El

    }else{
        O "NO"<<El
    }

}

Dr
