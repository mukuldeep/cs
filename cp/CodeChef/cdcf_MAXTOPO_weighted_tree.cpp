//
// Created by me on 13-3-2021.
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

ll dfssxx(vector<vector<ll>> &adj,vector<ll> &vis,ll node_n,vector<ll> &nos,vector<ll> &invpart,vector<ll> &allchildn){
    vis[node_n]=1;
    ll chcnt=0,an=1,l_invpart=1,all_chcnt=0;

    for(auto o: adj[node_n]){
        if(!vis[o]){
            ll l_an=dfssxx(adj,vis,o,nos,invpart,allchildn);
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


ll ini_child_cnt(ll n, vector<vector<ll>> &adj,ll curr_node,vector<ll> &ini_vis,vector<ll> &ini_cnt,vector<ll> &max_of_ch,vector<ll> &parent){
    ini_vis[curr_node]=1;
    ll allchcnt=0,max_ch=0;
    for(auto ch:adj[curr_node]){
        if(!ini_vis[ch]){
            ll xxg=ini_child_cnt(n,adj,ch,ini_vis,ini_cnt,max_of_ch,parent);
            allchcnt+=xxg;
            parent[ch]=curr_node;
            max_ch=max(max_ch,xxg);
        }
    }

    max_of_ch[curr_node]=max_ch;
    return ini_cnt[curr_node]=allchcnt+1;
}
void simp(ll n,ll k){
    ll x,y;
    vector<vector<ll>> adj(n+1);
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<pair<ll,ll>> ans;
    ll lvla;
    for(ll i=1;i<=n;i++){//1 to n
        vector<ll> vis(n+1),nos(n+1),invpart(n+1),allchildn(n+1);
        for(ll xx=0;xx<=n;xx++){vis[xx]=0;invpart[xx]=0;allchildn[xx]=0;nos[xx]=0;}
        lvla=dfssxx(adj,vis,i,nos,invpart,allchildn);

        ans.push_back(make_pair(lvla,i));
    }
    sort(ans.begin(),ans.end());
    if(k==1){
        cout<<ans[n-1].second<<" "<<ans[n-1].first<<endl;
    }else{
        cout<<ans[n-2].second<<" "<<ans[n-2].first<<endl;
    }

}
void soln(ll t){
    ll n,k,x,y;
    cin>>n>>k;
    if(n<=10){
        simp(n,k);
        return;
    }
    vector<vector<ll>> adj(n+1);
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<ll> ini_cnt,ini_vis,max_of_ch,parent;
    ini_cnt.assign(n+1,0);
    ini_vis.assign(n+1,0);
    max_of_ch.assign(n+1,0);
    parent.assign(n+1,0);
    ini_child_cnt(n,adj,1,ini_vis,ini_cnt,max_of_ch,parent);

    vector<ll> f_index;
    ll hf=n/2;
    for(ll i=1;i<=n;i++){
        if(max_of_ch[i]<=hf && ini_cnt[i]>hf){
            f_index.push_back(i);
        }
    }

    sort(f_index.begin(),f_index.end());

//    for(auto o:f_index){
//        cout<<o<<" f ";
//    }cout<<endl;

    ll node_index;
    if(k==1){
        node_index=f_index[f_index.size()-1];
    }else{
        if(f_index.size()>1){
            node_index=f_index[f_index.size()-2];
        }else{
            vector<pair<ll,ll>> adjacents;
            for(auto ad:adj[f_index[0]]){
                if(ad==parent[f_index[0]]){
                    adjacents.push_back(make_pair(n-ini_cnt[f_index[0]],ad));
                }else{
                    adjacents.push_back(make_pair(ini_cnt[ad],ad));
                }
            }
            sort(adjacents.begin(),adjacents.end());
//            for(auto o:adjacents){
//                cout<<o.first<<"=>"<<o.second<<" ";
//            }cout<<endl;

            node_index=adjacents[adjacents.size()-1].second;
        }
    }


    vector<ll> vis(n+1),nos(n+1),nos_ch(n+1),invpart(n+1),allchildn(n+1);
    for(ll xx=0;xx<=n;xx++){vis[xx]=0;invpart[xx]=0;allchildn[xx]=0;nos[xx]=0;nos_ch[xx]=0;}
    ll lvla=dfssxx(adj,vis,node_index,nos,invpart,allchildn);
    cout<<node_index<<" "<<lvla<<endl;


}
void test(){
    vector<ll> tes;
    tes.push_back(12);
//    tes.push_back(10);
//    tes.push_back(10);
//    tes.push_back(10);
//    tes.push_back(1);


//    cout<<findMindiff(tes)<<endl;
}
int cc_main() {
    precalc();
    //test();
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



