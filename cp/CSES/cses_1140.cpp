//
// Created by me on 06-07-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){SYNC ll t=1;W_(t)soln(t);return 0;}
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

/*
 * Max profit Weighted jobs Scheduling
 * takes jobs vector returns max profit
 */

struct job{
    ll suru;
    ll ses;
    ll luv;
};

bool sort_by_ses(job j1, job j2)
{
    return j1.ses == j2.ses?(j1.luv<j2.luv):(j1.ses < j2.ses);
}
ll b_src_jobs(vector<job> &jobs,ll index)//binary search : previous valid job
{
    ll lo = 0, hi = index - 1;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (jobs[mid].ses < jobs[index].suru)//non overlapping on a day <=for overlapping
        {
            if (jobs[mid + 1].ses <jobs[index].suru)lo = mid + 1;//non overlapping on a day <=for overlapping
            else return mid;
        }
        else hi = mid - 1;
    }

    return -1;
}
/*
 * maximum profit from weighted jobs
 */
ll find_maximum_luv(vector<job> &jobs,ll n){
    sort(jobs.begin(), jobs.end(), sort_by_ses);
    vll dp(n);
    dp[0] = jobs[0].luv;
    for (ll i=1; i<n; i++)
    {
        ll inclProf = jobs[i].luv;
        ll l = b_src_jobs(jobs,i);
        //O_ i<<" "<<l<<EL
        if (l!=-1)inclProf += dp[l];
        dp[i] = max(inclProf, dp[i-1]);
    }
    ll result = dp[n-1];

//    FR_AU(xd,jobs){
//        O_ xd.suru<<" "<<xd.ses<<" "<<xd.luv<<EL
//    }
//    FR_AU(xd,dp){
//        O_ xd<<" ";
//    }
    return result;
}


void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    I_ n;
    vector<job> jobs;
    FR_IR(i,0,n){
        I_ a>>b>>m;
        jobs.push_back({a,b,m});
    }
    O_ find_maximum_luv(jobs,n)<<EL
}

DRIVER
