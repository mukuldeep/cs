//
// Created by me on 25-07-2021.
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

bool rec(vll &arr,ll n, ll curr,ll curr_sum, ll ele_pos){
    if(curr==n){
        if(curr_sum==arr[ele_pos])return true;
        else return false;
    }
    bool ans=false;
    if(curr!=ele_pos){
        ans|=rec(arr,n,curr+1,curr_sum+arr[curr],ele_pos);
    }
    ans|=rec(arr,n,curr+1,curr_sum,ele_pos);
    return ans;
}
void rec2(vll &arr,uompll &allsm,ll n, ll curr,ll curr_sum){
    if(curr==n){
        allsm[curr_sum]++;
        return;
        //if(allsm[curr_sum]==1)return true;
        //else return false;
    }
    bool ans=false;
    //ans|=
            rec2(arr,allsm,n,curr+1,curr_sum+arr[curr]);
    //if(!ans)ans|=
            rec2(arr,allsm,n,curr+1,curr_sum);
    //return ans;
}

void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n;
    vll arr(n);
    uompll mp,dmp;
    uompll sm;
    FR_IR(i,0,n){
        I_ arr[i];
        arr[i]=abs(arr[i]);
        if(arr[i]==0 || mp[arr[i]]==1){
            ans=1;
        }
        mp[arr[i]]=1;
        //sm[2*arr[i]]=1;
    }
    if(ans){
        O_ "YES"<<EL
        return;
    }
    if(n<3){
        O_ "NO"<<EL
        return;
    }
    //bool an=false;

    bool res2=false;
            rec2(arr,sm,n,0,0);
            FR_AU(xd,sm){
                if(xd.second>1){
                    //O_ xd.first<<" "<<xd.second<<EL
                    res2=1;
                    break;
                }
            }
    //FR_IR(i,0,n){
//        FR_IR(j,i+1,n){
//            ll df=abs(arr[i]-arr[j]);
//            if(mp[df]==1){
//                ans=1;
//                break;
//            }
//            mp[df]=1;
//        }
        //an|=rec(arr,n,0,0,i);
    //}
    if(res2)O_ "YES"<<EL
    else O_ "NO"<<EL
}

DRIVER
