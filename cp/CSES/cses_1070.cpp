//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,nn,hs,i,h;
    cin>>n;
    if(n<4 && n>1){
        cout<<"NO SOLUTION"<<endl;
    }else{
        i=1;
        nn=n;
        h=n/2;
        hs=h+1;
        while(n){
            if(hs<=nn) {
                cout << hs << " ";
                n--;
                hs++;
            }
            if(i<=h) {
                cout << i << " ";
                n--;
                i++;
            }

        }



    }
}

int main() {
        soln(0);
    return 0;
}



