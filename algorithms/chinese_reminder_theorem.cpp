//
// Created by me on 31-03-2021.
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

/*
 *  ans%num[0]=rem[0]
 *  ans%num[1]=rem[1]
 *  ans%num[2]=rem[2]
 *
 *  ans=(ans1) + (ans2*num[0]) + (ans3*num[0][num[1].......... ans(i)num[0...i-1]) % m
 *                  ans+asn(i)*num[0]..num[i-1]=rem[i]  % num[i]
 *                  ans(i)=(rem[i]-ans)/(num[0]..num[i-1])
 *                  ans(i)num[0...i-1]=ans(i)*num[0...i-1]
 *                                     (rem[i]-ans)/(num[0]..num[i-1])*num[0...i-1]
 *                                     storing this into: mulfact=(num[0]..num[i-1])*num[0...i-1]
 *
 *
 */

ll mod_inv(ll a,ll m)
{
    ll m0 = m;
    ll y=0,x=1;
    if (m==1)
        return 0;
    while (a>1) {
        ll q=a/m;
        ll t=m;
        m=a%m,a=t;
        t=y;
        y=x-q*y;
        x=t;
    }
    if(x<0)
        x+=m0;
    return x;
}

ll ch_rem_th(vprll x){
    ll n=x.size();
    //m is num[0]*num[1]*num[2]*num[3].....num[n]
    ll m=1;
    for(auto o:x){
        m*=o.first;
    }

    ll ans=0;
    for(ll i=0;i<n;i++){
        ll mul_fact=1;
        for(ll j=0;j<i;j++){
            mul_fact*=x[j].first;
            mul_fact*=mod_inv(x[j].first,x[i].first);
            mul_fact%=m;
        }
        ans+=(mul_fact*(x[i].second+m-ans))%m;
        ans%=m;
    }
    return ans;
}



// k is size of num[] and rem[]. Returns the smallest
// number x such that:
// x % num[0] = rem[0],
// x % num[1] = rem[1],
// ..................
// x % num[k-2] = rem[k-1]
// Assumption: Numbers in num[] are pairwise coprime
// (gcd for every pair is 1)
ll ch_rem_th_nlogn(vprll arr)
{
    ll k=arr.size();
    //without mod
    ll m = 1;
    for (ll i = 0; i < k; i++)
        m *= arr[i].first;

    ll ans = 0;

    // Apply formula
    for (ll i = 0; i < k; i++) {
        ll pp = m / arr[i].first;
        ans += arr[i].second * mod_inv(pp, arr[i].first) * pp;
    }
    return ans % m;
}

void soln(ll t){
    ll n,k,a,b,c;
    I_ n;
    vprll arr;
    FR_IR(i,0,n){
        I_ a>>b;
        arr.PB_(MP_(a,b));
    }
    cout<<ch_rem_th(arr)<<endl;
    cout<<ch_rem_th_nlogn(arr)<<endl;

}

TEST_DRIVER


/*

1
3
5 3
7 2
8 1


233

 */