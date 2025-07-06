//
// Created by me on 7-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n,e,h,a,b,c;//NEHABC
    cin>>n>>e>>h>>a>>b>>c;
    ll f=0,minprice=LONG_LONG_MAX;

    for(int i=0;i<=n;i++) {
        ll local_price=c*i;
        ll avail_egg=e-i;
        ll avail_choco=h-i;
        ll left_friends=n-i;

        if(avail_choco>=0 && avail_egg>=0)
            if(left_friends==0){
                local_price=n*c;
                minprice=min(minprice,local_price);
                f=1;
            }else {
                if(a>b){
                    ll cms = avail_choco / 3;
                    if (left_friends <= cms) {
                        local_price += left_friends * b;
                        f = 1;
                        minprice = min(minprice, local_price);
                    } else if ((avail_egg / 2)+cms >= left_friends) {
                        left_friends -= cms;
                        local_price += (cms * b + left_friends * a);
                        f = 1;
                        minprice = min(minprice, local_price);
                    }
                } else {
                    ll oml = avail_egg / 2;
                    if (left_friends <= oml) {
                        local_price += left_friends * a;
                        f = 1;
                        minprice = min(minprice, local_price);
                    } else if ((avail_choco / 3)+oml >= left_friends) {
                        left_friends -= oml;
                        local_price += (oml * a + left_friends * b);
                        f = 1;
                        minprice = min(minprice, local_price);
                    }
                }
            }
    }
    if(f){
        cout<<minprice<<endl;
    }else{
        cout<<-1<<endl;
    }

}

int cc_main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



