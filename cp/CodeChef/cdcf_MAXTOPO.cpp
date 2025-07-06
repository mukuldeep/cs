//
// Created by me on 9-3-2021.
//
// tree center finding code is taken from https://www.geeksforgeeks.org/find-the-node-at-the-centre-of-an-n-ary-tree/
#include <bits/stdc++.h>
#define ll long long
#define t9p7 1000000007
using namespace std;

map<int, vector<int> > tree;
bool getDiameterPath(int vertex,int targetVertex,int parent,vector<int>& path)
{
    if (vertex == targetVertex) {
        path.push_back(vertex);
        return true;
    }
    for (auto i : tree[vertex]) {
        if (i == parent)
            continue;
        if (getDiameterPath(i, targetVertex,vertex, path)) {
            path.push_back(vertex);
            return true;
        }
    }
    return false;
}
void farthestNode(int vertex, int parent,int height, int& maxHeight,int& maxHeightNode)
{
    if (height > maxHeight) {
        maxHeight = height;
        maxHeightNode = vertex;
    }
    for (auto i : tree[vertex]) {
        if (i == parent)
            continue;
        farthestNode(i, vertex,height + 1,maxHeight,maxHeightNode);
    }
}
void addedge(int a, int b)
{
    tree[a].push_back(b);
    tree[b].push_back(a);
}

vector<ll> FindCentre(int n)
{
    int maxHeight = -1;
    int maxHeightNode = -1;

    farthestNode(0, -1, 0, maxHeight,maxHeightNode);
    int leaf1 = maxHeightNode;
    maxHeight = -1;
    farthestNode(maxHeightNode,-1, 0, maxHeight,maxHeightNode);
    int leaf2 = maxHeightNode;
    vector<int> path;
    getDiameterPath(leaf1, leaf2,-1, path);
    int pathSize = path.size();

    vector<ll> cntrxx;
    if (pathSize % 2) {
        cntrxx.push_back(path[pathSize / 2]+1);
        //cout << path[pathSize / 2]<< endl;
//        if(n>1){
//            cntrxx.push_back(path[(pathSize / 2)+1]+1);
//        }else if(n>2){
//            cntrxx.push_back(path[(pathSize / 2)-1]+1);
//        }
    }
    else {
        //cout << path[pathSize / 2]<< ", "<< path[(pathSize - 1) / 2]<< endl;
        cntrxx.push_back(path[pathSize / 2]+1);
        cntrxx.push_back(path[(pathSize - 1) / 2]+1);
    }
    return cntrxx;
}

//#########


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
void soln(ll t){
    tree.clear();
    ll n,k,x,y;
    cin>>n>>k;
    vector<vector<ll>> adj(n+1);
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        addedge(x-1,y-1);
    }
//    vector<pair<ll,ll>> chldcnts;
//    for(ll i=1;i<=n;i++) {//1 to n chldcnt
//        chldcnts.push_back(make_pair(adj[i].size(),i));
//    }
//    sort(chldcnts.begin(),chldcnts.end());
//    for(ll i=0;i<n;i++){
//        cout<<i<<":"<<chldcnts[i].first<<"<="<<chldcnts[i].second<<endl;
//    }
    vector<ll> cntrexx=FindCentre(n);
    vector<pair<ll,ll>> ans;

    if(k==1){
        sort(cntrexx.begin(),cntrexx.end());
        ll index=cntrexx[cntrexx.size()-1];
        vector<ll> vis(n + 1), nos(n + 1), invpart(n + 1), allchildn(n + 1);
        for (ll xx = 0; xx <= n; xx++) {vis[xx] = 0;invpart[xx] = 0;allchildn[xx] = 0;nos[xx] = 0;}
        ll ansss = dfss(adj, vis, index, nos, invpart, allchildn);
        ansss %= t9p7;
        cout<<index<<" "<<ansss<<endl;
    }else{
        if(cntrexx.size()>1){
            sort(cntrexx.begin(),cntrexx.end());
            ll index=cntrexx[cntrexx.size()-2];
            vector<ll> vis(n + 1), nos(n + 1), invpart(n + 1), allchildn(n + 1);
            for (ll xx = 0; xx <= n; xx++) {vis[xx] = 0;invpart[xx] = 0;allchildn[xx] = 0;nos[xx] = 0;}
            ll ansss = dfss(adj, vis, index, nos, invpart, allchildn);
            ansss %= t9p7;
            cout<<index<<" "<<ansss<<endl;
        }else{//look for all the child node for larger no of child
            vector<pair<ll,ll>> alladj;
            for(auto ch:adj[cntrexx[0]]){
                alladj.push_back(make_pair(adj[ch].size(),ch));
            }
            sort(alladj.begin(),alladj.end());
            ll index=alladj[alladj.size()-1].second;
            vector<ll> vis(n + 1), nos(n + 1), invpart(n + 1), allchildn(n + 1);
            for (ll xx = 0; xx <= n; xx++) {vis[xx] = 0;invpart[xx] = 0;allchildn[xx] = 0;nos[xx] = 0;}
            ll ansss = dfss(adj, vis, index, nos, invpart, allchildn);
            ansss %= t9p7;
            cout<<index<<" "<<ansss<<endl;

        }
    }

//    if(cntrexx.size()==1){
//        for(auto ff:adj[cntrexx[0]]){
//            cntrexx.push_back(ff);
//        }
//    }
//    for(auto index:cntrexx) {
//        vector<ll> vis(n + 1), nos(n + 1), invpart(n + 1), allchildn(n + 1);
//        for (ll xx = 0; xx <= n; xx++) {vis[xx] = 0;invpart[xx] = 0;allchildn[xx] = 0;nos[xx] = 0;}
//        ll ansss = dfss(adj, vis, index, nos, invpart, allchildn);
//        ansss %= t9p7;
//        //cout << index << " " << ansss << endl;
//        ans.push_back(make_pair(ansss,index));
//    }
//    sort(ans.begin(),ans.end());
//
////    for(ll i=0;i<n;i++){
////        cout<<ans[i].first<<" "<<ans[i].second<<endl;
////    }
//
//    if(k==1){
//        cout<<ans[ans.size()-1].second<<" "<<ans[ans.size()-1].first<<endl;
//    }else{
//        cout<<ans[ans.size()-2].second<<" "<<ans[ans.size()-2].first<<endl;
//    }


    /*
    vector<pair<ll,ll>> ans;
    ll lvla;
    for(ll i=1;i<=n;i++){//1 to n
        vector<ll> vis(n+1),nos(n+1),invpart(n+1),allchildn(n+1);
        for(ll xx=0;xx<=n;xx++){vis[xx]=0;invpart[xx]=0;allchildn[xx]=0;nos[xx]=0;}
        lvla=dfss(adj,vis,i,nos,invpart,allchildn);
//        print_v(nos,"nos");
//        print_v(invpart,"invpart");
//        print_v(allchildn,"allchildn");

        ans.push_back(make_pair(lvla,i));
    }
    sort(ans.begin(),ans.end());

//    for(ll i=0;i<n;i++){
//        cout<<ans[i].first<<" "<<ans[i].second<<endl;
//    }

    if(k==1){
        cout<<ans[n-1].second<<" "<<ans[n-1].first<<endl;
    }else{
         cout<<ans[n-2].second<<" "<<ans[n-2].first<<endl;
    }
     */

}
void test(){
    for(ll i=0;i<24;i++)
    cout<<i<<":"<<inv_fac[i]<<endl;
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



