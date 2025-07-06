/*
 * Created by me on 27-01-2022.
 */
#include <bits/stdc++.h>
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1;  I t;
#define W(n) while(n--)
#define O cout<<
#define I cin>>
#define El endl;
#define ll long long

#define V(x) vector<x>
#define St(x) set<x>
using namespace std;

St(ll) pre_st;
V(ll) pre_arr;
void pre(){
    for(ll i=1;i*i<=1000000000;i++){
        pre_st.insert(i*i);
    }
    for(ll i=1;i*i*i<=1000000000;i++){
        pre_st.insert(i*i*i);
    }
    pre_arr=V(ll) (pre_st.begin(),pre_st.end());
}


void soln(ll t){
    ll n,a;
    I n;
    a=upper_bound(pre_arr.begin(),pre_arr.end(),n)-pre_arr.begin();
    O a<<El
}

int main(){
    Sync
    W(t)
    soln(t);
    return 0;
}
