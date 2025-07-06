//
// Created by me on 26-03-2021.
//
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define t9p7 1000000007
using namespace std;



void soln(ll t,ll p){
    freopen("./inout/cheating_detection_sample_ts1_input.txt", "r", stdin);
    cout<<"Case #"<<t<<": ";
    string str;

    ld uniformity[100]={0},distribution[100]={0};
    ll correct_no_stud[10000]={0},wrong_no_stud[10000]={0},correct_q_no[100];
    vector<vector<ll>> correct_stud(10000),wrong_stud(10000);


    for(int i=0;i<100;i++) {
        cin >> str;
        ll no_of_correct=0,total_ind_sum=0;
        ll cont=0;char prech='1';
        for(ll hh=0;hh<10000;hh++){
            if(str[hh]=='1'){
                no_of_correct++;
                total_ind_sum+=hh;
                correct_no_stud[hh]++;
                correct_stud[hh].push_back(i);
            }else{
                wrong_no_stud[hh]++;
                wrong_stud[hh].push_back(i);
            }
            uniformity[i]+=abs((ld)hh/2-no_of_correct);
            if(str[hh]==prech){
                cont++;
            }else{
                distribution[i]+=cont;
                cont=1;
            }
            prech=str[hh];

        }
        correct_q_no[i]=no_of_correct;
    }

    //by no of student gave the answer correct###############
    vector<pair<ll,ll>> correct_no_stud_sort,wrong_no_stud_sort;
    for(ll oo=0;oo<10000;oo++){
        if(correct_no_stud[oo])
        correct_no_stud_sort.push_back(make_pair(correct_no_stud[oo],oo));
        if(wrong_no_stud[oo])
        wrong_no_stud_sort.push_back(make_pair(wrong_no_stud[oo],oo));
    }
    sort(correct_no_stud_sort.begin(),correct_no_stud_sort.end());
    sort(wrong_no_stud_sort.begin(),wrong_no_stud_sort.end());
    ll score_stud_corr[100]={0},score_stud_wrong[100]={0};
    for(ll cq=0;cq<250;cq++){
        ll score_to_add=(250-cq);
        if(cq<correct_no_stud_sort.size())
        for(auto stud:correct_stud[correct_no_stud_sort[cq].second]){
            score_stud_corr[stud]+=score_to_add;
        }
        if(cq<wrong_no_stud_sort.size())
        for(auto stud:wrong_stud[wrong_no_stud_sort[cq].second]){
            score_stud_wrong[stud]+=score_to_add;
        }
    }
    vector<pair<ll,ll>> select_by_corr,select_by_wrong;
    for(ll cq=0;cq<100;cq++){
        select_by_corr.push_back(make_pair(score_stud_corr[cq],cq));
        select_by_wrong.push_back(make_pair(score_stud_wrong[cq],cq));
    }
    sort(select_by_corr.begin(),select_by_corr.end());
    sort(select_by_wrong.begin(),select_by_wrong.end());

    //by no of correct answer student gave######################
    vector<pair<ll,ll>> select_by_no_corr;
    for(ll oo=0;oo<100;oo++){
        //if(4000<correct_q_no[oo] && correct_q_no[oo]<7000){
            select_by_no_corr.push_back(make_pair(5000-abs(correct_q_no[oo]-5000),oo));
        //}
    }
    sort(select_by_no_corr.begin(),select_by_no_corr.end());

    //by uniformity score ... lower the score higher the chance
    vector<pair<ld,ll>> select_by_uniformity;
    for(ll oo=0;oo<100;oo++){
        select_by_uniformity.push_back(make_pair(uniformity[oo],oo));
    }
    sort(select_by_uniformity.begin(),select_by_uniformity.end());

    //by distribution score ... lower the score higher the chances
    vector<pair<ld,ll>> select_by_distribution;
    for(ll oo=0;oo<100;oo++){
        select_by_distribution.push_back(make_pair(distribution[oo],oo));
    }
    sort(select_by_distribution.begin(),select_by_distribution.end());


    //list making
    vector<ll> list_uniformity,list_no_corr,list_corr,list_wrong,list_dist;
    for(ll ii=99;ii>=0;ii--){
        list_no_corr.push_back(select_by_no_corr[ii].second);
        list_corr.push_back(select_by_corr[ii].second);
        list_wrong.push_back(select_by_wrong[ii].second);
    }
    for(ll ii=0;ii<100;ii++){
        list_uniformity.push_back(select_by_uniformity[ii].second);
        list_dist.push_back(select_by_distribution[ii].second);
    }

//    for(ll kk=0;kk<100;kk++){
//        cout<<list_no_corr[kk]<<" "<<list_corr[kk]<<" "<<list_wrong[kk]<<" "<<list_uniformity[kk]<<" "<<list_dist[kk]<<endl;
//    }

    ll stud_final_score[100]={0};
    for(ll ii=0;ii<100;ii++){

        stud_final_score[list_no_corr[ii]]+=(100-ii)*1;
        stud_final_score[list_corr[ii]]+=(100-ii)*2;
        stud_final_score[list_wrong[ii]]+=(100-ii)*2;
        stud_final_score[list_uniformity[ii]]+=(100-ii)*1;
        stud_final_score[list_dist[ii]]+=(100-ii)*4;
    }

    ll mx=-1,ans_stud;
    for(ll ii=0;ii<100;ii++){
        if(mx<stud_final_score[ii]){
            mx=stud_final_score[ii];
            ans_stud=ii+1;
        }
    }
    cout<<ans_stud<<endl;
}

int cc_main() {
    ll t,p;
    cin>>t>>p;
    for(int i=1;i<=t;i++){
        soln(i,p);
    }
    return 0;
}



