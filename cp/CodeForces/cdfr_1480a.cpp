//
// Created by me on 28-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll a,b;
    string str;
    cin>>str;
    for(a=0;a<str.size();a++){
        if(a&1){
            if(str[a]=='z')str[a]='y';
            else str[a]='z';
        }else{
            if(str[a]=='a')str[a]='b';
            else str[a]='a';
        }
    }
    cout<<str<<endl;
}

int main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



