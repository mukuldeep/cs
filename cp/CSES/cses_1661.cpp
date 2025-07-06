
/*
 * Created by me on 05-01-2022.
 */
#include <bits/stdc++.h>
#define Dr int main(){ soln(1);return 0;}
#define Drt int cc_main(){ soln(1);return 0;}
#define F(a,c) for (ll a=0;a<c; a++)
#define O cout<<
#define I cin>>
#define El endl;
//ds
#define ll long
#define V(x) vector<x>
#define Uom(x,y) map<x,y>
using namespace std;

void pre(){

}


void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0;
    I n>>k;
    Uom(ll,ll) mp;
    F(i,n){
        I a;
        cnt+=a;
        if(mp.find(cnt-k)!=mp.end())ans+=mp.at(cnt-k);
        if(cnt==k)ans++;
        mp[cnt]++;
        //O "ans:"<<ans<<" cnt:"<<cnt<<" mp[cnt]:"<<mp[cnt-k]<<El
    }

//    Fa(xd,mp){
//        O xd.first<<" "<<xd.second<<El
//    }
    O ans<<El
}

Dr

