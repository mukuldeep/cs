//
// Created by me on 25-02-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void soln(){
    ll duration,intersections,nstreet,nvehicals,point;
    cin>>duration>>intersections>>nstreet>>nvehicals>>point;
    unordered_map<string,pair<pair<ll,ll>,ll>> streets;

    ll STRT,END,TIME;
    string NAME;
    for(ll i=0;i<nstreet;i++){
        cin>>STRT>>END>>NAME>>TIME;
        streets[NAME]=make_pair(make_pair(STRT,END),TIME);
    }

    vector<vector<string>> vehicles;
    ll NSTREETS;
    string NAMESTREET;
    for(ll i=0;i<nvehicals;i++){
        cin>>NSTREETS;
        vector<string> vehicle;
        ll total_duration=0;

        cin>>NAMESTREET;
        vehicle.push_back(NAMESTREET);
        for(ll j=1;j<NSTREETS;j++){
            cin>>NAMESTREET;
            total_duration+=(streets[NAMESTREET].second)+1;
            vehicle.push_back(NAMESTREET);
        }
        //if(total_duration<=duration){
            vehicles.push_back(vehicle);
        //}
    }

//    //<sim>
//
//    ll vcl_delays[1004]={0};
//    ll intersection_delay[100004]={0};
//    for(ll yui=0;yui<100004;yui++){
//        intersection_delay[yui]=duration;
//    }
//ll loop=5;
//while(loop--) {
//    ll intersection_q[100004] = {0};
//    for (ll timeline = 0; timeline < duration; timeline++) {
//        ll vclno = 0;
//        for (auto vv:vehicles) {
//            ll l_timeline = 0;
//            for (auto name_street:vv) {
//                l_timeline += streets[name_street].second;
//                if ((vcl_delays[vclno] + l_timeline) == timeline) {
//                    intersection_q[streets[name_street].first.second]++;
//                    vcl_delays[vclno]++;
//                } else if ((vcl_delays[vclno] + l_timeline) > timeline) {
//                    break;
//                }
//            }
//            vclno++;
//        }
//
//        for (ll oop = 0; oop < intersections; oop++) {
//            if (intersection_q[oop] > 0) {
//                intersection_q[oop]--;
//                intersection_delay[oop] = min(intersection_delay[oop], intersection_q[oop]);
//            }
//        }
//    }
//}


    //</sim>
// answer calc
    //          id       incoming_name
    unordered_map<ll,set<string>> out;
    for(auto vv:vehicles){
        for(auto name_street:vv){
            out[streets[name_street].first.second].insert(name_street);
        }
    }

//answer out

    ll timing;
    cout<<out.size()<<endl;
    for(auto intersec:out){
        cout<<intersec.first<<endl;
        cout<<intersec.second.size()<<endl;
        timing=1;
        if(intersec.second.size()==1)timing=duration;
        else{
            timing=1+((duration/intersec.second.size())*2)/3+intersec.second.size()/100;
        }

//            if(intersec.second.size()<3){
//            if(duration<3){
//                timing=1;
//            }
//        }else if(intersec.second.size()<5){
//            if(duration<4){
//                timing=3;
//            }
//        }
        for(auto outstr:intersec.second) {
            cout << outstr << " " << timing << endl;
        }
    }

}

int cc_main() {
    //ifstream cin("./inout/input.txt");
    //ofstream cout("./inout/output.txt");
    freopen("./inout/a_output.txt", "a", stdout);
    freopen("./inout/a.txt", "r", stdin);
    soln();
    freopen("./inout/b_output.txt", "a", stdout);
    freopen("./inout/b.txt", "r", stdin);
    soln();
    freopen("./inout/c_output.txt", "a", stdout);
    freopen("./inout/c.txt", "r", stdin);
    soln();
    freopen("./inout/d_output.txt", "a", stdout);
    freopen("./inout/d.txt", "r", stdin);
    soln();
    freopen("./inout/e_output.txt", "a", stdout);
    freopen("./inout/e.txt", "r", stdin);
    soln();
    freopen("./inout/f_output.txt", "a", stdout);
    freopen("./inout/f.txt", "r", stdin);
    soln();
    return 0;
}