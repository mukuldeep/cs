//
// Created by me on 29-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll getSum(ll n)
{
    ll sum = 0;
    while (n != 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}


void soln(ll t){
    ll a,b,n,k;
    cin>>n;
    while(gcd(n,getSum(n))==1)n++;
    cout<<n<<endl;
}

int main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



