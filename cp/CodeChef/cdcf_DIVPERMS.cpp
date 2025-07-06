//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,s,d;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        arr[i] = i + 1;
    }
    vector<map<int,int>> adj;
    do{
        map<int,int> mp;
       for(int i=1;i<n;i++){
           if(arr[i]%arr[i-1]==0){
                mp[arr[i]/arr[i-1]]++;
           }
       }
        adj.push_back(mp);
    }while(next_permutation(arr,arr+n));

//    for(auto mpf:adj){
//        for(auto pr:mpf){
//            cout<<pr.first<<":"<<pr.second<<" ";
//        }
//        cout<<" -v"<<endl;
//    }
    int upto=1<<n;
    for(int i=1;i<=upto;i+=4){
        int k[n+1]={0};
        for(auto mpf:adj){
            int loc_cost=0;
            for(auto pr:mpf){
                if(i&(1<<pr.first)){
                    loc_cost+=pr.second;
                }
                //cout<<pr.first<<":"<<pr.second<<" ";
            }
        //cout<<" -v"<<endl;
        k[loc_cost]++;
        }
        cout<<i-1<<": \t";
        for(int xo=0;xo<=n;xo++){
//            if((i-1)/4)
//                cout<<k[xo]/120<<" ";
//            else if((i-1)/2)
//                cout<<k[xo]/24<<" ";
//            else
            cout<<k[xo]<<" \t";
        }
        cout<<endl;

    }



}

int cc_main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



