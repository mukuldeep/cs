//
// Created by me on 26-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define t9p7 1000000007
using namespace std;


void soln(ll t){
    cout<<"Case #"<<t<<": ";
    ll cj,jc;
    string str;
    cin>>cj>>jc;
    cin>>str;

    //first valid str
    ll fir_pos=-1;
    char fir_ch;
    for(ll i=0;i<str.length();i++){
        if(str[i]!='?'){
            fir_ch=str[i];
            fir_pos=i;
            break;
        }
    }

    ll cost=0;
    if(cj+jc>=0){
        if(fir_pos==-1) {
            cout << "0\n";
            return;
        }
        char pre=fir_ch;
        for(auto ch:str){
            if(ch=='C'){
                if(pre=='J'){
                    cost+=jc;
                    pre='C';
                }
            }else if(ch=='J'){
                if(pre=='C'){
                    cost+=cj;
                    pre='J';
                }
            }
        }
    }else {
        char pre;

        ll is_last = str[str.length() - 1] == '?';
        if (fir_pos==-1){
            if(cj<jc){
                pre='C';
                str[0]=pre;
            }else{
                pre='J';
                str[0]=pre;
            }
        }else if(fir_pos&1){
            if(fir_ch=='C') {
                pre = 'J';
                str[0]='J';
            }else {
                pre = 'C';
                str[0]='C';
            }
        }else{
            pre=fir_ch;
            str[0]=pre;
        }

        for(ll kk=0;kk<str.length();kk++){
            char ch=str[kk];
            if(ch=='C'){
                if(pre=='J'){
                    cost+=jc;
                    pre='C';
                }
            }else if(ch=='J'){
                if(pre=='C'){
                    cost+=cj;
                    pre='J';
                }
            }else{
                if(pre=='C'){
                    cost+=cj;
                    str[kk]='J';
                    pre='J';
                }else{
                    cost+=jc;
                    str[kk]='C';
                    pre='C';
                }
            }
        }

        if(is_last){
            if(str[str.length()-1]=='C'){
                if(jc>0)cost-=jc;
            }else{
                if(cj>0)cost-=cj;
            }
        }
    }
    cout<<cost<<"\n";
}

int cc_main() {
    ll t;
    cin>>t;
    for(int i=1;i<=t;i++){
        soln(i);
    }
    return 0;
}