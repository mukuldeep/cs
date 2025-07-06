//
// Created by me on 25-05-2021.
//
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,a,b;
    cin>>n;
    while(n--) {
        cin>>a>>b;
        if ((a + b) % 3) {
            cout<<"NO\n";// << endl;
            continue;
        }
        if (a > b)swap(a, b);
        if ((a << 1) >= b)cout<<"YES\n";// << endl;
        else cout<<"NO\n";// << endl;
    }
    return 0;
}


