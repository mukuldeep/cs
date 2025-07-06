//
// Created by me on 17-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> prime_sq_list;
void SieveOfEratosthenes(ll n=10005)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (ll p = 2; p <= n; p++)
        if (prime[p])
            prime_sq_list.push_back(p*p);
}
ll minimumSubarrays(vector<ll> ar, int n)
{
    set<ll> se;
    ll cnt = 1;

    for (ll i = 0; i < n; i++) {
        if (se.count(ar[i]) == 0) {
            se.insert(ar[i]);
        }
        else {
            cnt++;
            se.clear();
            se.insert(ar[i]);
        }
    }
    return cnt;
}
void soln(ll t){
    ll n,s,d,k,a;
    cin>>n>>k;

    vector<ll> arr;
    for(ll i=0;i<n;i++){
        cin>>a;
        for(auto sq:prime_sq_list){
            if(a<sq)break;
            while(a%sq==0)
                a/=sq;
        }
        arr.push_back(a);
    }
    cout<<minimumSubarrays(arr,n)<<endl;
}

int main() {
    SieveOfEratosthenes(100008);
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



