//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void toh(ll n,ll from,ll to, ll ax){
    if(n==1){
        cout<<from<<" "<<to<<endl;
        return;
    }
    toh(n-1,from,ax,to);
    cout<<from<<" "<<to<<endl;
    toh(n-1,ax,to,from);

}

void soln(ll t){
    ll n,nb;
    cin>>n;
    cout<<(1<<n)-1<<endl;
    toh(n,1,3,2);

}

int cc_main() {
    ll t=1;
//    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



