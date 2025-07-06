//
// Created by me on 13-3-2021.
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

ll soln(ll t){
    ll n,m,x,y;
    vector<ll> initial,vis;
    unordered_set<ll> final;
    vector<pair<ll,ll>> from,to;
    multiset<pair<ll,ll>> fir_ranges;
    vector<pair<ll,ll>> fir_range;
    ll a,b,c,d;

    cin>>n>>m>>x>>y;
    ll path_len=0;
    vis.assign(m+5,0);
    for(ll i=0;i<m;i++){
        cin>>a>>b>>c>>d;
        if(a<=x && x<=b)
            initial.push_back(i);
        if(c<=y && y<=d)
            final.insert(i);
        from.push_back(make_pair(a,b));
        to.push_back(make_pair(c,d));
        fir_range.push_back(make_pair(a,i));
        fir_range.push_back(make_pair(b,i));
    }
//    print_v(initial);
//    print_v(final);
//    print_v(from);
//    print_v(to);
//    print_v(fr);
//    print_v(fir_range);
    if(x==y)return 0;
    if(initial.empty() || final.empty())return -1;

    sort(fir_range.begin(),fir_range.end());

    stack<ll> qu1;
    //set<pair<ll,ll>> st1,st2;
    path_len = 1;
    for (auto o:initial) {
        qu1.push(o);
        vis[o] = 1;
        if (final.find(o) != final.end()) {
            return path_len;
        }
    }

    set<ll> next_sec_index;
    //sort(fir_range.begin(),fir_range.end());

    while(!(qu1.empty())){//not present in initial points. so path length>0

        path_len++;
        //iterating for all element in qu1
        while(!(qu1.empty())){
            vis[qu1.top()]=1;
            auto l_bound=lower_bound(fir_range.begin(),fir_range.end(),make_pair(to[qu1.top()].first,LONG_LONG_MIN));
            auto u_bound=upper_bound(fir_range.begin(),fir_range.end(),make_pair(to[qu1.top()].second,LONG_LONG_MAX));
            for(auto itr_xx=l_bound;itr_xx!=u_bound && itr_xx!=fir_range.end();itr_xx++){
                if(!vis[(*itr_xx).second]) {
                    vis[(*itr_xx).second]=1;
                    next_sec_index.insert((*itr_xx).second);
                    if (final.find((*itr_xx).second)!=final.end()) {
                        return path_len;
                    }
                }
            }

            //full
            ll end_elem_n=fir_range.end()-u_bound;
            ll pre_elem_n=l_bound-fir_range.begin();
            ll rangef=to[qu1.top()].first;
            ll ranges=to[qu1.top()].second;

            //if(end_elem_n>pre_elem_n){
                for(auto itr_f=fir_range.begin();itr_f!=l_bound;itr_f++){
                    if(!vis[(*itr_f).second]) {
                        if(from[(*itr_f).second].first<rangef && from[(*itr_f).second].second>ranges){
                            vis[vis[(*itr_f).second]]=1;
                            next_sec_index.insert((*itr_f).second);
                            if(final.find((*itr_f).second)!=final.end()) {
                                return path_len;
                            }
                        }
                    }
                }

//            }else{
//
//            }


            fir_range.erase(l_bound,u_bound);
            qu1.pop();
        }

        for(auto ggg:next_sec_index){
            qu1.push(ggg);
        }
        next_sec_index.clear();
    }

    //output
    return -1;
//    if(found){
//        cout<<path_len<<endl;
//    }else{
//        cout<<-1<<endl;
//    }
    //cout<<"###"<<endl;


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
void test(){
    multiset<int> s;

    // Function to insert elements
    // in the multiset container
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(1);
    s.insert(4);

    cout << "The multiset elements are: ";
    for (auto it = s.begin(); it != s.end(); it++)
        cout << *it << " ";

    // when 2 is present
    auto it = s.lower_bound(2);
    cout << "\nThe lower bound of key 2 is ";
    cout << (*it) << endl;

    // when 3 is not present
    // points to next greater after 3
    it = s.lower_bound(3);
    cout << "The lower bound of key 3 is ";
    cout << (*it) << endl;

    // when 5 exceeds the max element in multiset
    it = s.lower_bound(7);
    cout << "The lower bound of key 7 is ";
    cout << (*it) << endl;

}

void test2(){
    vector<pair<ll,ll>> fir_range;
    fir_range.push_back(make_pair(12,112));
    fir_range.push_back(make_pair(1,320));
    fir_range.push_back(make_pair(2,0));
    fir_range.push_back(make_pair(4,47));
    fir_range.push_back(make_pair(5,45));
    fir_range.push_back(make_pair(5,46));
    fir_range.push_back(make_pair(4,45));
    fir_range.push_back(make_pair(22,2));
    fir_range.push_back(make_pair(20,32));
    fir_range.push_back(make_pair(20,32));
    fir_range.push_back(make_pair(1,32));
    fir_range.push_back(make_pair(32,92));
    fir_range.push_back(make_pair(10,90));

    for(auto xx:fir_range){
        cout<<xx.first<<" "<<xx.second<<endl;
    }cout<<endl;

    sort(fir_range.begin(),fir_range.end());

    for(auto xx:fir_range){
        cout<<xx.first<<" "<<xx.second<<endl;
    }cout<<endl;

    vector<pair<ll,ll>> todel;
    todel.push_back(make_pair(2,5));
    todel.push_back(make_pair(4,10));
    todel.push_back(make_pair(33,34));
    todel.push_back(make_pair(32,32));

    for(auto yy:todel) {
        cout<<"to del "<<yy.first<<" to "<<yy.second<<endl;
        auto l_bound = lower_bound(fir_range.begin(), fir_range.end(), make_pair(yy.first, LONG_LONG_MIN));
        auto u_bound = upper_bound(fir_range.begin(), fir_range.end(), make_pair(yy.second, LONG_LONG_MAX));
        for (auto itr_xx = l_bound; itr_xx != u_bound && itr_xx != fir_range.end(); itr_xx++) {
            cout << (*itr_xx).first << " " << (*itr_xx).second << endl;
        }
        cout << endl;

        fir_range.erase(l_bound, u_bound);
        cout<<"after deleteion"<<endl;
        for (auto xx:fir_range) {
            cout << xx.first << " " << xx.second << endl;
        }
        cout << endl;

    }
}
int cc_main() {
    //test2();
    ll t;
    cin>>t;
    while(t--) {
        cout<<soln(t)<<endl;
    }
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
5 3 1 2
4 5 2 3
1 2 4 5
5 5 2 3

 1
20 3 1 10
4 4 2 3
1 2 4 5
5 5 3 4
 */