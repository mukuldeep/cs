/*
 * Created by me on 27-01-2022.
 */
#include <bits/stdc++.h>
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1;  I t;
#define F(a,c) for (ll a=0;a<c; a++)
#define Fa(xx,xxs) for(auto xx:xxs)
#define Srt(x) sort(x.begin(),x.end());
#define W(n) while(n--)

#define O cout<<
#define I cin>>
#define El endl;

#define ll long long
#define S string
#define V(x) vector<x>
#define P(x) pair<x,x>



using namespace std;

void pre(){

}


void soln(ll t){
    ll n,k,a;
    I n>>k;
    V(ll) arr(n);
    V(P(ll)) brr;
    F(i,n){//input all ai
        I arr[i];
    }
    F(i,n){//input all bi & putting them in vector of pair
        I a;
        brr.push_back({arr[i],a});
    }
    Srt(brr)//sorting them according to the first element of each element of the vector
    //looping through all the elements of the vector
    Fa(i,brr){
        if(k<i.first){//if current k (RAM size) less than smallest RAM requirement from all the softwares is greater then breaking from loop
            break;
        }else{// otherwise add i.second (RAM increase by current software) to the RAM
            k+=i.second;
        }
    }
    O k<<El//total RAM size after running all possible softwares
}

int main(){
    Sync
    W(t)
    soln(t);
    return 0;
}
