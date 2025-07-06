//
// Created by me on 5-3-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void print_v(vector<ll> v){
    for(auto o:v)
        cout<<o<<" ";
    cout<<endl;
}
void print_v(set<ll> v){
    for(auto o:v)
        cout<<o<<" ";
    cout<<endl;
}
void print_v(vector<pair<ll,ll>> v){
    for(auto o:v)
        cout<<o.first<<","<<o.second<<" ";
    cout<<endl;
}
void print_v(set<pair<ll,ll>> v){
    for(auto o:v)
        cout<<o.first<<","<<o.second<<" ";
    cout<<endl;
}
void print_v(multiset<pair<ll,ll>> v){
    for(auto o:v)
        cout<<o.first<<","<<o.second<<" ";
    cout<<endl;
}

void soln(ll t){
    ll n,m,x,y;
    vector<ll> initial,vis;
    set<ll> final;
    vector<pair<ll,ll>> from,to;
    multiset<pair<ll,ll>> fr;

    ll a,b,c,d;

    cin>>n>>m>>x>>y;
    vis.assign(m+1,0);

    for(ll i=0;i<m;i++){
        cin>>a>>b>>c>>d;
        if(x<=b && x>=a)
            initial.push_back(i);
        if(y<=d && y>=c)
            final.insert(i);
        from.push_back(make_pair(a,b));
        to.push_back(make_pair(c,d));
        fr.insert(make_pair(a,i));
        fr.insert(make_pair(b,i));
    }
//    print_v(initial);
//    print_v(final);
//    print_v(from);
//    print_v(to);
//    print_v(fr);
    queue<ll> qu1,qu2;
    set<pair<ll,ll>> st1,st2;
    for(auto o:initial){
        qu1.push(o);

    }

//    ll path_len=0,f=1;
//    queue<ll> aq,bq;
//
//    for(auto o:initial){
//        aq.push(o);
//    }
//    while(f){
//        path_len++;
//        while (!aq.empty()){
//            ll r_l,r_r,curr_i;
//            multiset<pair<ll,ll>>::iterator r_li,r_ri;
//            curr_i=aq.front();
//            r_li=fr.lower_bound(make_pair(to[curr_i].first,-1));
//            if((*r_li).first!=to[curr_i].first)r_li++;
//            r_ri=fr.upper_bound(make_pair(to[curr_i].second,m+1));r_ri--;
//            if((*r_ri).first!=to[curr_i].second)r_ri--;
//
//            for(auto i=r_li;i!=r_ri;i++){
//                bq.push((*i).second);
//            }
//            vis[curr_i]=1;
//            aq.pop();
//            if(final.find(curr_i)!=final.end()){
//                f=0;
//                cout<<path_len<<endl;
//                break;
//            }
//        }
//        while(!bq.empty()){
//            aq.push(bq.front());
//            bq.pop();
//        }
//    }
}

int cc_main() {
    ll t;
    cin>>t;
    while(t--)
        soln(t);
    return 0;
}


/*
3
5 2 1 2
1 2 4 5
5 5 2 3
6 1 3 4
1 6 3 3
2 1 2 2
1 1 1 1

1
5 2 1 2
1 2 4 5
5 5 2 3
 */