
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<string> explode(string const & s, char delim)
{
    vector<string> result;
    istringstream iss(s);
    for (string token; getline(iss, token, delim); )
        result.push_back(move(token));
    return result;
}
int main(){
    ll cnt=0;
    string str;
    unordered_map<string,ll> mp;
    getline(cin,str);
    vector<string> arr;
    arr=explode(str,' ');
    for(auto xx:arr){
        mp[xx]++;
    }
    for(auto xd:mp){
        if(xd.second==1)
            cnt++;
    }
    cout<<cnt;
    return 0;
}
