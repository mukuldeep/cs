//
// Created by me on 25-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void soln(ll t){
    ll n,m,x;
    cin>>n>>m>>x;
    ll a_r=x%n;
    if(a_r==0)a_r=n;
    ll a_c=ceil((ld)x/(ld)n);
    ll num=(a_r-1)*m+a_c;

    cout<<num<<endl;

}

int main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



