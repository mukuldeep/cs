//
// Created by mukul on 22-10-2020.
//
#include <bits/stdc++.h>
using namespace std;

int cc_main() {
    int *ptr;
    int (*ptr2)[5];
    int arr[5]={1,2,3,4,5};

    ptr=arr;
    ptr2=&arr;

    cout<<ptr<<" : "<<sizeof(ptr)<<" : "<<sizeof(*ptr)<<endl;
    cout<<ptr2<<" : "<<sizeof(ptr2)<<" : "<<sizeof(*ptr2)<<endl;

    ptr++;
    ptr2++;

    cout<<ptr<<" : "<<sizeof(ptr)<<" : "<<sizeof(*ptr)<<endl;
    cout<<ptr2<<" : "<<sizeof(ptr2)<<" : "<<sizeof(*ptr2)<<endl;

    cout<<*ptr2[0];
    for(int i=0;i<50;i++){
        cout<<i<<". "<<ptr<<" : "<<*ptr<<endl;
        ptr++;
    }


    int arr2d[][3]={{1,2,3},{4,5,6},{7,8,9}};

    for(int  i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<*(*(arr2d+i)+j)<<" ";
        }
        cout<<endl;
    }
    return 0;
}

