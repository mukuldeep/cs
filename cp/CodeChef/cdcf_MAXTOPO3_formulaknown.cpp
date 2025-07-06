//
// Created by me on 8-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define t9p7 1000000007
using namespace std;

ll fac[500005]={0},inv_fac[500005]={0};
ll gcdExtended(ll a, ll b, ll* x, ll* y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
ll mod_inv(ll a, ll m=t9p7)
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return -1;
    else
    {
        ll res = (x % m + m) % m;
        return res;
    }
}

void print_v(vector<ll> v,string name){
    cout<<endl<<name<<endl;
    for(auto o:v){
        cout<<o<<" ";
    }
    cout<<endl;
}

void precalc(){
    fac[0]=1;
    inv_fac[0]=mod_inv(1);
    for(ll i=1;i<500002;i++){
        fac[i]=(fac[i-1]*i)%t9p7;
        inv_fac[i]=(inv_fac[i-1]*mod_inv(i))%t9p7;
    }
}

ll dfss(vector<vector<ll>> &adj,vector<ll> &vis,ll node_n,vector<ll> &nos,vector<ll> &invpart,vector<ll> &allchildn){
    vis[node_n]=1;
    ll chcnt=0,an=1,l_invpart=1,all_chcnt=0;

    for(auto o: adj[node_n]){
        if(!vis[o]){
            ll l_an=dfss(adj,vis,o,nos,invpart,allchildn);
            an*=l_an;an%=t9p7;
            an*=l_an;an%=t9p7;
            ll div=fac[allchildn[o]]*invpart[o];div%=t9p7;
            an*=mod_inv(div);an%=t9p7;

            chcnt++;

            l_invpart*=invpart[o];l_invpart%=t9p7;

            all_chcnt+=allchildn[o];

        }
    }
    if(chcnt==0){
        allchildn[node_n]=0;
        invpart[node_n]=1;
        nos[node_n]=1;
        return 1;
    }
    allchildn[node_n]=all_chcnt+chcnt;
    l_invpart*=inv_fac[chcnt];l_invpart%=t9p7;
    invpart[node_n]=l_invpart;

    ll this_nos=1;
    this_nos*=fac[allchildn[node_n]];this_nos%=t9p7;
    this_nos*=l_invpart;this_nos%=t9p7;
    this_nos*=an;this_nos%=t9p7;
    nos[node_n]=this_nos;
    return this_nos;
}
void soln(ll t){
    ll n,k,x,y;
    cin>>n>>k;
    vector<vector<ll>> adj(n+1);
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<pair<ll,ll>> ans;
    ll lvla;
    for(ll i=1;i<=1;i++){//1 to n
        vector<ll> vis(n+1),nos(n+1),invpart(n+1),allchildn(n+1);
        for(ll xx=0;xx<=n;xx++){vis[xx]=0;invpart[xx]=0;allchildn[xx]=0;nos[xx]=0;}
        lvla=dfss(adj,vis,i,nos,invpart,allchildn);
        print_v(nos,"nos");
        print_v(invpart,"invpart");
        print_v(allchildn,"allchildn");

        ans.push_back(make_pair(lvla,i));
    }
    sort(ans.begin()+1,ans.end());

    for(ll i=0;i<n;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }

    if(k==1){
        cout<<ans[n-1].second<<" "<<ans[n-1].first<<endl;
    }else{
         cout<<ans[n-2].second<<" "<<ans[n-2].first<<endl;
    }

}
void test(){
    for(ll i=0;i<24;i++)
    cout<<i<<":"<<inv_fac[i]<<endl;
}
int cc_main() {
    precalc();
    test();
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



