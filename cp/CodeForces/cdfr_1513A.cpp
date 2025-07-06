//
// Created by me on 11-04-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void soln(ll t){
    ll n,k;
    cin>>n>>k;
    ll mx_peak=(n-1)/2;

    if(k<=mx_peak){
        ll peak_strt=n-k+1;
        ll v_s=peak_strt-1;
        while(v_s>0 || peak_strt<=n){
            cout<<v_s<<" ";
            v_s--;
            if(peak_strt<=n){
                cout<<peak_strt<<" ";
                peak_strt++;
            }
        }
        cout<<endl;

    }else{
        cout<<-1<<endl;
    }
}

int main(){
    ll t=1;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}
