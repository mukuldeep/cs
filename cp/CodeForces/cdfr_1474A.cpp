//
// Created by me on 02-04-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll len;
    cin>>len;
    string b;
    cin>>b;
    char a[100005];
    int pre;
    if(b[0]=='0')
        pre=1;
    else
        pre=2;
    a[0]='1';
    for(int i=1;i<len;i++){
        if(b[i]=='0'){
            if(pre==1){
                a[i]='0';
                pre=0;
            }else{
                a[i]='1';
                pre=1;
            }
        }else{
            if(pre==2){
                a[i]='0';
                pre=1;
            }else{
                a[i]='1';
                pre=2;
            }
        }
    }
    a[len]='\0';
    cout<<a<<endl;

}

int main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



