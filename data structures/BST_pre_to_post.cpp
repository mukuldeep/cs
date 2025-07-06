//
// Created by mukul on 2-11-2020.
//
#include <bits/stdc++.h>
using namespace std;


void bst_pre_to_post(int pre[],int pre_start,int pre_end){
        if(pre_start>pre_end)return;
        int premid=lower_bound(pre+pre_start+1,pre+pre_end,pre[pre_start])-pre;

        //cout<<"pre_start:"<<pre_start<<" pre_end:"<<pre_end<<" premid:"<<premid<<endl;
        bst_pre_to_post(pre,pre_start+1,premid-1);
        bst_pre_to_post(pre,premid,pre_end);
        cout<<pre[pre_start]<<" ";
}

int cc_main() {

    int size=10;
    int pre[]={6,2,1,4,3,5,8,7,9,10};
    bst_pre_to_post(pre,0,size-1);

    return 0;
}

