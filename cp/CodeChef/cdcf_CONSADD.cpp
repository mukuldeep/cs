//
// Created by me on 10-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void print_v(vector<vector<ll>> mat){
    cout<<"matrix"<<endl;
    for(auto x:mat){
        for(auto r:x){
            cout<<r<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void soln(ll t){
    ll r,c,x,el;
    cin>>r>>c>>x;

    vector<vector<ll>> mat;
    for(ll i=0;i<r;i++) {
        vector<ll> thiscolumn;
        for(ll j=0;j<c;j++){
            cin>>el;
            thiscolumn.push_back(el);
        }
        mat.push_back(thiscolumn);
        thiscolumn.clear();
    }
    print_v(mat);
    for(ll i=0;i<r;i++) {
        for(ll j=0;j<c;j++){
            cin>>el;
            mat[i][j]-=el;
        }
    }
    vector<ll> sum_arr,inv_sum_arr;
    sum_arr.assign(x+5,0);
    inv_sum_arr.assign(x+5,0);

    ll start=0;
    for(ll i=0;i<r;i++) {
        ll ind=start;
        for (ll j = 0; j < c; j++) {
            sum_arr[ind]+=mat[i][j];
            inv_sum_arr[ind]+=mat[i][c-1-j];
            ind++;
            ind%=x;
        }
        start++;
        start%=x;
    }

    ll f=1,f2=1,inisum=sum_arr[0];
    for(ll i=1;i<x;i++){
        if(sum_arr[i]!=inisum){
            f=0;
            break;
        }
    }

    if(f ){
        inisum=inv_sum_arr[0];
        for(ll i=1;i<x;i++){
            if(inv_sum_arr[i]!=inisum){
                f2=0;
                break;
            }
        }
    }

    if(f && f2){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    mat.clear();
}

int cc_main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



