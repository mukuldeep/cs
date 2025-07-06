//
// Created by me on 17-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,s,d,k;
    cin>>n>>k;
    n=n-k+3;
    if(n%3==0){
        d=n/3;
        cout<<d<<" "<<d<<" "<<d<<" ";
    }else{
        ll cnt2=0;
        while(n%2==0){
            if(n==4)break;
            cnt2++;
            n/=2;

        }
        ll a,b;
        if(n==4){
            b=1;
            a=2;
        }else {
            b = n / 2;
            a = 1;
        }
        if(cnt2) {
            b*=1<<cnt2;
            a*=1<<cnt2;
        }
        cout<<a<<" "<<b<<" "<<b<<" ";

    }
    for(ll i=0;i<k-3;i++){
        cout<<"1 ";
    }
    cout<<endl;

}

int main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



