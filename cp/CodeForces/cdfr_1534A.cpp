//
// Created by me on 13-06-2021.
//
#include <bits/stdc++.h>
#define SYNC ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define DRIVER int main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define TEST_DRIVER int cc_main(){SYNC ll t=1;I_ t;W_(t)soln(t);return 0;}
#define FR_(a,c)   for (ll (a)=0;(a)<(c); (a)++)
#define FR_E(a,c)   for (ll (a)=0;(a)<=(c); (a)++)
#define FR_IR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FR_AU(xx,xxs) for(auto (xx):(xxs))
#define srt(ww) sort((ww).begin(),(ww).end())
#define rsrt(ww) sort((ww).rbegin(),(ww).rend())
#define W_(n) while((n)--)
#define WH_ while
#define IL_ while(1)
#define PB_ push_back
#define MP_(a,b) make_pair((a),(b))
#define O_ cout<<
#define PRCN fixed<<setprecision(20)
#define I_ cin>>
#define EL endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef stack<ll> skll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef vector<pair<ll, ll>> vprll;
typedef map<ll,ll>  mpll;
typedef unordered_map<ll,ll> uompll;
typedef set<ll> stll;
const ll t9p7=1000000007;
bool check(vector<string> &mat,ll n,ll m){
    FR_IR(i,0,n){
        FR_IR(j,0,m){
            if(i>0){
                if(mat[i-1][j]==mat[i][j])return false;
            }
            if(i<n-1){
                if(mat[i+1][j]==mat[i][j])return false;
            }
            if(j>0){
                if(mat[i][j-1]==mat[i][j])return false;
            }
            if(j<m-1){
                if(mat[i][j+1]==mat[i][j])return false;
            }
        }
    }
    return true;
}

void soln(ll t){
    ll m,n,k,a,b,c,cnt=0,ans=1,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    string str;
    I_ n>>m;
    vll arr(n);
    vector<string> mat(n);
    queue<pair<ll,ll>> qu;
    FR_IR(i,0,n){
        I_ mat[i];
        FR_IR(j,0,m){
            if(mat[i][j]!='.')qu.push({i,j});
        }
    }
    if(qu.empty()){
        qu.push({0,0});
        mat[0][0]='W';
    }
    while(!qu.empty()){
        pair<ll,ll> pr;
        pr=qu.front();
        a=pr.first;
        b=pr.second;
        qu.pop();
        if(a>0){
            if(mat[a-1][b]=='.'){
                qu.push({a-1,b});
                if(mat[a][b]=='W')mat[a-1][b]='R';
                else mat[a-1][b]='W';
            }else if(mat[a-1][b]==mat[a][b]){
                ans=0;
                break;
            }
        }
        if(a<n-1){
            if(mat[a+1][b]=='.'){
                qu.push({a+1,b});
                if(mat[a][b]=='W')mat[a+1][b]='R';
                else mat[a+1][b]='W';
            }else if(mat[a+1][b]==mat[a][b]){
                ans=0;
                break;
            }
        }
        if(b>0){
            if(mat[a][b-1]=='.'){
                qu.push({a,b-1});
                if(mat[a][b]=='W')mat[a][b-1]='R';
                else mat[a][b-1]='W';
            }else if(mat[a][b-1]==mat[a][b]){
                ans=0;
                break;
            }
        }
        if(b<m-1){
            if(mat[a][b+1]=='.'){
                qu.push({a,b+1});
                if(mat[a][b]=='W')mat[a][b+1]='R';
                else mat[a][b+1]='W';
            }else if(mat[a][b+1]==mat[a][b]){
                ans=0;
                break;
            }
        }
    }

    if(ans){
        if(check(mat,n,m)){
            O_ "YES"<<EL
            FR_IR(i,0,n){
                O_ mat[i]<<EL
            }
        }else{
            O_ "NO"<<EL
        }
    }else{
        O_ "NO"<<EL
    }

}
DRIVER
