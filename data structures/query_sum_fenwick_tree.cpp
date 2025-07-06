//
// Created by me on 12-07-2021.
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

class fenwick_tree{
    ll n=0;
    vector<ll> arr;
    public:
    fenwick_tree(ll n){
        this->n=n;
        arr=vector<ll> (n+1,0);
    }
    ll lsb_num(ll n) {
        return n&-n;
    }
    ll get_prefix_sum(ll x){
        if(x>n)return get_prefix_sum(n);
        if(x<1)return 0;
        ll ans=0;
        while(x){
            ans+=arr[x];
            x^=lsb_num(x);
        }
        return ans;
    }
    ll get_range_sum(ll l,ll r){
        return get_prefix_sum(r)-get_prefix_sum(l-1);
    }
    void point_update(ll pos,ll val){
        if(pos>n || pos<1)return;//not updating invalid ranges
        while(pos<=n){
            arr[pos]+=val;
            pos+=lsb_num(pos);
        }
    }

};

void soln(ll t){
    ll m,n,o,p,q,k,a,b,c,d,e,f=0,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>q;
    vll arr(n);
    fenwick_tree ft=fenwick_tree(n);
    FR_IR(i,0,n){
        I_ arr[i];
        ft.point_update(i+1,arr[i]);
    }
    FR_IR(i,0,q){
        I_ a>>b>>c;
        if(a==1){//point update
            ft.point_update(b,c);
            arr[b-1]+=c;
        }else{//query
            O_ "prefix sum "<<b<<": "<<ft.get_prefix_sum(b)<<EL
            O_ "prefix sum "<<c<<": "<<ft.get_prefix_sum(c)<<EL
            O_ "range sum("<<b<<","<<c<<"):"<<ft.get_range_sum(b,c)<<EL
        }
        FR_AU(xd,arr){
            O_ xd<<" ";
        }O_ EL
    }

}

TEST_DRIVER
/*
 1
 10 5
 1 2 3 4 5 6 7 8 9 11
 1 3 4
 2 3 5
 1 7 10
 2 2 8
 2 1 10

 ans:

 */