//
// Created by me on 20-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,a;
    string str;
    cin>>str;
    ll len=str.length();

    ll no_1_ad=0,no_0_ad=len-1;
    ll f1=1;
    for(ll i=1;i<len;i++){
        no_1_ad=i-1;
        if(str[i]=='1' && str[i-1]=='1'){
            f1=0;
            break;
        }
    }
    if(f1)no_1_ad=len;
    f1=1;

    for(ll i=len-2;i>=0;i--){
        no_0_ad=i+1;
        if(str[i]=='0' && str[i+1]=='0'){
            f1=0;
            break;
        }
    }
    if(f1)no_0_ad=-1;
//cout<<no_0_ad<<" "<<no_1_ad<<endl;
    if(no_0_ad<=no_1_ad){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



