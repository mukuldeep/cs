#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll const prime_upto=1000005;
vector<vector<ll>> d_prime_factors(prime_upto + 1);
void distinct_prime_factors(ll n=prime_upto)
{
    for (ll p = 2; p<= n; p++)
        if (!(d_prime_factors[p].size()))
            for (ll i = p; i <= n; i += p)
                d_prime_factors[i].push_back(p);
}


int cc_main(){
    ll q,n;
    distinct_prime_factors();
    cin>>q;
    while(q--){
        cin>>n;
        for(auto factor:d_prime_factors[n])
            cout<<factor<<" ";
        cout<<endl;
    }
    return 0;
}

/*

 6
 23
 76354
 100
 120
 720
 125








 */