//
// Created by me on 24-07-2021.
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
 * Disjoint set union by size with path compression
 * #### position is 0 to n ###
 */
class disjoint_set_ubsize_pc{
        vll parent;
        vll size;
        ll n;
    public:
    /*
     * constructor
     */
    disjoint_set_ubsize_pc(ll n){
        this->n=n;
        parent=vll(n);
        size=vll(n,1);
        FR_IR(i,0,n){
            parent[i]=i;
        }
    }
    /*
     * find parent or representative of the set where a belongs to
     * with path compression
     */
    ll find_set(ll a){
        if(parent[a]==a)
            return a;
        return parent[a]=find_set(parent[a]);
    }
    /*
     * union by size
     */
    void union_bsize(ll a,ll b){
        a=find_set(a);
        b=find_set(b);
        if(a!=b){
            if(size[a]<size[b])
                swap(a,b);
            parent[b]=a;
            size[a]+=size[b];
        }
    }
    /*
     * whether a and b belongs to same set or not
     */
    bool is_same_set(ll a, ll b){
        a=find_set(a);
        b=find_set(b);
        if(a==b)return true;
        return false;
    }
    ll set_size(ll a){
        a=find_set(a);
        return size[a];
    }
    /*
     * no of disjoint set
     */
    ll no_of_disjoint_set(){
        ll cnt=0;
        FR_IR(i,0,n){
            if(parent[i]==i)cnt++;
        }
        return cnt;
    }
    /*
     * prints all the sets
     * can be little faster
     */
    void print_sets(){
        map<ll,vll> mp;
        FR_IR(i,0,n){
            find_set(i);
            mp[parent[i]].push_back(i);
        }

        FR_AU(xd,mp){
            O_ "set "<<xd.first<<": ";
            FR_AU(xxd,xd.second)O_ xxd<<" ";O_ EL
        }
    }
};


void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m;
    disjoint_set_ubsize_pc ds(n);

    FR_IR(i,0,m){
        I_ k;
        vll arr(k);
        FR_IR(j,0,k)
            I_ arr[j];
        if(k>1){
            FR_IR(j,1,k){
                ds.union_bsize(arr[j]-1,arr[j-1]-1);
            }
        }
    }
    FR_IR(i,0,n){
        O_ ds.set_size(i)<<" ";
    }O_ EL

}
DRIVER
