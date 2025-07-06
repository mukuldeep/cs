//
// Created by me on 25-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void soln(ll t){
    //freopen("./inout/a_output.txt", "r", stdin);
    ll n,m,x;
    cin>>n;
    unordered_map<ll,ll> umap;

    for(ll i=0;i<n;i++){
        cin>>x;
        //if(umap.find(x)==umap.end()){
        //    umap[x]=1;
        //}else {
        umap[x]++;
        //}
    }
    ll ans=0,h=n/2;
    for (auto f : umap){
        if(f.second>h){
            ans=f.second-(n-f.second);
            break;
        }
    }
    if(n&1 && ans==0)ans=1;
    cout<<ans<<endl;
}

int main() {


    ll t;
    cin>>t;
//    clock_t start, end;
//
//    /* Recording the starting clock tick.*/
//    start = clock();
    while(t--)
        soln(t);

//    end = clock();

//    // Calculating total time taken by the program.
//    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
//    cout << "Time taken by program is : " << fixed
//         << time_taken << setprecision(5);
//    cout << " sec " << endl;
    return 0;
}



