//
// Created by me on 19-08-2021.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;


int SumOfPro(int arr1[],int arr2[],int n){
    if(n==0)return -1;
    int a=0;
    for(int i=0;i<n;i++)
        a+=(arr1[i]*arr2[n-i-1]);
    return a;
}

