//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MX_P=7;
void print_a(ll a[],ll n) {
    for(ll i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
ll check_one_possibility(ll n,ll x[],ll a[]){
    ll mul=0;
    for(int i=0;i<n;i++){
        mul+=x[i]*a[i];
    }
    if(mul%MX_P==0)
        return 1;
    return 0;
}
void all_possible_x(ll n,ll h,ll x[],ll a[],ll &cnt,ll hsh[]) {
    if(n==h) {
        if(check_one_possibility(n,x,a)){
            //print_a(x, n);
            cnt++;
        }
        return;
    }
    for(ll i=0;i<MX_P;i++) {
        if(hsh[i]==0) {
            hsh[i]=1;
            x[h] = i;
            all_possible_x(n, h + 1, x, a, cnt, hsh);
            hsh[i]=0;
        }
    }
}

void soln(ll t){
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    //sort(a,a+n);

    ll x[n];
    ll hsh[MX_P+1]={0};
    ll cnt=0;
    all_possible_x(n,0,x,a,cnt,hsh);
    cout<<cnt<<":done"<<endl;
}
void all_possible_soln(ll n,ll h,ll a[]){
    if(n==h) {
        ll a_sum=0;
        for(int dd=0;dd<n;dd++){
            a_sum+=a[dd];
        }
        ll x[n];
        ll hsh[MX_P+1]={0};
        ll cnt=0;
        all_possible_x(n,0,x,a,cnt,hsh);
        if(cnt!=120) {
            cout << cnt << " : done : ";
            print_a(a, n);
            if (a_sum % MX_P == 0)cout<<a_sum << " ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
        }
        return;
    }
    for(ll i=0;i<MX_P;i++) {
        a[h]=i;
        all_possible_soln(n, h + 1,a);
    }
}
int ans_main();
int cc_main() {
    ll t;
    cin>>t;
    while(t--) {

        ll n;
        cin>>n;
        ll m[n]={0};
        all_possible_soln(n,0,m);

        //soln(t);
        //ans_main();
    }
    return 0;
}
int ans_main() {
    ll n;
    cin>>n;
    ll a[n];
    ll sum=0;
    ll n_pos=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum+=a[i];
        if(a[i])n_pos++;
    }
    if(n_pos==2 && sum==239){
        cout<<0<<endl;
        return 0;
    }
    sort(a,a+n);
    ll ans=1;
    if(a[n-1]==0){
        for(int i=0;i<n;i++){
            ans*=(239-i);
            ans%=998244353;
        }
    }else{
        for(int i=1;i<n;i++){
            ans*=(239-i);
            ans%=998244353;
        }
    }
    cout<<ans<<endl;
    return 0;
}




