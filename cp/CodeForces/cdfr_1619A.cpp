//
// Created by me on 27-01-2022.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define W_(n) while((n)--)
#define O_ cout<<
#define I_ cin>>
#define EL endl;
using namespace std;
typedef long long ll;

void soln(ll t){//each test case
    ll n;
    string str;
    I_ str;
    n=str.length();
    if(n&1){//if size of the string is odd then it is not possible to divide into two so answer is "NO"
        O_ "NO"<<EL
    }else{//if size of the string is even
        if(str.substr(0,n/2)==str.substr(n/2,n/2))//if the first half is same as second half
            O_ "YES"<<EL
        else//if the first half is different from second half
            O_ "NO"<<EL
    }

}

DRIVER
