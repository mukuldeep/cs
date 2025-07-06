//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void allperm(string str){
    ll n=str.length();
    cout<<str<<endl;
    ll isincomplete=1;
    while(isincomplete){
        ll i;
        //finding index 1
        for(i=n-2;i>=0;i--)
            if(str[i]<str[i+1])
                break;
        sort(str.begin()+i+1,str.end());
        //find next index
        ll j;
        for(j=i+1;j<n;j++)
            if(str[j]>str[i])
                break;
        if(i==-1 || j==n) {
            isincomplete = 0;
            break;
        }else
            swap(str[i],str[j]);
        cout<<str<<endl;

    }
}
void soln(ll t){
    ll fact[]={1,1,2,6,24,120,720,5040,40320};
    ll cnt[27]={0};
    ll n,ans=0;
    string str;
    cin>>str;
    for(auto i:str){
        cnt[i-'a']++;
    }
    ans=fact[str.length()];
    n=1;
    str="";
    for(ll i=0;i<26;i++){
        n*=fact[cnt[i]];
        while(cnt[i]--)
            str+='a'+i;
    }
    ans/=n;
    cout<<ans<<endl;

    allperm(str);
}

int cc_main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



