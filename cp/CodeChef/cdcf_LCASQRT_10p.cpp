//
// Created by me on 10-12-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void print_a(ll a[],ll n) {
    for(ll i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
ll child_of_lca(ll par[],ll lca,ll curr){
    while(par[curr]!=lca){
        curr=par[curr];
        if(curr==-1)
            break;
    }
    return curr;
}

void sum_of_child(ll a[],vector<ll> ch[],ll &sum_b,ll chl){
    sum_b+=a[chl];
    for(auto chld:ch[chl]){
            sum_of_child(a,ch,sum_b,chld);
    }
}

void sum_of_all_Lix(ll a[],ll par[],vector<ll> ch[],ll ex,ll &sum_b){
    sum_b+=a[par[ex]];
    for(auto chld:ch[par[ex]]){
        if(chld!=ex){
            sum_of_child(a,ch,sum_b,chld);
        }
    }
}

ll sum_l_ix(ll a[],ll i,ll x,ll par[],vector<ll> ch[]){
    ll sum_b = 0;
    if(i!=x) {
        ll ch_of_lca = child_of_lca(par, x, i);
        if (ch_of_lca == -1)return 0;

        sum_of_all_Lix(a, par, ch, ch_of_lca, sum_b);
        return sum_b;
    }else{
        sum_of_child(a,ch,sum_b,i);
        return sum_b;
    }
}
ll c_x(ll n,ll a[],ll p,ll x,ll par[],vector<ll> ch[]){
    ll cx=0;
    for(int i=0;i<n;i++){
        cx+=(a[i]*sum_l_ix(a,i,x,par,ch));//%998244353;
    }
    cx%=p;
    return cx;
}
ll check_one_possibility(ll n,ll c[],ll a[],ll p,ll par[],vector<ll> ch[]){
    for(int x=0;x<n;x++){
        if(c[x]!=c_x(n,a,p,x,par,ch))return 0;
    }
    return 1;
}
void copy_to_ans_a(ll a[],ll ans_a[],ll n){
    for(int x=0;x<n;x++){
        ans_a[x]=a[x];
    }
}
void all_possible_a(ll n,ll p,ll h,ll c[],ll a[],ll &cnt,ll par[],vector<ll> ch[],ll ans_a[]) {
    if(n==h) {
        if(check_one_possibility(n,c,a,p,par,ch)) {
            if(cnt==0){
                copy_to_ans_a(a,ans_a,n);
            }
            cnt++;
            cnt%=998244353;
        }
        return;
    }
    for(ll i=0;i<p;i++) {
        a[h]=i;
        all_possible_a(n,p,h+1,c,a,cnt,par,ch,ans_a);
    }
}

void soln(ll t){
    ll n,p;
    cin>>n>>p;
    ll par[n]={0};
    par[0]=-1;
    //1# input and tree creation
    vector<ll> child[n];
    for(int i=1;i<n;i++) {
        cin>>par[i];
        par[i]--;
        child[par[i]].push_back(i);
    }
    ll c[n];
    for(int i=0;i<n;i++){
        cin>>c[i];
    }

    //2# L (i,x) for all possible one (in #3)
    //3# creating all possible sequence of a
    ll a[n],ans_a[n];
    ll cnt=0;
    all_possible_a(n,p,0,c,a,cnt,par,child,ans_a);
    //cout<<child_of_lca(par,1,5);
    //4# printing result

        cout<<cnt<<endl;
        if(cnt==0){
            cout<<-1<<endl;
        }else{
            for(int x=0;x<n;x++){
                cout<<ans_a[x]<<" ";
            }
            cout<<endl;
        }
}

int cc_main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}
/*

2
6 3
1 1 2 3 2
1 2 0 1 1 1
 5 3
 1 1 1 3
 2 1 0 2 1
 */


