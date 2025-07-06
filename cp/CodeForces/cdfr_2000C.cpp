/*
 * Created by me on 21-08-2024.
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


void soln(ll t){
    //O "test t"<<El
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    I n;

    V(ll) el(n);
    F(i,n){
        I el[i];
    }
    I m;

    F(h,m){
        I str;
        if(str.length()!=n){
            O "NO"<<El
            continue;
        }

        Uom(ll,char) num_ch;
        Uom(char,ll) ch_num;
        bool flag = true;
        F(ind,n){
            if(num_ch.find(el[ind])!=num_ch.end()){//found
                if(str[ind]!=num_ch[el[ind]]){ // but elements are not same
                    flag = false;
                    break;
                }


            }else{//elements is new
                if(ch_num.find(str[ind])!=ch_num.end()){// but char is used earlier
                    flag = false;
                    break;
                }
                num_ch.insert({el[ind],str[ind]});
                ch_num.insert({str[ind],el[ind]});
            }
        }
        p_bin(flag);

    }
}

Dr
