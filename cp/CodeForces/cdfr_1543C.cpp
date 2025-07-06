//
// Created by me on 07-07-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define FR_(a,c)   for (ll (a)=0;(a)<(c); (a)++)
#define FR_E(a,c)   for (ll (a)=0;(a)<=(c); (a)++)
#define FR_IR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FR_AU(xx,xxs) for(auto (xx):(xxs))
#define srt(ww) sort((ww).begin(),(ww).end())
#define rsrt(ww) sort((ww).rbegin(),(ww).rend())
#define W_(n) while((n)--)
#define WH_ while
#define IL_ while(1)
#define PB_ push_back
#define MP_(a,b) make_pair((a),(b))
#define O_ cout<<
#define PRCN fixed<<setprecision(20)
#define I_ cin>>
#define EL endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef stack<ll> skll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef vector<pair<ll, ll>> vprll;
typedef map<ll,ll>  mpll;
typedef unordered_map<ll,ll> uompll;
typedef set<ll> stll;
const ll t9p7=1000000007;

//ld calc(ld c,ld m, ld p, ld k){
//    O_ "  "<<c<<" "<<m<<" "<<p<<EL
//    if(p==0)return 0.0;
//    if(c==0 && m==0)return p;
//    //if(abs(1-p)<1e-9)return 1;
//
//    ld ans=p,ff;
//    if(c>0){
//        if(c>k){
//            ld extra=c-k;
//            if(m>0){
//                ff=(ld)calc(k,m+extra/2.0,p+extra/2.0,k);
//                O_ "ff:"<<ff<<EL
//                ans+=c*ff;O_ ans<<EL
//
//            }else{
//                ff=(ld)calc(k,m,p+extra,k);
//                ans+=c*ff;O_ ans<<EL O_ "ff:"<<ff<<EL
//            }
//        }else{
//            if(m>0){
//                ff=(ld)calc(0,m+c/2.0,p+c/2.0,k);
//                O_ "ff:"<<ff<<EL
//                ans+=c*ff;O_ ans<<EL
//            }else{
//                ff=(ld)calc(0,m,p+c,k);
//                O_ "ff:"<<ff<<EL
//                ans+=c*ff;O_ ans<<EL
//            }
//        }
//    }
//
//    if(m>0){
//        if(m>k){
//            ld extra=m-k;
//            if(c>0){
//                ans+=m*calc(c+extra/2.0,k,p+extra/2.0,k);O_ ans<<EL
//            }else{
//                ans+=m*calc(c,k,p+extra,k);O_ ans<<EL
//            }
//        }else{
//            if(c>0){
//                ans+=m*calc(c+m/2.0,0,p+m/2.0,k);O_ ans<<EL
//            }else{
//                ans+=m*calc(c,0,p+m,k);O_ ans<<EL
//            }
//        }
//    }
//    O_ "ans:"<<ans<<EL
//    return ans;
//}


void calc2(ld c,ld m, ld p, ld k,ld fac, ld &an,ld h){
    an+=fac*p*h;
    if(c>1e-12){
        if(c>k){
            if(m>1e-12){
                calc2(c-k,m+k/2.0L,p+k/2.0L,k,fac*c,an,h+1);
            }else{
                calc2(c-k,m,p+k,k,fac*c,an,h+1);
            }
        }else{
            if(m>1e-12){
               calc2(0,m+c/2.0L,p+c/2.0L,k,fac*c,an,h+1);
            }else{
                calc2(0,m,p+c,k,fac*c,an,h+1);
            }
        }
    }

    if(m>1e-12){
        if(m>k){
            if(c>1e-12){
                calc2(c+k/2.0L,m-k,p+k/2.0L,k,fac*m,an,h+1);
            }else{
                calc2(c,m-k,p+k,k,fac*m,an,h+1);
            }
        }else{
            if(c>1e-12){
                calc2(c+m/2.0L,0,p+m/2.0L,k,fac*m,an,h+1);
            }else{
               calc2(c,0,p+m,k,fac*m,an,h+1);
            }
        }
    }

}
void soln(ll t){
    O_ PRCN;
    ld m,n,k,a,b,c,cnt=0,ans=0;
    I_ a>>b>>c>>k;
    calc2(a,b,c,k,1.0,ans,1);
    O_ PRCN<<ans<<EL
}

DRIVER
