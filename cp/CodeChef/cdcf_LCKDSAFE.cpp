//
// Created by me on 14-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,in,d;
    cin>>n;
    vector<ll> arr;
    vector<vector<ll>> my_arr;
    vector<ll> her_arr;
    her_arr.assign(63,0);
    my_arr.assign(n+1,her_arr);

    ll max_sum=0,last_max=0;
    for(int i=1;i<=n;i++) {
        cin>>in;
        string s = bitset<64> (in).to_string();
        ll local_max=0;
        for(ll j=0;j<62;j++){
            //cout<<s[63-i];
            if(s[63-j]=='1'){
                if(my_arr[i-1][j]==last_max)
                    my_arr[i][j]=my_arr[i-1][j]+1;
                else
                    my_arr[i][j]=1;
            }
            if(my_arr[i][j]>local_max)local_max=my_arr[i][j];
        }
        last_max=local_max;
        max_sum+=local_max;
    }

    ll ans;
    ans=n*(n+1);
    ans>>=1;
    ans-=max_sum;
    cout<<ans<<endl;
}

int cc_main() {
    //test();
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



