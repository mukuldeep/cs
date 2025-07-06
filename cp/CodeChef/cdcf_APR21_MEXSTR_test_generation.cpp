//
// Created by me on 04-04-2021.
//
#include <bits/stdc++.h>
#define DRIVER int main(){ll t=1;I_ t;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){ll t=1;I_ t;W_(t)soln(t);return 0;}
#define FR_(a,c)   for (ll (a)=0;(a)<(c); (a)++)
#define FR_E(a,c)   for (ll (a)=0;(a)<=(c); (a)++)
#define FR_IR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FR_AU(xx,xxs) for(auto (xx):(xxs))
#define W_(n) while((n)--)
#define WH_ while
#define IL_ while(1)
#define PB_ push_back
#define MP_(a,b) make_pair((a),(b))
#define O_ cout<<
#define I_ cin>>
#define EL endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef vector<pair<ll, ll>> vprll;
typedef map<ll,ll>  mpll;
typedef unordered_map<ll,ll> uompll;

string decToBinary(int n)
{
    if(!n)return "0";
    int binaryNum[64];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    string str="";
    for (int j = i - 1; j >= 0; j--){
        str+=binaryNum[j]?"1":"0";
    }
        //cout << binaryNum[j];
    return str;
}
bool is_subseq(string t, string s) {
    if(s == t)
        return true;
    int n = s.size();
    int m = t.size();
    int j = 0;
    for(int i = 0; i < n; i++){
        if(t[j] == s[i])
            j++;
        if(j == t.size())
            return true;
    }
    return false;
}

void soln(ll t){
    ll n,k,a,b,c;
    I_ n;
    FR_IR(i,0,n+1){
        O_ decToBinary(i)<<EL
    }
}

TEST_DRIVER
