//
// Created by me on 03-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,m,x,cnt,a,index;
    vector<ll> tkct,pre,post,v;
    vector<ll>::iterator pos;
    cin>>n>>m;
    v.assign(n,0);
    for(ll i=0;i<n;i++){
        cin>>a;
        tkct.push_back(a);
        pre.push_back(i);
        post.push_back(i);
    }

    sort(tkct.begin(),tkct.end());
    for(ll i=0;i<m;i++) {
        cin >> a;
        if(tkct.size()==0){
            cout<<-1<<endl;
            continue;
        }
        pos=lower_bound(tkct.begin(),tkct.end(),a);
        if(pos==tkct.begin()){
            if(*pos<=a && !v[pos-tkct.begin()]){
                    cout << *pos << endl;
                    pre[pos - tkct.begin()] == -1;
                    v[pos - tkct.begin()] = 1;
            }else {
                cout << -1 << endl;
            }
        }else{
            if(*pos!=a)
                pos--;
            cout<<*pos<<endl;
            tkct.erase(pos);
        }

    }

}

int cc_main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



