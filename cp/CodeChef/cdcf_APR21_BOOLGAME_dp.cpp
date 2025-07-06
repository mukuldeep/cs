//
// Created by me on 08-04-2021.
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
struct rnge{
    ll val,strt,end,intval=0,tot_val=0;
};
bool srtbysec(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    if(a.second==b.second)return a.first<b.first;
    return (a.second < b.second);
}



void soln(ll t){
    ll n,m,k,a,b,c;
    I_ n>>m>>k;
    vll gi(n+1);
    FR_IR(i,0,n)
        I_ gi[i];

    vector<rnge> ranges;
    unordered_map<ll,vll> ranges_end;
    FR_IR(i,0,m){
        I_ a>>b>>c;
        rnge xrnge;
        xrnge.strt=a;
        xrnge.end=b;
        xrnge.val=c;
        ll key=0,rngsum=c;
        FR_IR(j,a-1,b){
            key|=1<<j;
            rngsum+=gi[j];
        }
        //O_ key<<":"<<rngsum<<EL
        xrnge.tot_val=rngsum;
        xrnge.intval=key;
        ranges.PB_(xrnge);
        ranges_end[b].PB_(i);
    }

//    FR_AU(rr,ranges_end[3]){
//        O_ rr<<EL
//    }

    vector<vprll> dp(n+2);
    dp[0].PB_(MP_(0,0));
    FR_IR(i,1,n+1){
        dp[i]=dp[i-1];
        FR_AU(xl,dp[i-1]){
            ll smmx=xl.first+gi[i-1];
            ll smmx_ind=xl.second|=1<<(i-1);
            FR_AU(rr,ranges_end[i]){
                if((smmx_ind & ranges[rr].intval)==ranges[rr].intval){
                    smmx+=ranges[rr].val;
                }
            }
            dp[i].PB_(MP_(smmx,smmx_ind));
        }
        //
        //O_ "ranges ends with "<<i<<" are ";
        FR_AU(rr,ranges_end[i]){
            //O_ rr<<": ";
            ll pre_ind=ranges[rr].strt-1;
            FR_AU(pre_sm_pr,dp[pre_ind]){
                ll r_smmx=pre_sm_pr.first+ranges[rr].tot_val;
                ll r_smmx_ind=pre_sm_pr.second|ranges[rr].intval;

                FR_IR(endswith,pre_ind+1,i+1){
                    FR_AU(rrr,ranges_end[endswith]){
                        if(rrr!=rr && (ranges[rrr].intval&r_smmx_ind)==ranges[rrr].intval)r_smmx+=ranges[rrr].val;
                    }
                }

                dp[i].PB_(MP_(r_smmx,r_smmx_ind));
            }
        }//O_ EL

        //sort current vector
        sort(dp[i].rbegin(),dp[i].rend(),srtbysec);
        //FR_AU(ghjk,dp[i])O_ ghjk.first<<":"<<ghjk.second<<" ";O_ EL

        //removing duplicate
        vprll temp;
        temp.PB_(dp[i][0]);
        FR_IR(ii,1,dp[i].size()){
            if(dp[i][ii].second!=dp[i][ii-1].second)temp.PB_(dp[i][ii]);
        }

        //sort temp
        sort(temp.rbegin(),temp.rend());

        dp[i]=temp;


        //resizing current vector to maximum contraints
        while(dp[i].size()>300)dp[i].pop_back();
    }

//    FR_AU(row,dp){
//        FR_AU(cell,row){
//            O_ cell.first<<":"<<cell.second<<" ";
//        }O_ EL
//    }

    //output
    FR_IR(i,0,k)
        O_ dp[n][i].first<<" ";
    O_ EL

}


TEST_DRIVER
/*
1
4 5 16
-4 -2 5 2
1 3 0
1 4 -3
1 2 6
2 3 8
3 4 7
 ans:20 19 14 13 11 10 5 2 2 1 0 0 0 -2 -2 -4


1
4 2 16
-4 -2 5 2
1 3 0
1 4 -3
 ans: 7 5 5 3 3 2 1 0 0 -1 -2 -2 -2 -4 -4 -6


1
4 1 16
-4 -2 5 2
1 1 90
 ans: 93 91 91 89 88 86 86 84 7 5 5 3 2 0 0 -2

 1
 5 5 32
 -9 0 23 6 -7
 1 4 9
 2 4 -6
 2 3 19
 1 3 -4
 4 5 43
    ans: 78 74 65 56 42 42 42 42 38 35 33 33 29 29 23 22 20 16 14 7 6 6 0 0 -3 -3 -7 -7 -9 -9 -16 -16

    1
    10 10 32
    9 -4 3 -6 12 -7 9 16 -1 14
    1 5 -8
    2 4 16
    3 8 18
    5 7 -3
    2 5 -10
    3 4 12
    2 7 0
    4 6 -3
    7 9 7
    1 2 6
ans: 81 80 80 75 75 75 74 74 74 73 71 71 69 69 69 68 68 68 67 67 66 66 66 66 66 66 65 65 65 63 63 62

 */
