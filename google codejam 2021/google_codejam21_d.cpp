//
// Created by me on 26-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define t9p7 1000000007
using namespace std;

vector<ll> median_sort(vector<ll> arr){
    if(arr.size()<3){
        return arr;
    }
    vector<ll> part1,part2,part3,spart1,spart2,spart3;
    ll f_ms=arr[0],s_ms=arr[1],midans;

    if(arr.size()==3) {
        cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
        cin>>midans;
        if(midans==arr[0])swap(arr[0],arr[1]);
        if(midans==arr[2])swap(arr[1],arr[2]);
        return arr;
    }

    for(ll i=2;i<arr.size();i++){
        cout<<f_ms<<" "<<s_ms<<" "<<arr[i]<<endl;
        cin>>midans;
        if(midans==arr[i])
            part2.push_back(arr[i]);
        else if(midans==f_ms)
            part1.push_back(arr[i]);
        else
            part3.push_back(arr[i]);
    }
    spart1=median_sort(part1);
    spart2=median_sort(part2);
    spart3=median_sort(part3);

    //merge
    vector<ll> merged_arr;
    if(spart1.size()>1){
        cout<<f_ms<<" "<<spart1[spart1.size()-1]<<" "<<spart1[spart1.size()-2]<<endl;
        cin>>midans;
        if(midans!=spart1[spart1.size()-1])
            reverse(spart1.begin(),spart1.end());
    }
    for(auto xx:spart1)merged_arr.push_back(xx);
    merged_arr.push_back(f_ms);

    if(spart2.size()>1){
        cout<<f_ms<<" "<<spart2[0]<<" "<<spart2[1]<<endl;
        cin>>midans;
        if(midans!=spart2[0])
            reverse(spart2.begin(),spart2.end());
    }
    for(auto xx:spart2)merged_arr.push_back(xx);
    merged_arr.push_back(s_ms);

    if(spart3.size()>1){
        cout<<s_ms<<" "<<spart3[0]<<" "<<spart3[1]<<endl;
        cin>>midans;
        if(midans!=spart3[0])
            reverse(spart3.begin(),spart3.end());
    }
    for(auto xx:spart3)merged_arr.push_back(xx);

    return merged_arr;
}

void soln(ll t,ll n,ll &q){
    vector<ll> arr,sarr;
    for(ll i=1;i<=n;i++){
        arr.push_back(i);
    }
    sarr=median_sort(arr);
    for(auto xx:sarr){
        cout<<xx<<" ";
    }cout<<endl;
}

int cc_main() {
    ll t,q,n,check;
    cin>>t>>n>>q;
    for(int i=1;i<=t;i++){
        soln(i,n,q);
        cin>>check;
        if(check==-1)return 0;
    }
    return 0;
}



