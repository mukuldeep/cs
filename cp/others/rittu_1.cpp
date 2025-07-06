#include <bits/stdc++.h>
#define ll long long
using namespace std;
int cc_main() {
    string str;
    cin>>str;
    ll slen=str.length();
    ll ans=0;
    for (int i = 0; i < slen; i++)
        for (int len = 1; len <= slen - i; len++)
            ans+=stoi(str.substr(i, len));
    cout<<ans<<endl;
    return 0;
}



