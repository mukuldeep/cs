/*
 * Created by me on 28-12-2021.
 */
#include <bits/stdc++.h>
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1; // I t;
#define Dr int main(){Sync W(t)soln(t);return 0;}
#define Drt int cc_main(){Sync W(t)soln(t);return 0;}
#define F(a,c) for (ll a=0;a<c; a++)
#define Fe(a,c) for(ll a=0;a<=c; a++)
#define Fi(i,s,e) for(ll i=s;i<e;i++)
#define Rfi(i,s,e) for(ll i=s;i>e;i--)
#define Fa(xx,xxs) for(auto xx:xxs)
#define Srt(x) sort(x.begin(),x.end());
#define Rsrt(x) sort(x.rbegin(),x.rend());
#define Rev(x) reverse(x.begin(),x.end());
#define W(n) while(n--)
#define Wh while
#define Il while(1)
#define Pb push_back
#define O cout<<
#define Prcn fixed<<setprecision(20)
#define I cin>>
#define El endl;
//ds
#define ll long long
#define ld long double
#define S string
#define Ch char
#define V(x) vector<x>
#define Vv(x) V(V(x))
#define Sk(x) stack<x>
#define St(x) set<x>
#define Q(x) queue<x>
#define Dq(x) deque<x>
#define P(x) pair<x,x>
#define P2(x,y) pair<x,y>
#define Mp(x,y) map<x,y>
#define Uom(x,y) unordered_map<x,y>

//functions
#define p_bin(x) if(x)O "YES"<<El else O "NO"<<El

//constants
#define t9p7 1000000007
#define INF 100000000000000000 //1e17
using namespace std;

void pre(){

}

/*
 * simple segment tree implementation for sum queries and point update
 * 1-based indexing for seg_tree
 * 0-based for input array, queries , updates
 */
class segment_tree_r_u_p_q{
    vector<ll> arr;
    vector<ll> seg_tree;
    ll n;
    //builds the segment tree
    void build(ll v,ll l,ll r){
        if(l==r){
            seg_tree[v]=arr[l];
            return;
        }
        ll mid=(l+r)/2;
        build(2*v,l,mid);
        build(2*v+1,mid+1,r);
        seg_tree[v]=0;
    }
    //find value of single element at pos
    ll find_at_util(ll v,ll l,ll r,ll pos){
        //O v<<" l:"<<l<<" r:"<<r<<" pos:"<<pos<<El
        if(l==r)
            return seg_tree[v];
        ll mid=(l+r)/2;
        if(pos<=mid)
            return seg_tree[v]+find_at_util(v*2,l,mid,pos);
        else
            return seg_tree[v]+find_at_util(v*2+1,mid+1,r,pos);
    }
    //range update seg tree at pos_l to pos_r
    void update_util(ll v,ll l,ll r,ll pos_l,ll pos_r,ll val){
        //O v<<" l:"<<l<<" r:"<<r<<" pos:"<<pos_l<<","<<pos_r<<" val:"<<val<<El
        if(pos_l>pos_r)return;
        if(l==pos_l && r==pos_r)
            seg_tree[v]+=val;
        else{
            ll mid=(r+l)/2;
            update_util(v*2,l,mid,pos_l,min(pos_r,mid),val);
            update_util(v*2+1,mid+1,r,max(pos_l,mid+1),pos_r,val);
        }
    }
    public:
        //constructor
        segment_tree_r_u_p_q(vector<ll> arr){
            this->n=arr.size();
            this->arr=arr;
            this->seg_tree=V(ll)(n*4+1);
            build(1,0,n-1);
        }

        //find sum in range
        ll find_at(ll pos){
            return find_at_util(1,0,n-1,pos);
        }

        //range update seg tree
        void update(ll pos_l,ll pos_r, ll val){
            update_util(1,0,n-1,pos_l,pos_r,val);
        }

        void show_tree(){
            Fa(xx,seg_tree){
                O xx<<" ";
            }O El
        }
};

void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    I n>>m;
    V(ll) arr(n);
    F(i,n){
        I arr[i];
    }
    segment_tree_r_u_p_q sg(arr);
    //sg.show_tree();
    F(i,m){
        I a;
        if(a==1){
            I b>>c>>u;
            sg.update(b-1,c-1,u);
        }else{
            I b;
            ans=sg.find_at(b-1);
            O ans<<El
        }
    }
}

Dr
