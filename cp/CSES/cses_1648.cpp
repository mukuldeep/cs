//
// Created by me on 21-12-2021.
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
 * simple segment tree implementation for sum queries and point update
 * 1-based indexing for seg_tree
 * 0-based for input array, queries , updates
 */
class segment_tree_sum{
    vector<ll> arr;
    vector<ll> seg_tree;
    ll n;
    //builds the segment tree post order
    void build(ll v,ll l,ll r){
        if(l==r){
            seg_tree[v]=arr[l];
            return;
        }
        ll mid=(l+r)/2;
        build(2*v,l,mid);
        build(2*v+1,mid+1,r);
        seg_tree[v]=seg_tree[2*v]+seg_tree[2*v+1];
    }
    //find sum of elements from l to r 0-based indexing
    ll find_sum_util(ll l,ll r,ll v,ll cl,ll cr){
        //O_ "l:"<<l<<" r:"<<r<<" v:"<<v<<" cl:"<<cl<<" cr:"<<cr<<EL
        if(l>r)return 0;
        if(l==cl && r==cr)return seg_tree[v];
        ll mid=(cl+cr)/2;
        return find_sum_util(l,min(r,mid),2*v,cl,mid)+find_sum_util(max(l,mid+1),r,2*v+1,mid+1,cr);
    }
    //point update seg tree at pos
    void update_util(ll v,ll l,ll r,ll pos,ll val){
        if(l==r)seg_tree[v]=val;
        else{
            ll mid=(l+r)/2;
            if(pos<=mid)
                update_util(v*2,l,mid,pos,val);
            else
                update_util(v*2+1,mid+1,r,pos,val);
            seg_tree[v]=seg_tree[2*v]+seg_tree[2*v+1];
        }
    }
    public:
        //constructor
        segment_tree_sum(vector<ll> arr){
            this->n=arr.size();
            this->arr=arr;
            this->seg_tree=vll(n*4+1);
            build(1,0,n-1);
        }

        //find sum in range
        ll find_sum(ll l,ll r){
            return find_sum_util(l,r,1,0,n-1);
        }

        //point update to arr and seg tree
        void update(ll pos, ll val){
            arr[pos]=val;
            update_util(1,0,n-1,pos,val);
        }

        //print array
        /*void print_arr(){
            for(ll i=0;i<arr.size();i++){
                O_ i<<":"<<arr[i]<<" ";
            }O_ EL
        }
        //print seg tree
        void print_seg_tree(){
            for(ll i=0;i<seg_tree.size();i++){
                O_ i<<":"<<seg_tree[i]<<" ";
            }O_ EL
        }
         */

};



void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m;
    vll arr(n);
    FR_IR(i,0,n){
        I_ arr[i];
    }
    segment_tree_sum sg(arr);
    FR_IR(i,0,m){
        I_ k>>a>>b;
        if(k==1){
            sg.update(a-1,b);
        }else{
            O_ sg.find_sum(a-1,b-1)<<EL
        }
    }
}

DRIVER
