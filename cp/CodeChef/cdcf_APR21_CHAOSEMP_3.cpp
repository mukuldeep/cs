//
// Created by me on 09-04-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1,q,d;I_ t>>q>>d;W_(t)soln(t,q,d);return 0;}
#define TEST_DRIVER int cc_main(){SYNC ll t=1,q,d;I_ t>>q>>d;W_(t)soln(t,q,d);return 0;}
#define FR_(a,c)   for (ll (a)=0;(a)<(c); (a)++)
#define FR_E(a,c)   for (ll (a)=0;(a)<=(c); (a)++)
#define FR_IR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FR_AU(xx,xxs) for(auto (xx):(xxs))
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
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef vector<pair<ll, ll>> vprll;
typedef map<ll,ll>  mpll;
typedef unordered_map<ll,ll> uompll;


void d_0(){
    ll tx,ty,bx,by,rdr=0;
    tx=ty=-1000000000000000005;
    bx=by=1000000000000000005;
    //O_ "in d_0 "<<tx<<EL;
    string res="MM";
    while(res!="O"){
        ll hx,hy;
        hx=(tx+bx)/2;
        hy=(ty+by)/2;
        if(rdr)
            O_ 2<<" "<<tx<<" "<<ty<<" "<<bx<<" "<<by<<EL
        else
            O_ 1<<" "<<hx<<" "<<hy<<EL
        I_ res;
        if(res=="PP"){
            bx=hx-1;
            by=hy-1;
        }else if(res=="PN"){
            bx=hx-1;
            ty=hy+1;
        }else if(res=="PY"){
            bx=hx-1;
            by=ty=hy;
            rdr=1;
        }else if(res=="NP"){
            by=hy-1;
            tx=hx+1;
        }else if(res=="NN"){
            tx=hx+1;
            ty=hy+1;
        }else if(res=="NY"){
            tx=hx+1;
            by=ty=hy;
            rdr=1;
        }else if(res=="XP"){
            bx=tx=hx;
            by=hy-1;
            rdr=1;
        }else if(res=="XN"){
            bx=tx=hx;
            ty=hy+1;
            rdr=1;
        }
    }

}

void d_1(){
    ll tx,ty,bx,by,three=0,weapon=1;
    tx=ty=-1000000000000000001;
    bx=by=1000000000000000001;
    string res="MM";
    while(res!="O"){
        if(weapon==2){
            if(bx-tx==3 && by-ty==3){
                O_ 2<<" "<<tx<<" "<<ty<<" "<<tx+2<<" "<<by<<EL
                I_ res;
                if(res=="O")break;
                else if(res=="IN")bx=tx+2;
                else{
                    tx+=2;
                    bx++;
                }
            }
            if(bx-tx==2 && by-ty==3){
                O_ 2<<" "<<tx<<" "<<ty<<" "<<bx<<" "<<ty+2<<EL
                I_ res;
                if(res=="IN") {
                    O_ 2<<" "<<tx<<" "<<ty<<" "<<bx<<" "<<ty+2<<EL
                    I_ res;
                }else if(res=="OUT"){
                    O_ 2<<" "<<tx<<" "<<ty+2<<" "<<bx<<" "<<ty+4<<EL
                    I_ res;
                }
                break;
            }
            if(bx-tx==3 && by-ty==2){
                O_ 2<<" "<<tx<<" "<<ty<<" "<<tx+2<<" "<<by<<EL
                I_ res;
                if(res=="IN") {
                    O_ 2<<" "<<tx<<" "<<ty<<" "<<tx+2<<" "<<by<<EL
                    I_ res;
                }else if(res=="OUT"){
                    O_ 2<<" "<<tx+2<<" "<<ty<<" "<<tx+4<<" "<<by<<EL
                    I_ res;
                }
                break;
            }else{
                O_ 2<<" "<<tx<<" "<<ty<<" "<<bx<<" "<<by<<EL
                I_ res;
                break;
            }
        }else if(weapon==1) {
            if((bx-tx)>=2 && (by-ty)>=2) {
                ll hx, hy;
                hx = (tx + bx) / 2;
                hy = (ty + by) / 2;

                O_ 1 << " " << hx << " " << hy << EL
                I_ res;
                if (res == "PP") {
                    bx = hx;
                    by = hy;
                    tx--;
                    ty--;
                } else if (res == "PN") {
                    bx = hx;
                    ty = hy;
                    tx--;
                    by++;
                } else if (res == "PY") {
                    bx = hx;
                    by = hy + 1;
                    ty = hy - 1;
                    tx = tx - 1;
                    three = 1;
                } else if (res == "NP") {
                    by = hy;
                    tx = hx;
                    ty--;
                    bx++;
                } else if (res == "NN") {
                    tx = hx;
                    ty = hy;
                    bx++;
                    by++;
                } else if (res == "NY") {
                    tx = hx;
                    by = hy + 1;
                    ty = hy - 1;
                    bx = bx + 1;
                    three = 1;
                } else if (res == "XP") {
                    bx = hx + 1;
                    tx = hx - 1;
                    by = hy;
                    ty--;
                    three = 1;
                } else if (res == "XN") {
                    bx = hx + 1;
                    tx = hx - 1;
                    ty = hy;
                    by++;
                    three = 1;
                } else if (res == "O" || res=="FAILED")break;

                if((bx-tx)<=3 && (by-ty)<=3)weapon=2;
            }else{
                weapon=2;
                O_ 2<<" "<<tx<<" "<<ty<<" "<<bx<<" "<<by<<EL
                I_ res;
                break;
            }
        }
        cout.flush();

    }
    cout.flush();

}
void soln(ll t,ll q,ll d){
    if(d) {
        d_1();
    }else{
        d_0();
    }
}

DRIVER
