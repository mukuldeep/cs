//
// Created by mukul on 22-10-2020.
//
#include <bits/stdc++.h>
using namespace std;

int preIndex=0;
void in_pre_to_post(int pre[],int in[],int in_start,int in_end,map<int,int> hm){
        if(in_start>in_end)return;

        int inmid=hm[pre[preIndex++]];
        in_pre_to_post(pre,in,in_start,inmid-1,hm);
        in_pre_to_post(pre,in,inmid+1,in_end,hm);
        cout<<in[inmid]<<" ";
}

void util_in_pre_to_post(int pre[],int in[],int size){
    map<int,int> hm;
    for(int i=0;i<size;i++){
        hm[in[i]]=i;
    }
    in_pre_to_post(pre,in,0,size-1,hm);
}

int cc_main() {

    int size=10;
    int in[]={4,2,8,5,9,1,6,3,7,10};
    int pre[]={1,2,4,5,8,9,3,6,7,10};

    util_in_pre_to_post(pre,in,size);

    return 0;
}

