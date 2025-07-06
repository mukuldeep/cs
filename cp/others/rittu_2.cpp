#include <bits/stdc++.h>
#define ll long long
using namespace std;
int cc_main() {
    ll steps[11],st,ans[11];
    for(ll i=0;i<11;i++){
     cin>>steps[i];
     ans[i]=LONG_LONG_MAX-1;
    }
    time_t start, end;
    time(&start);

    ans[0]=0;
    for(ll i=0;i<11;i++){
        for(ll j=i+1;j<11;j++){
            if(j<=i+steps[i]){
                ans[j]=min(ans[j],ans[i]+1);
            }else{
                break;
            }
        }
    }
    cout<<ans[10]<<endl;
    time(&end);
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(20);
    cout << " sec " << endl;
    return 0;
}



