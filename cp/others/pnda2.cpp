
#include<bits/stdc++.h>
using namespace std;
int sol(string str, int k)
{
    int n = str.length();
    int r = 0;
    int cnt[26];
    for (int i = 0; i < n; i++)
    {
        int d_count = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int j=i; j<n; j++)
        {
            if (cnt[str[j] - 'a'] == 0)d_count++;
            cnt[str[j] - 'a']++;
            if (d_count == k)r++;
            if(d_count > k) break;
        }
    }
    return r;
}
int cc_main()
{
    string str = "abc";
    int k = 2;
    cout << "Total substrings with exactly "
         << k <<" distinct characters :"
         << sol(str, k) << endl;
    return 0;
}
