/*
 * Created by mukul on 03-09-2024.
 */
#include <bits/stdc++.h>
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1;  //I t;
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

void print_vector(V(ld) arr){
    Fa(xx,arr) {
        O xx << "\t";
    }O El
}

void gcd_poly(V(ld) p1, V(ld) p2){
    O El
    // keeping p1 greater exponent for simplicity
    if(p1.size()<p2.size()){
        swap(p1,p2);
    }
    O "After swap:"<<El
    O "p1:";print_vector(p1);
    O "p2:";print_vector(p2);

    // breaking condition
    // break if gcd found i.e. any one of the polynomial has size<=1
    if(p2.size()<=1){
        O "\n\nGCD is *:";
        print_vector(p1);
        O "* (may be multiplied by some constant)"<<El
        return;
    }


    // finding factor
    ld facr = (p1[p1.size()-1]/p2[p2.size()-1]);
    O "The factor to be divided with is "<<facr<<El

    //create vector to substract
    for( int i = 0;i<p2.size();i++){
        p2[i] *= facr;
    }
    O "p2 after multiplying :\t";
    print_vector(p2);


    //substract it from the p1
    for(int p1_i=p1.size()-1,p2_i=p2.size()-1;p2_i>=0;p1_i--,p2_i--){
        p1[p1_i] -= p2[p2_i];
    }
    O "p1 after substraction:\t";
    print_vector(p1);

    //reducing p1 iff most significant exponents coficients are ~0
    ld p_zero = 1e-9;
    ld n_zero = -1e-9;
    while(p1.size()>0 && p1[p1.size()-1]<p_zero && p1[p1.size()-1]> n_zero){
        p1.pop_back();
    }

    O "p1 after reduction:\t";
    print_vector(p1);

    gcd_poly(p1,p2);

}


void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    S str;
    //I n>>m;
    n=4;
    m = 3;
    V(ld) p1={-1,1,-1,1};
    V(ld) p2 = {2,-3,1};

    O "initial vectors:"<<El
    O "p1:";print_vector(p1);
    O "p2:";print_vector(p2);

    gcd_poly(p1,p2);


}

Dr


/**
 *  HOW TO RUN
 *  1. Consider soln() as main function for the program
 *  change iff any changes in test cases are required
 *
 */


/**
 * Problem statement
 * Given two univariate polynomials p1 and p2 (of the same variable) find
 * their greatest common divisor. For example the two polynomials x^3−x^2+x−1
 * and x^2 −3x+ 4 have x−1 as their gcd. Each polynomial is provided
 * as an array of its coefficients. For example x^3 − 3x^2 + 4 is provided as [4,-3,0,1].
 *
 */
