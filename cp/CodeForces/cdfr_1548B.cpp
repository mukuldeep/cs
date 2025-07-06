//
// Created by me on 08-08-2021.
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


/*
 * sparse table for gcd query
 * 0-indexed
 */
class sparse_table_class_gcd{
    vvll sparse_table;
    ll n,k;
    map<pair<ll,ll>,ll> mp;

    /*
     * calculate sparse table
     */
    void calc_sparse_table(){
        FR_IR(j,1,k+1)
            for (ll i=0;i+(1<<j)<= n; i++)
                sparse_table[i][j] = __gcd(sparse_table[i][j-1],sparse_table[i + (1 << (j - 1))][j - 1]);
    }

    void print_spt(){
        FR_AU(xd,sparse_table){
            FR_AU(xxd,xd){
                O_ xxd<<" ";
            }O_ EL
        }
    }

public:
    sparse_table_class_gcd(){
    }
    sparse_table_class_gcd(ll n){
        this->n=n;
        k=ceil(log2(n));
        sparse_table=vvll(n+1,vll(k+1));
        input_array();
    }
    void input_array(){
        FR_IR(i,0,n){
            I_ sparse_table[i][0];
        }
        calc_sparse_table();
    }
    sparse_table_class_gcd(vll arr){
        n=arr.size();
        k=ceil(log2(n));
        sparse_table=vvll(n+1,vll(k+1));
        FR_IR(i,0,n)sparse_table[i][0]=arr[i];
        calc_sparse_table();
        //O_ "sparse table calculated"<<EL
        //print_spt();
    }

    ll find_gcd(ll left,ll right){

        ll gcd = 1;
        ll flag=1;
        for (ll j=k;j>=0;j--) {
            if((1<< j) <= right-left + 1) {
                if(flag){
                    gcd=sparse_table[left][j];
                    flag=0;
                }else{
                    gcd=__gcd(gcd,sparse_table[left][j]);
                }
                left+= (1 << j);
            }
        }
        return gcd;
    }



    ll binary_search(ll from_ind,ll strt,ll end,ll mx_till_now){
            //O_ "fromind:"<<from_ind<<" strt:"<<strt<<" end:"<<end<<" mxtillnow:"<<mx_till_now<<EL
            if(end-from_ind+1<mx_till_now)return mx_till_now;
            if(strt==end) return end-from_ind+1;
            if(end-strt==1){
                ll ans=find_gcd(from_ind,end);
                if(ans!=1)return end-from_ind+1;
                return end-from_ind;
            }
            ll mid=(strt+end)/2;
            ll mid_ans=find_gcd(from_ind,mid);
            //O_ mid_ans<<EL
            if(mid_ans==1){
                return binary_search(from_ind,strt,mid-1,mx_till_now);
            }else{
                return binary_search(from_ind,mid,end,mx_till_now);
            }
    }
    /*
     * returns maximum size of GCD not equals 1
     */
    ll max_subarray_size_gcd_not_equals_one(){
        ll mx=0;
        FR_IR(i,0,n){
            //O_ "i="<<i<<" ";cout.flush();
            ll temp;
            if(find_gcd(i,i)==1)temp=0;
            else temp=binary_search(i,i,n-1,mx);
            //O_ "temp="<<temp<<EL
            mx=max(mx,temp);
        }
        return mx;
    }

};


void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n;
    vll arr(n-1),brr(n);
    FR_IR(i,0,n){
        I_ brr[i];
    }
    FR_IR(i,1,n){
        arr[i-1]=abs(brr[i]-brr[i-1]);
    }

    sparse_table_class_gcd spt(arr);
    ans=spt.max_subarray_size_gcd_not_equals_one();
    O_ ans+1<<EL

}
DRIVER
