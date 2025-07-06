//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll a,b;
    string str;
    cin>>str;
    ll cnt[27]={0};
    for(auto ch:str){
        cnt[ch-'A']++;
    }
    ll odd=-1,oddcnt=0;
    for(ll i=0;i<26;i++){
        if(cnt[i]&1){
            oddcnt++;
            odd=i;
        }
    }

    if(oddcnt>1)
        cout<<"NO SOLUTION"<<endl;
    else{
        for(ll i=0;i<26;i++){
            if(odd!=i)
            for(ll j=0;j<cnt[i]/2;j++){
                cout<<char('A'+i);
            }
        }
        if(oddcnt)
            for(ll j=0;j<cnt[odd];j++){
                cout<<char('A'+odd);
            }
        for(ll i=25;i>=0;i--){
            if(odd!=i)
                for(ll j=0;j<cnt[i]/2;j++){
                    cout<<char('A'+i);
                }
        }

    }

}

int main() {
    ll t=1;
//    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



