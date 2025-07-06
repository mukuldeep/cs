#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    string str;
    cin>>str;
    ll slen=str.length();
    ll ans=0,dg=0;
    for (int i = 0; i < slen; i++){
        dg+=(str[i]-'0')*(i+1);
        ans+=(dg*pow(10,slen-1-i));
    }
    cout<<ans<<endl;
    return 0;
}



