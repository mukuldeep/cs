//
// Created by me on 14-3-2021.
//
// code snippet for extended gcd and mod inverse is taken from geeksforgeeks
#include <bits/stdc++.h>
#define ll long long
#define t9p7 1000000007

using namespace std;

ll inv[200005]={0};
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
void precalc(){
    inv[0]=1;
    for(ll i=1;i<200002;i++){
        inv[i]=mod_inv(i)%t9p7;
    }
}


void dfs(vector<vector<ll>> &adj,vector<ll> &vis,vector<ll> &prob,ll node,ll prev_prob,ll dist,ll n_sib){
    if(dist<=0){
        return;
    }
    vis[node]=1;
    ll curr_prob=prev_prob*inv[n_sib];curr_prob%=t9p7;
    prob[node]+=curr_prob;prob[node]%=t9p7;
    ll n_chld=adj[node].size()-1;
    for(auto chld:adj[node]){
        if(!vis[chld]){
            dfs(adj,vis,prob,chld,curr_prob,dist-1,n_chld);
        }
    }
}
void subtask3(vector<vector<ll>> &adj,ll ind_1,ll n,ll q){
    vector<ll> lin_ar(n+5),index_of(n+5),qu_on;qu_on.assign(n+5,0);
    lin_ar[0]=ind_1;
    index_of[lin_ar[0]] = 0;
    for(ll i=1;i<n;i++) {
        if(adj[lin_ar[i - 1]][0] == lin_ar[i-1])
            lin_ar[i]= adj[lin_ar[i - 1]][1];
        else
            lin_ar[i]=adj[lin_ar[i - 1]][0];
        index_of[lin_ar[i]] = i;
    }

    vector<pair<ll,ll>> ranges;

    //query
    ll last=0;
    ll a,b,op,node,dist,ind_of_node,n_ranges,ans;
    for(ll i=0;i<q;i++) {
        cin >> op;
        if (op == 1) {
            cin>>a>>b;
            node=(last+a)%n+1;
            dist=(last+b)%n+1;
            ind_of_node=index_of[node];

            ranges.push_back(make_pair((ind_of_node-dist),(ind_of_node+dist)));
            if(adj[node].size()==1){
                ranges.push_back(make_pair((ind_of_node-dist),(ind_of_node+dist)));
            }else {
                qu_on[node]++;
            }
        }else{
            cin>>a;
            node=(last+a)%n+1;
            n_ranges=0;
            ind_of_node=index_of[node];
            for(auto range:ranges){
                if(range.first<=ind_of_node && ind_of_node<=range.second)
                    n_ranges++;
            }
            n_ranges+=qu_on[node];
            ans=(n_ranges*inv[2]); ans%=t9p7;
            cout<<ans<<endl;
            last=ans;
        }

    }
}
void soln(ll t){
    ll n,q,s,u,v;
    cin>>n>>q;
    vector<vector<ll>> adj(n+1);
    vector<ll> prob;
    prob.assign(n+1,0);
    for(ll i=1;i<n;i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //<subtask 3
    ll cnt_2=0,cnt_1=0,ind_1;
    for(ll i=1;i<=n;i++){
        if(adj[i].size()==2){
            cnt_2++;
        }else if(adj[i].size()==1){
            cnt_1++;
            ind_1=i;
        }
    }
    if(cnt_1==2 && cnt_2==n-2){//subtask 3
        subtask3(adj,ind_1,n,q);
        return;
    }
    //subrask 3/>

    ll last=0;
    ll a,b,op,node,dist;
    for(ll i=0;i<q;i++){
        cin>>op;
        if (op==1){
            cin>>a>>b;
            node=(last+a)%n+1;
            dist=(last+b)%n+1;
            //cout<<"1. node:"<<node<<endl;
            if(dist>0) {
                vector<ll> vis;
                vis.assign(n + 1, 0);
                prob[node]+=1;prob[node]%=t9p7;
                vis[node]=1;
                ll sib_n=adj[node].size();
                for(auto chld:adj[node]) {
                    dfs(adj, vis,prob,chld,1,dist,sib_n);
                }
//                for(auto xxx:prob){
//                    cout<<xxx<<" ";
//                }cout<<endl;
            }
        }else{
            cin>>a;
            node=(last+a)%n+1;
            //cout<<"2. node:"<<node<<endl;
            cout<<prob[node]<<endl;
            last=prob[node];
        }
    }
}

int cc_main() {
    precalc();
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



