//
// Created by me on 27-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void soln(ll t){
    ll p,a,b,c,la,lb,lc;
    cin>>p>>a>>b>>c;
    la=(a-p%a)%a;
    lb=(b-p%b)%b;
    lc=(c-p%c)%c;
    la=min(la,lb);
    la=min(la,lc);
    cout<<la<<endl;
}

int main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



