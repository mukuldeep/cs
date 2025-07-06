/*
 * Created by me on 10-08-2023.
 */
#include <bits/stdc++.h>
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1; // I t;
#define Dr int main(){Sync W(t)soln(t);return 0;}
#define Drt int cc_main(){Sync W(t)soln(t);return 0;}
#define F(a,c) for (ll a=0;a<c; a++)
#define Fe(a,c) for(ll a=0;a<=c; a++)
#define Fi(i,s,e) for(ll i=s;i<e;i++)
#define Rfi(i,s,e) for(ll i=s;i>e;i--)
#define Fa(xx,xxs) for(auto xx:xxs)
#define Srt(x) sort(x.begin(),x.end());
#define Rsrt(x) sort(x.rbegin(),x.rend());
#define Rev(x) reverse(x.begin(),x.end());
#define W(n) while(n--)
#define Wh while
#define Il while(1)
#define Pb push_back
#define O cout<<
#define Prcn fixed<<setprecision(20)
#define I cin>>
#define El endl;
//ds
#define ll long long
#define ld long double
#define S string
#define Ch char
#define V(x) vector<x>
#define Vv(x) V(V(x))
#define Sk(x) stack<x>
#define St(x) set<x>
#define Q(x) queue<x>
#define Dq(x) deque<x>
#define P(x) pair<x,x>
#define P2(x,y) pair<x,y>
#define Mp(x,y) map<x,y>
#define Uom(x,y) unordered_map<x,y>

//functions
#define p_bin(x) if(x)O "YES"<<El else O "NO"<<El

//constants
#define t9p7 1000000007
#define INF 100000000000000000 //1e17
using namespace std;

void pre(){

}
/*
int getArtisticPhotographCountpre(int N, string C, int X, int Y) {
    // Write your code here
    int ans = 0;
    int P_P=0,P_B=0,N_P=0,N_B=0;
    // initiating next P & B count
    int ni=X,nj=Y;
    if(X==N)ni--;
    if(Y==N)nj--;
    for(int i=ni;i<=nj;i++){
        if(C[i] == 'P') N_P++;
        if(C[i] == 'B') N_B++;
    }
    cout<<N_P<<" "<<N_B<<endl;
    for(int i=1;i<N;i++){
        // update previous range counts
        if(i-X>=0){
            if(C[i-X] == 'P') P_P++;
            if(C[i-X] == 'B') P_B++;
            if(i-Y>0){
                if(C[i-Y-1] == 'P') P_P--;
                if(C[i-Y-1] == 'B') P_B--;
            }
        }
        // update next range counts
        if(i+X<N){
            if(C[i+X-1] == 'P') N_P--;
            if(C[i+X-1] == 'B') N_B--;
            if(i+Y<N){
                if(C[i+Y] == 'P') N_P++;
                if(C[i+Y] == 'B') N_B++;
            }
        }

        // Update count in case of Actor
        if(C[i] == 'A'){
            ans+=(P_P*N_B+P_B*N_P);
        }
        cout<<i<<" P:p="<<P_P<<" b="<<P_B<<" N:p="<<N_P<<" b="<<N_B<<endl;
    }
    return ans;
}
*/

int getArtisticPhotographCount_accepted(int N, string C, int X, int Y) {
    // Write your code here
    int NN=N+2;
    string CC="."+C+".";
    int ans = 0;
    int P_P=0,P_B=0,N_P=0,N_B=0;

    //if(CC[0] == 'P') P_P++;
    //if(CC[0] == 'B') P_B++;

    // initiating next P & B count
    int ni=X,nj=Y,pi=0,pj=0;
    if(X==NN)ni--;
    if(Y==NN)nj--;
    int pre_ni=ni,pre_nj=nj,pre_pi=0,pre_pj=0;

    for(int i=ni;i<=nj;i++){
        if(CC[i] == 'P') N_P++;
        if(CC[i] == 'B') N_B++;
    }
    for(int i=1;i<NN;i++){
        // update previous range counts
        pi=i-Y;pj=i-X;ni=i+X;nj=i+Y;
        if(pi<0)pi=0;
        if(pj<0)pj=0;
        if(ni>=NN)ni=NN-1;
        if(nj>=NN)nj=NN-1;

        if(pi != pre_pi){
            if(CC[pre_pi] == 'P')P_P--;
            if(CC[pre_pi] == 'B')P_B--;
        }
        if(pj != pre_pj){
            if(CC[pj] == 'P')P_P++;
            if(CC[pj] == 'B')P_B++;
        }
        if(ni != pre_ni){
            if(CC[pre_ni] == 'P')N_P--;
            if(CC[pre_ni] == 'B')N_B--;
        }
        if(nj != pre_nj){
            if(CC[nj] == 'P')N_P++;
            if(CC[nj] == 'B')N_B++;
        }
        pre_pi = pi;
        pre_pj = pj;
        pre_ni = ni;
        pre_nj = nj;

        // Update count in case of Actor
        if(CC[i] == 'A'){
            ans+=(P_P*N_B+P_B*N_P);
        }
    }
    return ans;
}

int getArtisticPhotographCount(int N, string C, int X, int Y) {
    // Write your code here
    int NN=N+2;
    string CC="."+C+".";
    int ans = 0;
    int P_P=0,P_B=0,N_P=0,N_B=0;

    //if(C[0] == 'P') P_P++;
    //if(C[0] == 'B') P_B++;
    // initiating next P & B count
    int ni=X,nj=Y,pi=0,pj=0;
    if(X==NN)ni--;
    if(Y==NN)nj--;
    int pre_ni=ni,pre_nj=nj,pre_pi=0,pre_pj=0;

    for(int i=ni;i<=nj;i++){
        if(CC[i] == 'P') N_P++;
        if(CC[i] == 'B') N_B++;
    }
    cout<<ni<<"-"<<nj<<" N:"<<N_P<<" "<<N_B<<endl;
    for(int i=1;i<NN-1;i++){
        // update previous range counts
        pi=i-Y;pj=i-X;ni=i+X;nj=i+Y;
        if(pi<0)pi=0;
        if(pj<0)pj=0;
        if(ni>=NN)ni=NN-1;
        if(nj>=NN)nj=NN-1;

        if(pi != pre_pi){
            if(CC[pre_pi] == 'P')P_P--;
            if(CC[pre_pi] == 'B')P_B--;
        }
        if(pj != pre_pj){
            if(CC[pj] == 'P')P_P++;
            if(CC[pj] == 'B')P_B++;
        }
        if(ni != pre_ni){
            if(CC[pre_ni] == 'P')N_P--;
            if(CC[pre_ni] == 'B')N_B--;
        }
        if(nj != pre_nj){
            if(CC[nj] == 'P')N_P++;
            if(CC[nj] == 'B')N_B++;
        }
        //cout<<i<<" P:p="<<P_P<<" b="<<P_B<<" N:p="<<N_P<<" b="<<N_B<<endl;
        cout<<i<<" p="<<pi<<"-"<<pj<<" n="<<ni<<"-"<<nj<<" P:"<<P_P<<" "<<P_B<<" N:"<<N_P<<" "<<N_B<<endl;

        pre_pi = pi;
        pre_pj = pj;
        pre_ni = ni;
        pre_nj = nj;
        // Update count in case of Actor
        if(CC[i] == 'A'){
            cout<<i<<" A found:"<<(P_P*N_B+P_B*N_P)<<endl;
            ans+=(P_P*N_B+P_B*N_P);
        }
    }
    return ans;
}
/*
int getArtisticPhotographCount(int N, string C, int X, int Y) {
    int arr_b[N];

}
 */

long long getArtisticPhotographCount_accepted_2(int N, string C, int X, int Y) {
    // Write your code here
    N+=2;
    C="."+C+".";
    long long ans = 0;
    long long P_P=0,P_B=0,N_P=0,N_B=0;

    // initiating next P & B count
    int ni=X,nj=Y,pi=0,pj=0;
    if(X==N)ni--;
    if(Y==N)nj--;
    int pre_ni=ni,pre_nj=nj,pre_pi=0,pre_pj=0;

    for(int i=ni;i<=nj;i++){
        if(C[i] == 'P') N_P++;
        else if(C[i] == 'B') N_B++;
    }
    for(int i=1;i<N-1;i++){
        // update previous range counts
        pi=i-Y;pj=i-X;ni=i+X;nj=i+Y;
        if(pi<0)pi=0;
        if(pj<0)pj=0;
        if(ni>=N)ni=N-1;
        if(nj>=N)nj=N-1;

        if(pi != pre_pi){
            if(C[pre_pi] == 'P')P_P--;
            else if(C[pre_pi] == 'B')P_B--;
        }
        if(pj != pre_pj){
            if(C[pj] == 'P')P_P++;
            else if(C[pj] == 'B')P_B++;
        }
        if(ni != pre_ni){
            if(C[pre_ni] == 'P')N_P--;
            else if(C[pre_ni] == 'B')N_B--;
        }
        if(nj != pre_nj){
            if(C[nj] == 'P')N_P++;
            else if(C[nj] == 'B')N_B++;
        }
        pre_pi = pi;
        pre_pj = pj;
        pre_ni = ni;
        pre_nj = nj;

        // Update count in case of Actor
        if(C[i] == 'A'){
            ans+=(P_P*N_B+P_B*N_P);
        }
    }
    return ans;
}
void soln(ll t){
    int N=6;
    string C="BPAAPB";
    int X=3;
    int Y=5;
    cout<<getArtisticPhotographCount(N,C,X,Y)<<endl;
}

Drt
