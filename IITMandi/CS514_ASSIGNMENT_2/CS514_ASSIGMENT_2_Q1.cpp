/*
 * Created by mukul on 01-10-2024.
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

// Recursive function to find the kth element in two sorted arrays
//int rec_i_th(V(ll)& arr1, V(ll)& arr2, int p1, int p2, int k)
//{
//    // If the first array is exhausted, return the i-th element from the second array
//    if(arr1.size() == p1)
//        return arr2[k];
//
//    // If the second array is exhausted, return the i-th element from the first array
//    if(arr2.size() == p2)
//        return arr1[k];
//
//    // Calculate midpoints for both arrays
//    int mid1 = p1 / 2;
//    int mid2 = p2 / 2;
//
//    if(mid1 + mid2 < k) {
//        // If the value at mid1 in the first array is greater, discard the left part of the second array
//        if(arr1[mid1] > arr2[mid2])
//            return rec_i_th(arr1, arr2+p2+1, p1, p2, k - mid2 - 1);
//            // Otherwise, discard the left part of the first array
//        else
//            return rec_i_th(arr1, arr2, p1, p2,
//                       k - mid1 - 1);
//    }
//    else {
//        // If the value at mid1 in the first array is greater, discard the right part of the first array
//        if(arr1[mid1] > arr2[mid2])
//            return rec_i_th(arr1, arr2, mid1 , p2, k);
//            // Otherwise, discard the right part of the second array
//        else
//            return rec_i_th(arr1, arr2, p1,  mid2, k);
//    }
//}


// Recursive function to find the k-th element in two sorted vectors
int i_th(vector<ll>& vec1, vector<ll>& vec2, int start1, int start2, int i) {
    // If the first vector is exhausted, return the k-th element from the second vector
    if(start1 >= vec1.size())
        return vec2[start2 + i];

    // If the second vector is exhausted, return the k-th element from the first vector
    if(start2 >= vec2.size())
        return vec1[start1 + i];

    // If k is 0, return the smaller of the current elements
    if(i == 0)
        return min(vec1[start1], vec2[start2]);

    // Calculate midpoints for both vectors
    int mid1 =(start1 + i / 2 < vec1.size()) ? vec1[start1 + i / 2] : INT_MAX;
    int mid2 =(start2 + i / 2 < vec2.size()) ? vec2[start2 + i / 2] : INT_MAX;

    // Discard half of one vector based on the comparison of midpoints
    if(mid1 < mid2) {
        return i_th(vec1, vec2, start1 + i / 2 + 1, start2, i - i / 2 - 1);
    } else {
        return i_th(vec1, vec2, start1, start2 + i / 2 + 1, i - i / 2 - 1);
    }
}

/**
 * find median element in two sorted arrays
 * where median m=(a+b)/2
 * a,b are size of the two arrays
 */

int medianElement(vector<ll> arr1, vector<ll> arr2)
{
    int a = arr1.size();
    int b = arr2.size();
    int m =(a+b)/2;
    if(a==0 && b==0){
        return -1;
    }
    if(a==0){
        return arr2[m];
    }
    if(b==0)
    {
        return arr1[m];
    }

    return i_th(arr1, arr2, 0, 0, m - 1);
    //return kth(arr1, arr2, arr1, arr2, m-1);
}


void soln(ll t){

    V(ll) arr1 = {1,5,7,12,23,26,28,30,34,36,39,41,49,51,52,55,59,60,61,89,99};
    V(ll) arr2 = {1,3,6,9,11,15,18,20,30,36,38,42,45,48,52,54,57,59,70,78,79,93,96};

    V(ll) arr3 = {0,4};
    V(ll) arr4 = {};
    O medianElement(arr1,arr2);


}

Dr


/**
 * Problem statement
 * Given two sorted arrays of size a and b find the element whose is (a+b)/2
 * using an algorithm which does O(lg a + lg b) queries
 */


/**
 *  HOW TO RUN
 *  1. Consider soln() as main function for the program
 *  change iff any changes in test cases are required
 *
 */
