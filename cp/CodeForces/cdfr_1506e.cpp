//
// Created by me on 26-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void soln(ll t){
    ll n,a;
    cin>>n;

    vector<ll> vis(n+1,0),fxpos(n+1,0),arr,mx,st;
    queue<ll> arrstr;
    ll last_big=0;
    for(ll i=1;i<=n;i++){
        cin>>a;
        if(!vis[i] && a!=i){
            arrstr.push(i);
        }
        if(!vis[a]){
            vis[a]=1;
            cout<<a<<" ";
            mx.push_back(a);
            for(ll pp=last_big+1;pp<a;pp++){
                if(!vis[pp])
                    st.push_back(pp);
            }
            last_big=a;
        }else{
            cout<<arrstr.front()<<" ";
            arrstr.pop();
            mx.push_back(st.back());
            st.pop_back();
        }
    }
    cout<<endl;
    for(ll oo=0;oo<n;oo++){
        cout<<mx[oo]<<" ";
    }cout<<endl;

}

int cc_main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



/*

5
7
3 3 4 4 7 7 7
4
1 2 3 4
7
3 4 5 5 5 7 7
1
1
7
7 7 7 7 7 7 7

 */