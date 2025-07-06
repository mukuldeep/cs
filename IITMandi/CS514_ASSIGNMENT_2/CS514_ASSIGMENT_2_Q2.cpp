/*
 * Created by mukul on 01-10-2024.
 */
#include <bits/stdc++.h>
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1; // I t;
#define Dr int main(){Sync W(t)soln(t);return 0;}
#define Drt int cc_main(){Sync W(t)soln(t);return 0;}
#define F(a,c) for(ll a=0;a<c; a++)
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
// Function to select the k-th smallest element in the vector
int select(vector<int>& vec, int left, int right, int k);

void pre(){

}

// Function to find the median of a small group of 9 elements
int findMedian(vector<int>& vec, int left, int size){
    sort(vec.begin() + left, vec.begin() + left + size);
    return vec[left + size / 2];  // Return the middle element
}

// Partition function for quickselect
int partition(vector<int>& vec, int left, int right, int pivot){
    int pivotValue = vec[pivot];
    swap(vec[pivot], vec[right]);  // Move pivot to the end
    int storeIndex = left;

    for(int i = left; i < right; i++){
        if(vec[i] < pivotValue){
            swap(vec[i], vec[storeIndex]);
            storeIndex++;
        }
    }
    swap(vec[storeIndex], vec[right]);  // Move pivot to its final place
    return storeIndex;
}

// Function to find the median of medians
int medianOfMedians(vector<int>& vec, int left, int right){
    // If the list is small(<=9), simply sort and return the median
    if(right - left + 1 <= 9){
        return findMedian(vec, left, right - left + 1);
    }

    // Otherwise, divide the list into groups of 9
    vector<int> medians;
    for(int i = left; i <= right; i += 9){
        int groupSize = min(9, right - i + 1);
        medians.push_back(findMedian(vec, i, groupSize));
    }

    // Recursively find the median of the medians
    return select(medians, 0, medians.size() - 1, medians.size() / 2);
}

// Quickselect function to find the k-th smallest element
int select(vector<int>& vec, int left, int right, int k){
    // Base case: if the array contains only one element
    if(left == right){
        return vec[left];
    }

    // Use the median of medians as the pivot
    int pivot = medianOfMedians(vec, left, right);

    // Partition the array around the pivot and get its final position
    int pivotIndex = partition(vec, left, right, pivot);

    // The pivot is in its final sorted position
    if(k == pivotIndex){
        return vec[k];
    }else if(k < pivotIndex){
        return select(vec, left, pivotIndex - 1, k);
    }else{
        return select(vec, pivotIndex + 1, right, k);
    }
}

// Helper function to start the selection process
int kthSmallest(vector<int>& vec, int k){
    return select(vec, 0, vec.size() - 1, k);
}

void soln(ll t){
    vector<int> vec ={12, 3, 5, 7, 19, 26, 17, 9, 23, 18, 4, 1, 6, 11, 15, 2, 8, 21, 20, 22};
    int k = 5;  // Find the 5th smallest element
    cout << "The " << k << "-th smallest element is " << kthSmallest(vec, k - 1) << endl;


}

Dr


/**
 * Problem statement
 *
 */


/**
 *  HOW TO RUN
 *  1. Consider soln() as main function for the program
 *  change iff any changes in test cases are required
 *
 */
