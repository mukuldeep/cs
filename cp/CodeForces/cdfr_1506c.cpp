//
// Created by me on 25-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int lcsubstr(string X, string Y, int m, int n)
{
    int dp[m + 1][n + 1];
    int res = 0;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                res = max(res, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return res;
}
void soln(ll t){
    string a,b;
    cin>>a>>b;
    int lcsn=lcsubstr(a,b,a.length(),b.length());
    int ans=a.length()+b.length()-2*lcsn;
    cout<<ans<<endl;

}

int main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



