/*
 * Created by me on 24-11-2021.
 */
#include <bits/stdc++.h>
#define F(a,c) for (ll a=0;a<c; a++)
#define ll long long
#define V(x) vector<x>
using namespace std;

/*
 * storing smallest prime factor in prime[] using  SieveOfEratosthenes
 */
ll const prime_upto=10000005;
ll smallest_prime_factor[prime_upto + 1]={0};
void SieveOfEratosthenes(ll n=prime_upto)
{
    for (ll p = 2; p * p <= n; p++)
        if (!smallest_prime_factor[p])
            for (ll i = p * p; i <= n; i += p)
                if(!smallest_prime_factor[i])smallest_prime_factor[i]=p;

}
/*
 * main function / driver function
 */
int main(){
    SieveOfEratosthenes();
    ll n,a,b;
    cin>>n;
    V(ll) arr(n+1),arr2(n+1);//to store divisors d1 & d2 in different array
    F(i,n){//iterating through elements
        cin>>a;
        if(!smallest_prime_factor[a]){//if element is prime
            arr[i]=-1;
            arr2[i]=-1;
        }else{//if element is not prime
            b=a;
            while(b%smallest_prime_factor[a]==0){//dividing with smallest prime factor iff divisible
                b/=smallest_prime_factor[a];
            }
            if(b==1){//only consist of the smallest prime factor
                arr[i]=-1;
                arr2[i]=-1;
            }else{//can be divisible
                arr[i]=b;//one divisor is the left over number after dividing with smallest prime factor
                arr2[i]=a/b;//another number is the element divided by the previouly found divisor
            }
        }
    }

    //printing divisor array as output
    F(i,n)cout<<arr[i]<<" ";cout<<endl;
    F(i,n)cout<<arr2[i]<<" ";cout<<endl;
    return 0;
}

