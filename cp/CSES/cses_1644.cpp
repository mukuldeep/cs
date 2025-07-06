/*
 * Created by me on 14-01-2022.
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
 * simple segment tree implementation for min queries and point update
 * 1-based indexing for seg_tree
 * 0-based for input array, queries , updates
 */
class segment_tree_min{
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
        seg_tree[v]=min(seg_tree[2*v],seg_tree[2*v+1]);
    }
    //find min of elements from l to r 0-based indexing
    ll find_min_util(ll l,ll r,ll v,ll cl,ll cr){
        //O_ "l:"<<l<<" r:"<<r<<" v:"<<v<<" cl:"<<cl<<" cr:"<<cr<<EL
        if(l>r)return LONG_LONG_MAX;
        if(l==cl && r==cr)return seg_tree[v];
        ll mid=(cl+cr)/2;
        return min(find_min_util(l,min(r,mid),2*v,cl,mid),find_min_util(max(l,mid+1),r,2*v+1,mid+1,cr));
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
            seg_tree[v]=min(seg_tree[2*v],seg_tree[2*v+1]);
        }
    }
    public:
        //constructor
        segment_tree_min(vector<ll> arr){
            this->n=arr.size();
            this->arr=arr;
            this->seg_tree=V(ll)(n*4+1);
            build(1,0,n-1);
        }

        //find min in range
        ll find_min(ll l,ll r){
            return find_min_util(l,r,1,0,n-1);
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
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    I n>>a>>b;
    V(ll) arr(n),sm(n);
    F(i,n){
        I arr[i];
        sm[i]=arr[i];
        if(i!=0){
            sm[i]+=sm[i-1];
        }
    }
    segment_tree_min st(sm);
    mx=sm[a-1];
    Fi(i,a,n){
        ll min_s=max(0LL,i-b);
        ll min_e=i-a;
        ll min_sm_in_range=st.find_min(min_s,min_e);
        if(i-b<0)min_sm_in_range=min(min_sm_in_range,0LL);
        //O "range:"<<min_s<<" "<<min_e<<" =>"<<min_sm_in_range<<" sm:"<<sm[i]<<El
        mx=max(mx,sm[i]-min_sm_in_range);

    }
    O mx<<El

}

Dr
