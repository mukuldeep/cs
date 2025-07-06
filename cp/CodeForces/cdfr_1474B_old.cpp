//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n_prime[1000000];
void SieveOfEratosthenes()
{   bool prime[1000000];
    int n=1000000;
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    int last_p;
    int p=n-1;
    while(!prime[p])p--;
    n_prime[p]=p;
    last_p=p;
    for(;p>1;p--){
        if(prime[p]){
            last_p=p;
        }
        n_prime[p]=last_p;
    }

}

void soln(ll t){
    SieveOfEratosthenes();
    ll d;
    cin>>d;
   ll ans=1,last_p=1;
    ans*=last_p;
    last_p=n_prime[last_p+d];
    ans*=last_p;
    last_p=n_prime[last_p+d];
    ans*=last_p;
//    last_p=n_prime[last_p+d];
//    ans*=last_p;
    cout<<ans<<endl;

}

int cc_main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



