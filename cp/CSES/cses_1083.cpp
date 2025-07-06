//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    bool ar[200003]={false};
    ll n,b,i;
    cin>>n;
    for(i=0;i<n-1;i++){
        cin>>b;
        ar[b]=true;
    }
    i=1;
    while(ar[i])
        i++;
    cout<<i<<endl;
}

int cc_main() {
        soln(0);
    return 0;
}



