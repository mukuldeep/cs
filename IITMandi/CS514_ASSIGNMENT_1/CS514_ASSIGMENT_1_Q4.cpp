/*
 * Created by mukul on 03-09-2024.
 */
#include <bits/stdc++.h>
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1;  //I t;
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

void print_arr(V(ll) arr){
    Fa(xx,arr){
        O xx<<" ";
    }O El
}

void k_sort(ll n, ll k, V(ll)& arr){
    if(k==0){
        return;
    }

    if(k<n){
        //sorting first k elements with quicksort (inbuilt function)
        sort(arr.begin(),arr.begin()+k);
        O "after "<<1<<" elemements sorted:";
        print_arr(arr);

        //now iterating through elements other than first k
        for(ll i=k;i<n;i++){
            //apply selection sort on (i-k to i)th elements
            for(ll j=i-1;j>(i-k);j--){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }else{
                    break;
                }
            }
            O "after "<<i-k+2<<" elemements sorted:";
            print_arr(arr);

        }


    }else{
        Srt(arr);
    }
}

void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
//    I n>>k;
//    V(ll) arr(n);
//    F(i,n){
//        I arr[i];
//    }

    n = 15;
    k = 4;
    V(ll) arr = {   34, 35, 9,  7,  23, 67, 45, 89, 108,58, 190,    314,    140,    423,    214};
    //sorted        7   9   23  34  35  45  58  67  89  108 140     190     214     314     423

    k_sort(n,k,arr);

    O "\nSORTED ARRAY:";
    print_arr(arr);

}

Dr


/**
 *  HOW TO RUN
 *  1. Consider soln() as main function for the program
 *  change iff any changes in test cases are required
 *
 */


/**
 * Problem statement
 *  An input is considered k-sorted, if each element is at most k locations
 *  away from its correct location in the sorted order. Given an input array A
 *  and an integer k, which denotes that the input is already k-sorted design
 *  an algorithm which sorts the input in the best possible time.
 *
 */