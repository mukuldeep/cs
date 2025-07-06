//
// Created by me on 8-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int soln2(ll t){
    vector<int> numbers;
    int cnt=0;
    map<int,int> mp;
    for(auto x:numbers){
        if(mp.find(x)!=mp.end()){
            if(mp[x]==1){
                cnt++;
            }
            mp[x]++;
        }else{
            mp[x]=1;
        }
    }
    return cnt;

}

void soln3(ll t){
    string subject("Name: John Doe");
    string result;
    try {
        regex re("Name: (.*)");
        smatch match;
        if (regex_search(subject, match, re) && match.size() > 1) {
            result = match.str(1);
        } else {
            result =string("");

        }
        cout<<result<<endl;
    } catch (regex_error& e) {
        // Syntax error in the regular expression
        cout<<"error"<<endl;
    }
}
void soln4(ll t){
    string a = "GeeksForGeeks";
    string fa[]={"mukul@hackerrank.com",
                 "mukul_45@hackerrank.com",
                 "_@hackerrank.com",
                 "mukul_37845@hackerrank.com",
                 "mukul_37845@hackerrank.com",
                 "mukul7_345@hackerrank.com",
                 "mukul_3845@hackerrank.com",
                 "mukul_3845@hackerran.com",
    };
    // Here b is an object of regex (regular expression)
    regex b("(S)(.*)"); // Geeks followed by any character
    regex g("([a-z]){1,6}(_){0,1}([0-9]){0,4}(@hackerrank.com)");
    // regex_match function matches string a against regex b
    for(auto f:fa)
    if ( regex_match(f, g) )
        cout<<f<<endl;
        //cout << "String 'f' matches regular expression 'g' \n";


//    // regex_match function for matching a range in string
//    // against regex b
//    if ( regex_match(a.begin(), a.end(), b) )
//        cout << "String 'a' matches with regular expression "
//                "'b' in the range from 0 to string end\n";
}
void soln(ll t){

}
int cc_main() {
    ll t;
    t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



