//
// Created by me on 5-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
unsigned long long llrand() {
    unsigned long long r = 0;

    for (int i = 0; i < 5; ++i) {
        r = (r << 15) | (rand() & 0x7FFF);
    }

    return r & 0xFFFFFFFFFFFFFFFFULL;
}

void soln(ll t){
    ll const n=300;
    ll md=10000001;
    ll xarr[n],cnt=0,itr;
    for(ll i=0;i<n;i++){
        //cout<<llrand()<<endl;
        xarr[i]=rand();
        cout<<xarr[i]<<" ";
    }cout<<endl;

    for(itr=0;itr<1000000;itr++){
        for(ll i=0;i<n;i++){
            //cout<<llrand()<<endl;
            xarr[i]<<=1;
            xarr[i]%=md;
            //cout<<xarr[i]<<" ";
            if(xarr[i]==1){
                cout<<"itr:"<<itr<<" "<<"el:"<<i<<endl;
                cnt++;
            }
        }//cout<<endl;
    }

    cout<<"after "<<itr<<" iterations, total no of match found="<<cnt<<endl;

}

int cc_main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



