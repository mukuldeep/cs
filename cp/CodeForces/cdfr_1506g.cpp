//
// Created by me on 25-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void soln(ll t){
    string str;
    cin>>str;
    ll len=str.length();
    vector<vector<ll>> chr(27);
    for(ll i=0;i<len;i++){
        chr[str[i]-'a'].push_back(i);
    }
    for(ll i=0;i<=26;i++){
        sort(chr[i].begin(),chr[i].end());
    }


    vector<pair<ll,char>> ans;
    ll prev=len+100;
    for(ll i=25;i>=0;i--){
        if(chr[i].size()){
            if(chr[i].size()==1){
                ans.push_back(make_pair(chr[i][0],'a'+i));
                prev=chr[i][0];
            }else{
                ll last_ind_gr_prev=-1;
                for(ll oo=chr[i].size()-1;oo>=0;oo--){
                    if(chr[i][chr[i].size()-1]>prev){
                        last_ind_gr_prev=chr[i][oo];
                        break;
                    }
                }
                if(last_ind_gr_prev==-1){
                    prev=chr[i][0];
                    ans.push_back(make_pair(prev,'a'+i));
                }else{
                    ans.push_back(make_pair(last_ind_gr_prev,'a'+i));
                }
            }
        }
    }

    sort(ans.begin(),ans.end());
    string anss="";
    for(auto tt:ans){
        anss+=tt.second;
    }
    cout<<anss<<endl;

}

int main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}



