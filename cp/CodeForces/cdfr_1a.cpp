#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void soln(ll t){
    ll n,m,k,a,b,c;
    cin>>n>>m>>a;
    a=ceil((ld)n/(ld)a)*ceil((ld)m/(ld)a);
    cout<<a<<endl;
}

int main(int argc, char *argv[])
{ ll t=1;
    //cin>>t;
    while(t--){
        soln(t);
    }
    return 0;
}