//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll pre[20]={0},pre10[20];
void preprocess(){
    //preprocess
    pre[1]=9;
    pre10[1]=1;
    ll n_in_n_digit=9;
    for(ll i=2;i<18;i++){
        n_in_n_digit*=10;
        pre10[i]=pre10[i-1]*10;
        pre[i]=pre[i-1]+n_in_n_digit*i;
        //cout<<pre[i]<<endl;
    }
    //pre ends
}
void soln(ll t){
    ll k;
    cin>>k;
    ll digit;
    for(digit=17;pre[digit]>=k;digit--);
    digit++;
    ll nth=k-pre[digit-1];
    ll nthd=nth%digit;
    if(nthd==0) {
        nth /= digit;
    }else{
        nth/=digit;
        nth++;
        nthd=digit-nthd;
    }
    ll number=pre10[digit]+nth-1;
    //cout<<number<<endl;
    for(ll cc=0;cc<nthd;cc++){
        number/=10;
    }

    cout<<number%10<<endl;




}

int main() {
    preprocess();
    ll t=1;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



