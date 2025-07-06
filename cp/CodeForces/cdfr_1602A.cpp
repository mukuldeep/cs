/*
 * Created by DailyLinesOfCode on 03-11-2021.
 */
#include <bits/stdc++.h>
#define ll long long
#define t9p7 1e9+7
#define INF 1e17
using namespace std;

//pre code if any
void pre(){

}

//solution a single testcase
void soln(ll t){
    ll m,n,k,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string s,a,b;
    char ch;
    cin>>s;
    ch=s[0];
    for(auto s_ch:s){
        ch=min(ch,s_ch);
    }
    bool isdonea=false;
    for(auto s_ch:s){
        if(!isdonea && s_ch==ch){
            isdonea=true;
            a=ch;
        }else{
            b+=s_ch;
        }

    }
    cout<<a<<" "<<b<<endl;
}

//main function
int main(){
    //pre code if any
    pre();
    //test cases
    ll t;
    cin>>t;
    while(t--)
        soln(t);//every test case
}
