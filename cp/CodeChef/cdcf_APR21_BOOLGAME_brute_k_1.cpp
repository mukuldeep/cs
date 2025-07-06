//
// Created by me on 06-04-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
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

struct rnge{
    ll val,strt,end,intval=0,tot_val=0;
};

string decToBinary(int n)
{
    if(!n)return "0";
    int binaryNum[64];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    string str="";
    for (int j = i - 1; j >= 0; j--){
        str+=binaryNum[j]?"1":"0";
    }
        //cout << binaryNum[j];
    return str;
}

void soln(ll t){
    ll n,m,k,a,b,c,maxsum=0,max_bin=0;
    I_ n>>m>>k;

    vll gi(n+1);
    multimap<ll,ll,greater<ll>> giind;
    FR_IR(i,0,n) {
        I_ gi[i];
        giind.insert(MP_(gi[i],i));
    }

    for(auto xx:giind){
        O_ xx.first<<" "<<xx.second<<EL
    }

    vector<rnge> rangei;
    multimap<ll,ll,greater<ll>> ranges;
    FR_IR(i,0,m) {
        I_ a >> b >> c;
        a--;
        rnge xx;
        xx.strt=a;
        xx.end=b;
        xx.val=c;
        ll key=0,rngsum=c;
        FR_IR(j,a,b){
            key|=1<<j;
            rngsum+=gi[j];
        }
        xx.intval=key;
        xx.tot_val=rngsum;
        //ranges.insert(MP_(rngsum,i));
        rangei.PB_(xx);
    }

    FR_IR(i,0,m){
        FR_IR(j,0,m){
            if(i!=j){
                if(rangei[j].strt<=rangei[i].strt && rangei[i].end<=rangei[j].end){
                    rangei[j].tot_val+=rangei[i].val;
                }
            }
        }
    }
    FR_IR(i,0,m){
        ranges.insert(MP_(rangei[i].tot_val,i));
    }

    for(auto xx:ranges){
        O_ xx.first<<" "<<EL
    }

    ll intind=0,mx_sm=0;
    while(ranges.begin()->first>=0 || giind.begin()->first>=0){
        if(ranges.begin()->first>giind.begin()->first){
            if(rangei[ranges.begin()->second].intval & intind){
                //
                ll index=ranges.begin()->second;
                rnge xx=rangei[index];
                FR_IR(jj,xx.strt,xx.end){
                    if(intind & (1<<jj))xx.tot_val-=gi[jj];
                }
                rangei[index]=xx;
                ranges.erase(ranges.begin());
                ranges.insert(MP_(xx.tot_val,index));
            }else{
                mx_sm+=ranges.begin()->first;
                intind|=(rangei[ranges.begin()->second].intval);
                ranges.erase(ranges.begin());
            }
        }else{
            if(!(intind & (1<<giind.begin()->second))) {
                mx_sm += giind.begin()->first;
                intind |= (1 << giind.begin()->second);
            }
            giind.erase(giind.begin());
        }
    }
    O_ mx_sm<<EL
    O_ decToBinary(intind)<<EL


//    vprll rngi,rng;
//    vll rngsmi;
//    FR_IR(i,0,m){
//        I_ a>>b>>c;
//        a--;
//        rng.PB_(MP_(a,b));
//        ll key=0,rngsum=c,rngsumm=c;
//        FR_IR(j,a,b){
//            key|=1<<j;
//            rngsum+=gi[j];
//            rngsumm+=gi[j]<0?gi[j]:0;
//        }
//        rngsmi.PB_(rngsum);
//        rngi.PB_(MP_(key,c));
//        if(rngsumm>=0){
//            maxsum+=rngsumm;
//            max_bin|=key;
//        }
//    }
//    //O_ decToBinary(max_bin)<<" "<<maxsum<<EL
//
//    FR_IR(i,0,m){
//        if(rngsmi[i]<0 && (rngi[i].first & max_bin)==rngi[i].first){
//            //find the smallest number from the range remove it
//            a=rng[i].first,b=rng[i].second;
//            ll sm_num=gi[a],sm_ind=a;
//            FR_IR(j,a,b){
//                if(gi[j]<sm_num){
//                    sm_num=gi[j];
//                    sm_ind=j;
//                }
//            }
//            maxsum-=sm_num;
//            max_bin&=(~(1<<sm_ind));
//        }
//    }
//
//    O_ maxsum<<EL
}


TEST_DRIVER
/*

1
10 5 10
-1 0 3 -8 7 -7 4 2 -3 10
2 5 -3
4 6 7
6 7 -3
7 9 5
8 9 -3

ans:          26 26 25 25 25 25 24 24 24 24
ans 4 ranges: 28 28 27 27 26 26 25 25 25 25


 */