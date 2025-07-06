//
// Created by me on 4-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;


void soln(ll t){
    ll n,x=0,a,b,lseq=0,seq=0;
    map<ll,ll> umap;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a;
        if(n-seq+lseq<i)continue;
        if(umap.find(a)==umap.end()){
            umap[a]=i;
            lseq++;
            if(seq<lseq)seq=lseq;
        }else{
            ll umpa=umap[a];
            if(i-umpa<=lseq)
                lseq=i-umpa;
            else{
                lseq++;
                if(seq<lseq)seq=lseq;
            }
            umap[a]=i;
        }

    }
    cout<<seq<<endl;

}

int main() {
    soln(0);
    return 0;
}



