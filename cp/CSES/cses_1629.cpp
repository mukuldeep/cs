//
// Created by me on 4-3-2021.
//
#include <bits/stdc++.h>
#define ll long long    
using namespace std;
bool sortbysec(const pair<ll,ll>& a,const pair<ll,ll>& b){
    return a.second<b.second;
}
void soln(ll t){
    ll n,x,ans=0,lsum=0,a,b;
    vector<pair<ll,ll>> arr;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a>>b;
        arr.push_back(make_pair(a,b));
    }
    sort(arr.begin(),arr.end(),sortbysec);
    ll last_included=arr[0].second;
    ans++;
    //cout<<arr[0].first<<" "<<arr[0].second<<endl;
    for(ll i=1;i<n;i++){
        ll curr_s=arr[i].first;
        ll curr_e=arr[i].second;
        if(curr_s>=last_included){
            ans++;
            last_included=curr_e;
            //cout<<curr_s<<" "<<curr_e<<endl;
        }
    }

    cout<<ans<<endl;
}

int cc_main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



