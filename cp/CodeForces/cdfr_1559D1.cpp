//
// Created by me on 15-08-2021.
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
 * Disjoint set union by height with path compression
 * #### position is 0 to n ###
 */
class disjoint_set_ubheight_pc{
        vll parent;
        vll height;
        ll n;
    public:
    /*
     * constructor
     */
    disjoint_set_ubheight_pc(ll n){
        this->n=n;
        parent=vll(n);
        height=vll(n,1);
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
     * union by height
     */
    void union_bheight(ll a,ll b){
        a=find_set(a);
        b=find_set(b);
        if(a!=b){
            if(height[a]<height[b])
                swap(a,b);
            parent[b]=a;
            if(height[a]==height[b])
                height[a]++;
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
    ll m1,m2,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m1>>m2;
    disjoint_set_ubheight_pc dsu1(n),dsu2(n);

    FR_IR(i,0,m1){
        I_ a>>b;
        dsu1.union_bheight(a-1,b-1);
    }
    FR_IR(i,0,m2){
        I_ a>>b;
        dsu2.union_bheight(a-1,b-1);
    }
    vprll an;
    FR_IR(i,0,n){
        FR_IR(j,i+1,n){
            if(!dsu1.is_same_set(i,j) && !dsu2.is_same_set(i,j)){
                an.push_back({i+1,j+1});
                dsu1.union_bheight(i,j);
                dsu2.union_bheight(i,j);
            }
        }
    }

    O_ an.size()<<EL
    FR_AU(xd,an){
        O_ xd.first<<" "<<xd.second<<EL
    }
}

DRIVER
