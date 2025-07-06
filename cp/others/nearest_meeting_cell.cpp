//
// Created by me on 16-12-2021.
//

#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define FR_IR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FR_AU(xx,xxs) for(auto (xx):(xxs))
#define W_(n) while((n)--)
#define O_ cout<<
#define I_ cin>>
#define EL endl;
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef queue<ll> qll;
const ll t9p7=1000000007;



class graph_adjl_unweighted{
    vvll adjl;
    ll n,m;
public:
    graph_adjl_unweighted(ll n,ll m){
        this->m=m;
        this->n=n;
        adjl=vvll (n+1);
    }

    void add_directed_edge(ll a,ll b){
        adjl[a].push_back(b);
    }

    /*
     * To find shortest meet point between two node
     */

    ll bfs_shortest_node(ll s,ll to){
        ll ans=LONG_LONG_MAX;
        qll q1,q2;
        vector<bool> vis1(n+1,0),vis2(n+1,0);
        vll d1(n+1,0),d2(n+1,0);

        q1.push(s);
        vis1[s]=1;
        while(!q1.empty()){
            ll cur_v=q1.front();
            q1.pop();
            FR_AU(xd,adjl[cur_v]){
                if(!vis1[xd]){
                    vis1[xd]=1;
                    q1.push(xd);
                    d1[xd]=d1[cur_v]+1;
                }
            }
        }


        q2.push(to);
        vis1[to]=1;
        while(!q2.empty()){
            ll cur_v=q2.front();
            q2.pop();
            FR_AU(xd,adjl[cur_v]){
                if(!vis2[xd]){
                    vis2[xd]=1;
                    q2.push(xd);
                    d2[xd]=d2[cur_v]+1;
                }
            }
        }

        ll cell;
        for(ll i=1;i<=n;i++){
            if(vis1[i] && vis2[i]){
                if(ans>=d1[i]+d2[i]){
                    cell=i;
                    ans=d1[i]+d2[i];
                }

            }
        }

        if(ans==LONG_LONG_MAX)
            cell=-1;
//        if(cell!=-1){//all cells with minimum meet distance
//            for(ll i=1;i<=n;i++) {
//                if(d1[i]+d2[i]==ans){
//                    O_ i<<" ";
//                }
//            }O_ EL
//        }
       return cell;
    }

};


void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n;
    graph_adjl_unweighted gr=graph_adjl_unweighted(n,n+1);
    FR_IR(i,1,n+1){
        I_ a;
        if(a!=-1)
            gr.add_directed_edge(i,a+1);
    }
    I_ a>>b;
    O_ gr.bfs_shortest_node(a+1,b+1)-1<<EL

}

DRIVER

/*

1 23
4 4 1 4 1
3 8 8 8 0
8 1 4 9 15
11 -1 10 15 22
22 22 22
9 2

*/