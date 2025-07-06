//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void soln(ll t){
    ll n;
    ll ga=0,gg=0,gt=0,gc=0;
    string str;
    cin>>str;
    n=str.length();


    ll la=0,lg=0,lt=0,lc=0;
    switch (str[0]) {
        case 'A':la++;
            break;
        case 'G':lg++;
            break;
        case 'T':lt++;
            break;
        case 'C':lc++;
            break;

    }
    for(ll i=1;i<n;i++){

        if(str[i]!=str[i-1]) {
            switch (str[i - 1]) {
                case 'A':
                    ga = la > ga ? la : ga;
                    la = 0;
                    lg = 0;
                    lt = 0;
                    lc = 0;
                    break;
                case 'G':
                    gg = lg > gg ? lg : gg;
                    la = 0;
                    lg = 0;
                    lt = 0;
                    lc = 0;
                    break;
                case 'T':
                    gt = lt > gt ? lt : gt;
                    la = 0;
                    lg = 0;
                    lt = 0;
                    lc = 0;
                    break;
                case 'C':
                    gc = lc > gc ? lc : gc;
                    la = 0;
                    lg = 0;
                    lt = 0;
                    lc = 0;
                    break;
            }
        }
        switch (str[i]) {
            case 'A':la++;
                break;
            case 'G':lg++;
                break;
            case 'T':lt++;
                break;
            case 'C':lc++;
                break;
        }

    }
    gc = lc > gc ? lc : gc;
    gt = lt > gt ? lt : gt;
    ga = la > ga ? la : ga;
    gg = lg > gg ? lg : gg;
    cout<<max(ga,max(gt,max(gc,gg)))<<endl;
}

int cc_main() {
        soln(0);
    return 0;
}



