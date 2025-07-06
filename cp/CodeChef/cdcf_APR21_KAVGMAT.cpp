//
// Created by me on 03-04-2021.
//
#include <bits/stdc++.h>
#define DRIVER int main(){ll t=1;I_ t;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){ll t=1;I_ t;W_(t)soln(t);return 0;}
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
ld get_avg(vector<vll> &sarr,ll sx,ll sy,ll size){
    ld ans=sarr[sx+size-1][sy+size-1];
    if(sx>0)ans-=sarr[sx-1][sy+size-1];
    if(sy>0)ans-=sarr[sx+size-1][sy-1];
    if(sx>0 && sy>0)ans+=sarr[sx-1][sy-1];
    ans/=(ld)(size*size);
    return ans;
}
ll find_position(vector<vll> &sarr,ll row,ll strt,ll end,ll size,ll k){
    //O_ "\t in binsearch s:"<<strt<<" E:"<<end<<EL
    if(strt==end){
        if(get_avg(sarr,row,strt,size)<k)
            return -1;
        return strt;
    }
    ll mid=(strt+end)/2;
    ll val=get_avg(sarr,row,mid,size);
    if(val<k)return find_position(sarr,row,mid+1,end,size,k);
    return find_position(sarr,row,strt,mid,size,k);
}

void soln(ll t){
    ll n,m,k,a,b,c,cnt=0;
    I_ n>>m>>k;
    vector<vll> arr,sarr;
    vll last_pos(n+1,m);
    arr.assign(n,vll(m,0));
    sarr.assign(n,vll(m,0));

    FR_IR(i,0,n){
        ll cur=0;
        FR_IR(j,0,m){
            I_ arr[i][j];
            if(arr[i][j]>=k){
                cnt++;
                if(last_pos[i]==m)last_pos[i]=j;
            }
            cur+=arr[i][j];
            if(i){
                sarr[i][j]=sarr[i-1][j]+cur;
            }else{
                sarr[i][j]=cur;
            }
        }
    }
    ll pre_pos=m;
    FR_IR(size,2,min(n,m)+1){
        //O_ "size:"<<size<<EL
        pre_pos=m+1;
        FR_IR(row,0,n-size+1){
            //O_ "\t row:"<<row<<EL
            ll pos=find_position(sarr,row,0,min(m-size,pre_pos),size,k);
            //O_ "\t\t pos:"<<pos<<EL
            if(pos!=-1){
                cnt+=(m-size-pos+1);
                pre_pos=pos;
            }
        }
    }

    O_ cnt<<EL


//    ll q;
//    ll w,e,r;
//    I_ q;
//    FR_IR(i,0,q) {
//        I_ w >> r;
//        O_ find_position(sarr,w,0,m-r,r,k)<<EL
//    }


}

TEST_DRIVER
/*

 1
 5 5 10
 1 2 3 4 5
 2 4 6 8 10
 3 6 9 12 15
 4 8 12 16 20
 5 10 15 20 25

 1
3 6 7
2 2 3 4 5 6
3 4 5 6 7 8
4 5 5 7 8 9

 */