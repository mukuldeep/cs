//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void prnt(ll p[8][8]){
    for(ll i=0;i<8;i++){
        for(ll j=0;j<8;j++) {
            cout << p[i][j];
        }
           cout<<endl;
    }
    cout<<endl;
}
ll cnt_poss(ll p[8][8],ll n){
//    prnt(p);
    if(n==7){
//        prnt(p);
        ll lcnt=0;
        for(ll i=0;i<8;i++){
            if(p[7][i]==0)
                lcnt++;
        }
        return lcnt;
    }
    ll cnt=0;
    for(ll j=0;j<8;j++){
        if(p[n][j]==0){
            for(ll y=n;y<8;y++)
                if(p[y][j]!=-1)p[y][j]++;
            for(ll y=n,x=j;x<8 && y<8;x++,y++)
                if(p[y][x]!=-1)p[y][x]++;
            for(ll y=n,x=j;x>=0 && y<8;x--,y++)
                if(p[y][x]!=-1)p[y][x]++;
            cnt+=cnt_poss(p,n+1);
            for(ll x=n;x<8;x++)
                if(p[x][j]!=-1)p[x][j]--;
            for(ll y=n,x=j;x<8 && y<8;x++,y++)
                if(p[y][x]!=-1)p[y][x]--;
            for(ll y=n,x=j;x>=0 && y<8;x--,y++)
                if(p[y][x]!=-1)p[y][x]--;
        }
    }
    return cnt;
}
void soln(ll t){
    ll p[8][8]={0};
    ll n,i,j;
    string str;
    for(i=0;i<8;i++){
        cin>>str;
        for(j=0;j<8;j++) {
            if (str[j] == '*')
                p[i][j] = -1;
//            cout << p[i][j];
        }
//        cout<<endl;
    }
    cout<<cnt_poss(p,0)<<endl;

}

int cc_main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



