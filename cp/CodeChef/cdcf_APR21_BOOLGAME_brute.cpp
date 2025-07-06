//
// Created by me on 05-04-2021.
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

void solnk1(ll t,ll n, ll m, ll k){
    ll a,b,c,maxsum=0,max_bin=0;
    vll gi(n+1);
    FR_IR(i,0,n) {
        I_ gi[i];
        if(gi[i]>=0){
            maxsum+=gi[i];
            max_bin|=(1<<i);
        }
    }

    vprll rngi,rng;
    vll rngsmi;
    FR_IR(i,0,m){
        I_ a>>b>>c;
        a--;
        rng.PB_(MP_(a,b));
        ll key=0,rngsum=c,rngsumm=c;
        FR_IR(j,a,b){
            key|=1<<j;
            rngsum+=gi[j];
            rngsumm+=gi[j]<0?gi[j]:0;
        }
        rngsmi.PB_(rngsum);
        rngi.PB_(MP_(key,c));
        if(rngsumm>=0){
            maxsum+=rngsumm;
            max_bin|=key;
        }
    }
    //O_ decToBinary(max_bin)<<" "<<maxsum<<EL

    FR_IR(i,0,m){
        if(rngsmi[i]<0 && (rngi[i].first & max_bin)==rngi[i].first){
            //find the smallest number from the range remove it
            a=rng[i].first,b=rng[i].second;
            ll sm_num=gi[a],sm_ind=a;
            FR_IR(j,a,b){
                if(gi[j]<sm_num){
                    sm_num=gi[j];
                    sm_ind=j;
                }
            }
            maxsum-=sm_num;
            max_bin&=(~(1<<sm_ind));
        }
    }

    O_ maxsum<<EL
}

//brute force
void soln(ll t){
    ll n,m,k,a,b,c;
    I_ n>>m>>k;
//    if(k==1){
//        solnk1(t,n,m,k);
//        return;
//    }
    vll gi(n+1);
    vprll rngi;
    FR_IR(i,0,n)
        I_ gi[i];
    FR_IR(i,0,m){
        I_ a>>b>>c;
        a--;
        ll key=0;
        FR_IR(j,a,b)key|=1<<j;
        rngi.PB_(MP_(key,c));
    }
    ll max_rng=1<<n;
    vll xarr;
    FR_IR(i,0,max_rng){
        ll lans=0;
        FR_IR(j,0,n){
            if(i&(1<<j))
                lans+=gi[j];
        }
        for(auto xd:rngi){
            if((i&(xd.first))==xd.first)lans+=xd.second;
        }
        xarr.PB_(lans);
    }
    sort(xarr.begin(),xarr.end());

    auto itr=xarr.end();
    itr--;
    while(k--){
        O_ *itr<<" ";itr--;
    }O_ EL
}

TEST_DRIVER
