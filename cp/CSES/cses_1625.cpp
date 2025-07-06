//
// Created by me on 30-10-2020.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int grid[7][7]={0};
int cnt=0;
void print_grid(){
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
void print_all_path(int i,int j,int h){
    if(i==7)i=0;
    if(j==7)j=0;
    if(h==48) {
        int ff;
        cnt++;
        print_grid();
        cin>>ff;
        return;
    }
    if(j!=0){//up
        if(grid[j-1][i]==0){
            grid[j-1][i]=1;
            print_all_path(i,j-1,h+1);
            grid[j-1][i]=0;
        }
    }
    if(j<6){//down
        if(grid[j+1][i]==0){
            grid[j+1][i]=1;
            print_all_path(i,j+1,h+1);
            grid[j+1][i]=0;
        }
    }

    if(i!=0){//left
        if(grid[j][i-1]==0){
            grid[j][i-1]=1;
            print_all_path(i-1,j,h+1);
            grid[j][i-1]=0;
        }
    }
    if(i<6){//right
        if(grid[j][i+1]==0){
            grid[j][i+1]=1;
            print_all_path(i+1,j,h+1);
            grid[j][i+1]=0;
        }
    }
}
void soln(ll t){
    print_all_path(0,0,0);
    cout<<cnt;
}

int cc_main() {
    ll t=1;
    //cin>>t;
    while(t--)
        soln(t);
    return 0;
}



