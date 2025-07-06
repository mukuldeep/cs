//
// Created by me on 17-04-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define FR_(a,c)   for (ll (a)=0;(a)<(c); (a)++)
#define FR_E(a,c)   for (ll (a)=0;(a)<=(c); (a)++)
#define FR_IR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FR_AU(xx,xxs) for(auto (xx):(xxs))
#define srt(ww) sort((ww).begin(),(ww).end())
#define W_(n) while((n)--)
#define WH_ while
#define IL_ while(1)
#define PB_ push_back
#define MP_(a,b) make_pair((a),(b))
#define O_ cout<<
#define PRCN fixed<<setprecision(20)
#define I_ cin>>
#define EL endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef stack<ll> skll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef vector<pair<ll, ll>> vprll;
typedef map<ll,ll>  mpll;
typedef unordered_map<ll,ll> uompll;
typedef set<ll> stll;
const ll t9p7=1000000007;

//returns longest subsequence as string
// T&S O(m*n)+O(m+n)   length of two strings
string lcs_str_str(string s1,string s2){
    ll n1=s1.length(),n2=s2.length();
    vector<vll> tab(n1+1,vll(n2+1,0));
    FR_IR(i,1,n1+1)
        FR_IR(j, 1, n2 + 1)
            if (s1[i-1] == s2[j-1])tab[i][j] = tab[i - 1][j - 1] + 1;
                else tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);

    string str="";
    ll i=n1,j=n2;
    while(i>0 && j>0)
        if(s1[i-1]==s2[j-1]) {
            str+=s1[i - 1];
            i--,j--;
        }else if(tab[i-1][j]>tab[i][j-1])i--;
        else j--;
    reverse(str.begin(),str.end());
    return str;
}

//returns length of longest subsequence
// T&S O(m*n)   length of two strings
ll lcs_str_len(string s1,string s2){
    ll n1=s1.length(),n2=s2.length();
    vector<vll> tab(n1+1,vll(n2+1,0));
    FR_IR(i,1,n1+1)
        FR_IR(j, 1, n2 + 1)
            if (s1[i-1] == s2[j-1])tab[i][j] = tab[i - 1][j - 1] + 1;
            else tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
    return tab[n1][n2];
}

//returns length of longest common subsequence
// T&S O(m*n)   length of the arrays
ll lcs_arr_len(vll s1,vll s2){
    ll n1=s1.size(),n2=s2.size();
    vector<vll> tab(n1+1,vll(n2+1,0));
    FR_IR(i,1,n1+1)
        FR_IR(j, 1, n2 + 1)
            if (s1[i-1] == s2[j-1])tab[i][j] = tab[i - 1][j - 1] + 1;
            else tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
    return tab[n1][n2];
}

//returns length of longest common subsequence
// T O(n*m) S O(2*m)   length of the arrays
ll lcs_arr_len_sp_op(vll s1,vll s2){
    ll n1=s1.size(),n2=s2.size();
    vector<vll> tab(2,vll(n2+1,0));
    FR_IR(i,1,n1+1)
        FR_IR(j, 1, n2 + 1)
            if (s1[i-1] == s2[j-1])tab[i&1][j] = tab[(i - 1)&1][j - 1] + 1;
            else tab[i&1][j] = max(tab[(i - 1)&1][j], tab[i&1][j - 1]);
    return tab[n1&1][n2];
}

//returns longest common subsequence as an array
// T&S O(m*n)+O(m+n)   length of two arrays
vll lcs_arr_arr(vll s1,vll s2){
    ll n1=s1.size(),n2=s2.size();
    vector<vll> tab(n1+1,vll(n2+1,0));
    FR_IR(i,1,n1+1)
        FR_IR(j, 1, n2 + 1)
            if (s1[i-1] == s2[j-1])tab[i][j] = tab[i - 1][j - 1] + 1;
            else tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);

    vll str;
    ll i=n1,j=n2;
    while(i>0 && j>0)
        if(s1[i-1]==s2[j-1]) {
            str.PB_(s1[i - 1]);
            i--,j--;
        }else if(tab[i-1][j]>tab[i][j-1])i--;
        else j--;
    reverse(str.begin(),str.end());
    return str;
}


void soln(ll t){
    ll n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
//    string str1,str2;
//    I_ str1>>str2;
//    O_ lcs_str_str(str1,str2)<<EL
    I_ n>>k;
    vll arr1,arr2;
    FR_IR(i,0,n){
        I_ a;
        arr1.PB_(a);
    }
    FR_IR(i,0,k){
        I_ a;
        arr2.PB_(a);
    }
    O_ lcs_arr_len_sp_op(arr1,arr2)<<EL
    FR_AU(ff,lcs_arr_arr(arr1,arr2)){
        O_ ff<<" ";
    }O_ EL

}

TEST_DRIVER