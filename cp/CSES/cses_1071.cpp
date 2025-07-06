//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll y,x,ans=0;
    cin>>y>>x;
    if(y>x){
        if(y&1){
            ans=(y-1)*(y-1)+x;
        }else{
            ans=y*y-x+1;
        }
    }else{
        if(x&1){
            ans=x*x-y+1;
        }else{
            ans=(x-1)*(x-1)+y;
        }
    }
    cout<<ans<<endl;
}

int main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



