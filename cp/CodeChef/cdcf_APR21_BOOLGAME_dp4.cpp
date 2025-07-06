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
typedef stack<ll> skll;
typedef set<ll> stll;
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
vprll srt_rem_dup(vprll &arr){//replaced by unordered map minimizing time complexity
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
    vll gi(n+1);
    FR_IR(i,0,n) {
        I_ gi[i];
    }
    vector<vprll> ranges_adj(n+2);
    FR_IR(i,0,m){
        I_ a>>b>>c;
        ranges_adj[a].PB_(MP_(i,c));
        ranges_adj[b].PB_(MP_(i,c));
    }

    vector<vprll> dp(n+2);
    dp[0].PB_(MP_(0,0));
    FR_IR(i,1,n+1){
        vprll temp;
        uompll curr_rnge;
        ll curr_val=0,setbits=0;
        temp=dp[i-1];//.insert(temp.end(),dp[i-1].begin(),dp[i-1].end());
        for(ll j=i;j>=1;j--){
            curr_val+=gi[j-1];
            setbits|=(1<<j);
            //considering all ranges inside j to i
            FR_AU(xd,ranges_adj[j]){
                if(curr_rnge.find(xd.first)!=curr_rnge.end()){
                    curr_val+=xd.second;
                }else{
                    curr_rnge[xd.first]=1;
                }
            }
            if(j>1){
                FR_AU(xd,dp[j-2]) {
                    temp.PB_(MP_(xd.first + curr_val, setbits ^ xd.second));
                }
            }else{
                    temp.PB_(MP_(curr_val,setbits));
            }
        }

        //sorting in reverse order
        sort(temp.rbegin(),temp.rend());
        ll n_selected=0;
        uompll selected_index;
        FR_AU(xf,temp){
            if(n_selected>=k)break;
            if(selected_index.find(xf.second)==selected_index.end()) {
                n_selected++;
                dp[i].PB_(xf);
                selected_index[xf.second]=1;
            }
        }
        sort(temp.rbegin(),temp.rend(),srtbysec);
    }
    sort(dp[n].rbegin(),dp[n].rend());
    FR_IR(i,0,k){
        O_ dp[n][i].first<<" ";
    }O_ EL
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
