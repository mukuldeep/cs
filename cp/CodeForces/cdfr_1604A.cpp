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
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,current_pos=1,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a;
        if(a>current_pos){
            cnt+=(a-current_pos);
            current_pos=a;
        }
        current_pos++;
    }
    cout<<cnt<<endl;
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
