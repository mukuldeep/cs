//
// Created by me on 27-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
ll isbalance(string str){
    ll cnt=0;
    for(auto ch:str){
        if(ch=='(')cnt++;
        else cnt--;
        if(cnt<0) return 0;
    }
    if(cnt)return 0;
    return 1;
}
string replaceall(string str,char ch,char rch,char ch2,char rch2,char ch3,char rch3){
    for(ll i=0;i<str.size();i++){
        if(str[i]==ch)str[i]=rch;
        if(str[i]==ch2)str[i]=rch2;
        if(str[i]==ch3)str[i]=rch3;
    }
    return str;
}

void soln(ll t){
    ll n,a,d,k,f=0;
    string str;
    cin>>str;

    f=isbalance(replaceall(str,'A',')','B',')','C','('));
    if(!f)f=isbalance(replaceall(str,'A',')','B','(','C',')'));
    if(!f)f=isbalance(replaceall(str,'A','(','B',')','C',')'));

    if(!f)f=isbalance(replaceall(str,'A','(','B','(','C',')'));
    if(!f)f=isbalance(replaceall(str,'A',')','B','(','C','('));
    if(!f)f=isbalance(replaceall(str,'A','(','B',')','C','('));

    if(f)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

int cc_main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



