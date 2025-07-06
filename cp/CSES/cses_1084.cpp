//
// Created by me on 03-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,m,k,a,cnt=0;
    vector<ll> apa,app;
    vector<ll>::iterator itr;
    cin>>n>>m>>k;
    for(ll i=0;i<n;i++){
        cin>>a;
        app.push_back(a);
    }
    for(ll i=0;i<m;i++){
        cin>>a;
        apa.push_back(a);
    }
    sort(apa.begin(),apa.end());
    sort(app.begin(),app.end());
    itr=apa.begin();
    for(auto appl:app){

        while( itr<apa.end() && appl-(*itr)>k){
            itr++;
        }
        if(itr<apa.end()){
            if(abs(appl-(*itr))<=k){
                cnt++;
                itr++;
            }
        }else{
            break;
        }
    }
    cout<<cnt<<endl;

}

int cc_main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



