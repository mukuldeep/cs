//
// Created by me on 11-3-2021.
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



void precalc(){
    fac[0]=1;
    inv_fac[0]=mod_inv(1);
    for(ll i=1;i<500002;i++){
        fac[i]=(fac[i-1]*i)%t9p7;
        inv_fac[i]=(inv_fac[i-1]*mod_inv(i))%t9p7;
    }
}

ll dfss(vector<vector<ll>> &adj,vector<ll> &vis,ll node_n,vector<ll> &nos,vector<ll> &invpart,vector<ll> &allchildn,vector<ll> &par){
    vis[node_n]=1;
    ll chcnt=0,an=1,l_invpart=1,all_chcnt=0;

    for(auto o: adj[node_n]){
        if(!vis[o]){
            par[o]=node_n;
            ll l_an=dfss(adj,vis,o,nos,invpart,allchildn,par);
            an*=l_an;an%=t9p7;
            chcnt++;
            l_invpart*=inv_fac[allchildn[o]+1];l_invpart%=t9p7;
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
    invpart[node_n]=l_invpart;

    ll this_nos=1;
    this_nos*=fac[allchildn[node_n]];this_nos%=t9p7;
    this_nos*=l_invpart;this_nos%=t9p7;
    this_nos*=an;this_nos%=t9p7;
    nos[node_n]=this_nos;
    return this_nos;
}
void final_calc_dfs(ll n,vector<vector<ll>> &adj,vector<ll> &vis,ll node_n,vector<ll> &nos,vector<ll> &invpart,vector<ll> &allchildn,vector<ll> &p_inc_par,vector<ll> &par){
    vis[node_n]=1;
    //cout<<node_n<<endl;
    for(auto curr_node:adj[node_n]){
        //cout<<curr_node<<endl;
        if(!vis[curr_node]){
            //calc p of parent except this node
            ll p_par_ex_this=p_inc_par[node_n];
            //cout<<"p_per_ex_this"<<p_par_ex_this<<endl;
            //removing curr node in nos of par ex this
            p_par_ex_this*=mod_inv(nos[curr_node]);p_par_ex_this%=t9p7;
            p_par_ex_this*=fac[allchildn[curr_node]+1];p_par_ex_this%=t9p7;
            p_par_ex_this*=inv_fac[n-1];p_par_ex_this%=t9p7;
            p_par_ex_this*=fac[n-1-allchildn[curr_node]-1];p_par_ex_this%=t9p7;
            //cout<<"after remov this"<<endl;
            //calculate for curr node
            ll p_curr=nos[curr_node];
            p_curr*=p_par_ex_this;p_curr%=t9p7;
            //cout<<"x";
            p_curr*=inv_fac[n-1-allchildn[curr_node]];p_curr%=t9p7;
            //cout<<"y";
            p_curr*=fac[n-1];p_curr%=t9p7;
            //cout<<"z";
            p_curr*=inv_fac[allchildn[curr_node]];p_curr%=t9p7;
            //cout<<"after calc curr"<<endl;

            //p_curr*=mod_inv(2);p_curr%=t9p7;//###
            p_inc_par[curr_node]=p_curr;

            final_calc_dfs(n,adj,vis,curr_node,nos,invpart,allchildn,p_inc_par,par);
        }
    }

    //calc nos or p of parent except this node
//    ll p_ex_this=1,par_node=par[node_n];
//    for(auto o:adj[par_node]){
//        if(o!=node_n && o!=par[par_node]){
//            p_ex_this*=nos[o];p_ex_this%=t9p7;
//        }
//    }
//    p_ex_this*=p_inc_par[par_node];
//

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

    ll lvla,ind=1;
    vector<ll> vis(n+1),nos(n+1),invpart(n+1),allchildn(n+1),p_inc_par(n+1),par(n+1);
    for(ll xx=0;xx<=n;xx++){vis[xx]=0;invpart[xx]=0;allchildn[xx]=0;nos[xx]=0;p_inc_par[xx]=0;par[xx]=0;}
    lvla=dfss(adj,vis,ind,nos,invpart,allchildn,par);
    ans.push_back(make_pair(lvla,ind));
    p_inc_par[ind]=lvla;
    //cout<<lvla<<endl;

    for(ll xx=0;xx<=n;xx++){vis[xx]=0;}
    vis[1]=1;
    p_inc_par[1]=nos[1];
    final_calc_dfs(n,adj,vis,ind,nos,invpart,allchildn,p_inc_par,par);

    for(ll ii=2;ii<=n;ii++){
        //ll bhs=p_inc_par[ii]&1?(p_inc_par[ii]+t9p7)/2:p_inc_par[ii]/2;
        ans.push_back(make_pair(p_inc_par[ii],ii));
    }

//    for(auto hh:ans){
//        cout<<hh.first<<" "<<hh.second<<endl;
//    }cout<<endl;

    //answering
    sort(ans.begin(),ans.end());

//    for(auto hh:ans){
//        cout<<hh.first<<" "<<hh.second<<endl;
//    }cout<<endl;

    if(k==1){
        cout<<ans[n-1].second<<" "<<ans[n-1].first<<endl;
    }else{
        cout<<ans[n-2].second<<" "<<ans[n-2].first<<endl;
    }

}

int cc_main() {
    precalc();
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}