//
// Created by me on 25-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> adj[100005];
bool v[100005]={false};

void bfs(ll n){
    queue<ll> qu;
    vector<ll> color(n+1,0);
    ll fg = 0;
    for(ll o=1;o<=n;o++) {
        if(v[o])continue;
        qu.push(o);
        v[o] = true;
        color[o] = 1;
        while (!qu.empty()) {
            ll curr = qu.front();
            ll curr_color = color[curr];
            ll next_color = curr_color == 1 ? 2 : 1;
            qu.pop();

            for (auto adjc:adj[curr]) {

                if (!v[adjc]) {
                    v[adjc] = true;
                    qu.push(adjc);
                    color[adjc] = next_color;
                } else {
                    if (color[adjc] == curr_color) {
                        fg = 1;
                        break;
                    }
                }
            }
        }
        if(fg)break;
    }

    if(!fg){
        for(ll i=1;i<=n;i++){
            cout<<color[i]<<" ";
        }cout<<endl;
    }else{
        cout<<"IMPOSSIBLE\n";
    }
}
void soln(ll t){
    ll n,m,a,b;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(n);
}

int main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



