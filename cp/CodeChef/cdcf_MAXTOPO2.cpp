//
// Created by me on 8-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define t9p7 1000000007
using namespace std;
ll fac[500005]={0};
void precalc(){
    fac[0]=1;
    for(ll i=1;i<500002;i++){
        fac[i]=(fac[i-1]*i)%t9p7;
    }
}
ll calc_child_val(vector<ll> &child_val,vector<vector<ll>> &child,ll node_n){
    if(child[node_n].empty())
        return child_val[node_n]=1;
    ll val=fac[child[node_n].size()], lval;
    for(auto o:child[node_n]){
        lval=calc_child_val(child_val,child,o);
        val*=lval;
        val%=t9p7;
    }
    return child_val[node_n]=val;
}
void calc_sib_par_val(vector<ll> &child_val,vector<vector<ll>> &child,ll par_node_n,vector<ll> &sib_par_val,vector<ll> &par){
    for(auto node:child[par_node_n]){
        ll lvl=1;
        for(auto sib:child[par_node_n]){
            if(sib!=node){
                lvl*=child_val[node];lvl%=t9p7;
            }
        }
        lvl*=sib_par_val[par_node_n];lvl%=t9p7;
        if(par_node_n!=1) {
            lvl *= fac[child[par_node_n].size()];lvl %= t9p7;
        }else {
            lvl *= fac[child[par_node_n].size() - 1];lvl %= t9p7;
        }
        sib_par_val[node]=lvl;
    }
    for(auto node:child[par_node_n]){
        calc_sib_par_val(child_val,child,node,sib_par_val,par);
    }
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

    //children calc
    vector<vector<ll>> child(n+1);
    vector<ll> vis,par(n+1);
    stack<ll> st;
    vis.assign(n+1,0);

    child[1]=adj[1];
    par[1]=0;
    vis[1]=1;
    for(auto o:child[1]){
        st.push(o);
        par[o]=1;
    }
    while(!st.empty()){
        ll curr=st.top();
        vis[curr]=1;
        st.pop();
        for(auto o:adj[curr]){
            if(!vis[o]){
                child[curr].push_back(o);
                par[o]=curr;
                st.push(o);
            }
        }
    }


    //calculate child value dfs
    vector<ll> child_val(n+1);
    calc_child_val(child_val,child,1);

    //calculating siblings and parents
    vector<ll> sib_par(n+1);
    sib_par[1]=1;
    calc_sib_par_val(child_val,child,1,sib_par,par);

    //calculating
    vector<ll> cst(n+1);
    //vector<pair<ll,ll>> ans;
    cst[1]=child_val[1];
    //ans.push_back(make_pair(cst[1],1));
    for(ll i=2;i<=n;i++){
        cst[i]=(child_val[i]*sib_par[i])%t9p7;
        cst[i]*=(child[i].size()+1);cst[i]%=t9p7;
        //ans.push_back(make_pair(cst[i],i));
    }
    //sort(ans.begin(),ans.end());
    ll lar=LONG_LONG_MIN,lar_i=0,lar_2=LONG_LONG_MIN,lar_2_i=0;
    for(ll i=1;i<=n;i++){
        if(cst[i]>=lar){
            lar=cst[i];
            lar_i=i;
        }
    }
    if(k==1){
        cout<<lar_i<<" "<<lar<<endl;
    }else{
        for(ll i=1;i<=n;i++){
            if(cst[i]>=lar_2 && i!=lar_i){
                lar_2=cst[i];
                lar_2_i=i;
            }
        }
        if(lar_2_i>0 && lar_2>0)
            cout<<lar_2_i<<" "<<lar_2<<endl;
        else
            cout<<"1 1"<<endl;
    }

//    if(k==1){
//        cout<<ans[n-1].second<<" "<<ans[n-1].first<<endl;
//    }else{
//        cout<<ans[n-2].second<<" "<<ans[n-2].first<<endl;
//    }

}

int cc_main() {
    precalc();
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



