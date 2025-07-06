//
// Created by me on 27-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void soln(ll t){
    ll n,a,d,add=0,b;
    cin>>a>>b;
    if(b==1){add++;b=2;}

    ll pre=LONG_LONG_MAX;
    while(1){
        ll now=add,temp_b=b,temp_a=a,mlt=0;
        while(temp_a){
            temp_a/=temp_b;
            mlt++;
        }
        now+=mlt;
        if(now<=pre){
            pre=now;
        }else
            break;
        add++;b++;
    }
    cout<<pre<<endl;
}

int main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



