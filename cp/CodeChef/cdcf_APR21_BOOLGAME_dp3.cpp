//
// Created by me on 09-04-2021.
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
    ll val,strt,end,intval,tot_val;
};
bool srtbysec(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    if(a.second==b.second)return a.first<b.first;
    return (a.second < b.second);
}

void prnt(vector<vprll> dp){
    FR_AU(row,dp){
        FR_AU(cell,row){
            O_ cell.first<<":"<<cell.second<<" ";
        }O_ EL
    }
}
vprll srt_rem_dup(vprll &arr){
    if(arr.size()==0)return arr;
    sort(arr.rbegin(),arr.rend(),srtbysec);
    vprll temp;
    temp.PB_(arr[0]);
    FR_IR(ii,1,arr.size()){
        if(arr[ii].second!=arr[ii-1].second)temp.PB_(arr[ii]);
    }
    arr=temp;
    return temp;
}

void soln(ll t){
    ll n,m,k,a,b,c;
    I_ n>>m>>k;

    priority_queue<ll,vll,greater<ll>> mnhp;
    vll gi(n+1),presum(n+1,0),keystore(n+1,0);
    FR_IR(i,0,n) {
        I_ gi[i];
        presum[i+1]+=presum[i]+gi[i];
        keystore[i+1]|=keystore[i]|(1<<i);
    }

    vector<rnge> ranges;
    unordered_map<ll,vll> ranges_end,ranges_start;
    FR_IR(i,0,m){
        I_ a>>b>>c;
        rnge xrnge;
        xrnge.strt=a;xrnge.end=b;xrnge.val=c;
        xrnge.tot_val=presum[b]-presum[a-1];
        xrnge.intval=(keystore[b]^keystore[a-1]);
        ranges.PB_(xrnge);ranges_end[b].PB_(i);ranges_start[a].PB_(i);
    }

    vector<vprll> solid1(n+1,vprll(n+1,MP_(0,0)));

    FR_IR(i,1,n+1){
        FR_IR(j,i,n+1){
            ll key=keystore[j]^keystore[i-1];
            ll vall=presum[j]-presum[i-1];
            FR_AU(jj,ranges){
                if((jj.intval&key)==jj.intval)vall+=jj.val;
            }
            solid1[i][j].first=vall;
            solid1[i][j].second=key;
            //O_ vall<<":"<<key<<" ";
        }//O_ EL
    }


//    FR_AU(rr,ranges_end[3]){
//        O_ rr<<EL
//    }

    vector<vprll> dp(n+2);
    dp[0].PB_(MP_(0,0));
    mnhp.push(0);
    FR_AU(st_ind,ranges_start[1]){
        ll indx=ranges[st_ind].intval;
        ll vlmx=ranges[st_ind].tot_val;
        FR_AU(rng0,ranges)
            if((rng0.intval&indx)==rng0.intval)vlmx+=rng0.val;
        dp[ranges[st_ind].end].PB_(MP_(vlmx,indx));
        mnhp.push(vlmx);
        while(mnhp.size()>k)mnhp.pop();
    }
    //prnt(dp);
    FR_IR(i,1,n+1){

        FR_AU(dpi_1,dp[i-1])dp[i].PB_(dpi_1);//not considering this bit. case 1#

        FR_AU(dpi_1,dp[i-1]){//considering this bit. case 2#
            ll smmx=dpi_1.first+gi[i-1];
            ll smmx_ind=dpi_1.second|(1<<(i-1));
            FR_AU(rr,ranges_end[i]){
                if((smmx_ind & ranges[rr].intval)==ranges[rr].intval){
                    smmx+=ranges[rr].val;
                }
            }
            dp[i].PB_(MP_(smmx,smmx_ind));
            mnhp.push(smmx);
            while(mnhp.size()>k)mnhp.pop();
        }

        //sort and remove duplicate
        vprll temp=srt_rem_dup(dp[i]);

        //for ranges starts with next
        FR_AU(ip1_ind,ranges_start[i+1]){
            FR_AU(cur_prs,temp){
                ll n_ind=cur_prs.second|ranges[ip1_ind].intval;
                ll n_val=cur_prs.first+ranges[ip1_ind].tot_val;
                FR_IR(rr_ii,i+1,ranges[ip1_ind].end+1) {
                    FR_AU(all_rng,ranges_end[rr_ii]){
                            if ((ranges[all_rng].intval & n_ind) == ranges[all_rng].intval)n_val += ranges[all_rng].val;
                    }
                }
                if(n_val>mnhp.top()) {
                    dp[ranges[ip1_ind].end].PB_(MP_(n_val, n_ind));
                    mnhp.push(n_val);
                    while(mnhp.size()>k)mnhp.pop();
                }
            }
            //srt_rem_dup(dp[ranges[ip1_ind].end]);
        }

        //sort temp
        sort(temp.rbegin(),temp.rend());

        //resizing current vector to maximum contraints
        while(temp.size()>300)temp.pop_back();
//        FR_IR(kk,1,i+1){
//            temp.PB_(solid1[kk][i]);
//        }
        //sort rem dup
        temp=srt_rem_dup(temp);
        dp[i]=temp;
//        O_ "after "<<i<<EL
//        prnt(dp);
    }

    FR_IR(i,1,n+1) {
        FR_IR(j, i, n + 1) {
            dp[n].PB_(solid1[i][j]);
        }
    }
    dp[n]=srt_rem_dup(dp[n]);
    sort(dp[n].rbegin(),dp[n].rend());


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

 1
 15 10 32
 617 892 -349 -238 902 -450 -238 238 -432 981 -231 -233 475 453 230
 2 10 -37273
 2 4  928277
 2 7  23737
 14 15 -35738
 12 15 -12934
  7 9  1234
  8 11 -2134
  13 15 9012
  8 14 -4002
  7 13 -3984
  ans: 955297 955118 955074 955066 955064 955059 954895 954887 954885 954844 954843 954841 954836 954833 954828 954826 954822
        954680 954665 954664 954662 954654 954643 954627 954613 954611 954610 954606 954605 954603 954599 954595

 1
 15 10 32
 617 892 -349 -238 902 -450 -238 238 -432 981 -231 -233 475 453 230
 2 10 -273
 2 4  977
 2 7  737
 14 15 -738
 12 15 -934
  7 9  234
  8 11 -134
  13 15 912
  8 14 -402
  7 13 -384
ans: 5401 5352 5170 5163 5121 5114 5114 4997 4962 4948 4932 4930 4920 4916 4902 4883 4883 4876 4784 4774 4766 4764 4759 4735
4731 4731 4725 4724 4724 4724 4717 4715

  1
 4 4 16
 -9 0 23 -7
 1 4 9
 2 4 -6
 2 3 19
 1 3 -4
ans: 42 29 29 25 23 16 14 7 0 0 -7 -7 -9 -9 -16 -16
 */
