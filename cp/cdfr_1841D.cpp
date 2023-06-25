/*
 * Created by me on 25-06-2023.
 */
#include <bits/stdc++.h>
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1;  I t;
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

// comperison function for sorting vector of pair by second element
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    if(a.second == b.second)
        return (a.first < b.first);
    return (a.second < b.second);
}

// check if two interval intersect
bool is_intersect(ll ax,ll ay,ll bx,ll by){
    return (ax <= bx && bx <= ay) || (ax <= by && by <= ay) || (bx <= ax && ax <= by) || (bx <= ay && ay <= by);
}

void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    I n;
    V(P(ll)) arr(n);
    F(i,n){
        I arr[i].first>>arr[i].second;
    }

    // sorting the array of pairs in non-descending order by second elements
    sort(arr.begin(),arr.end(),sortbysec);

    ll last_ptr=0, // last segment index
    last_pair_ptr=-1, // last pair segment index
    paired=0; // paired or not. 0 -> waiting for pair, 1 -> paired

    // Iterating Over sorted segments starting from 2nd segment
    Fi(i,1,n){
        if(is_intersect(arr[last_ptr].first,arr[last_ptr].second,arr[i].first,arr[i].second)){
            //intersecting with last_segment

            if(paired) {
            // already paired. So, deleting

                cnt++;
            }else{
            //not paired

                if(last_pair_ptr == -1){
                // for first pair

                    last_pair_ptr=i;
                    last_ptr=i;
                    paired=1;
                }else if(is_intersect(arr[last_pair_ptr].first,arr[last_pair_ptr].second,arr[i].first,arr[i].second)){ //check if intersect with prev pair
                // Intersecting with last paired segment

                    cnt++;
                }else{
                // Not intersecting with last paired segment 
                    paired=1;
                    last_ptr=last_pair_ptr=i;
                }

            }
        }else{
        // Not intersecting with last segment
           if(!paired){
            // Not paired, so deleting the last segment 

              cnt++;
           }
        // Starting a new pair 
            last_ptr=i;
            paired=0;
        }
    }

    // If one unpaired element left
    if(!paired)
        cnt++;

    O cnt<<El
}

Dr
