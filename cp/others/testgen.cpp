/*
 * Created by mukul on 10-11-2021.
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
#define t9p7 1e9+7
#define INF 1e17
using namespace std;
ofstream outfile;

void pre(){
    outfile.open("test_cases.txt",ios_base::app);
}

/*
 * appends vector data to file opened earlier
 */
void append_vector_to_file(V(S) v){
    Fa(xd,v){
        outfile<<xd<<" \n";
    }
}


/*
 * displays a vector
 */
void disp_vector(V(S) v){
    O " vector{ \n";
    Fa(xd,v){
        O "\t"<<xd<<" \n";
    }O " }"<<El
}

/*
 * print current stack and store in ans
 */
void print_stack(V(S) &stk,V(S) &ans){
    S data="";
    Fa(xd,stk) {
        //O xd << " ";
        data+=xd+" ";
    }
    //O El
    ans.Pb(data);
    //outfile << data;
}

/*
 * store all combinations from arr to ans
 */
void rec_sol(V(V(S))  &arr,ll h,V(S) &stk,V(S) &ans){
    if(h==arr.size()){
        print_stack(stk,ans);
        return;
    }
    Fa(xd,arr[h]){
        stk.Pb(xd);
        rec_sol(arr,h+1,stk,ans);
        stk.pop_back();
    }
}
/*
 * driver function
 */
void soln(ll t){
    ll m,n,k,a,b,c,u,d,l,r,cnt=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    V(V(S)) arr,atomic_rules,display_ex_rules;
    V(S) ansarr,stk,atomic,atomic_p,ans,display_ex,move_ex;

    atomic={"x","12","y(1)"};
    atomic_rules.Pb(atomic);
    atomic_rules.Pb(atomic);
    atomic_rules[1].Pb("");

    rec_sol(atomic_rules,0,stk,atomic_p);
    //disp_vector(atomic_p);


    display_ex_rules.Pb(atomic);
    display_ex_rules.Pb({"","DELIMITED BY SPACE","DELIMITED BY SIZE"});
    rec_sol(display_ex_rules,0,stk,display_ex);
    //disp_vector(display_ex);

    move_ex=atomic;
    move_ex.Pb("HIGH-VALUE");
    move_ex.Pb("LOW-VALUE");
    move_ex.Pb("SPACES");
    //disp_vector(move_ex);




    arr.Pb({"ADD"});
    arr.Pb(atomic_p);//Pb({"x","12","y(1)","x x","x 12","x y(1)","12 x","12 12","12 x(1)","x(1) x","x(1) 12","x(1) x(1)"});
    arr.Pb({"TO"});
    arr.Pb({"x","12","y(1)"});
    arr.Pb({"GIVING"});
    arr.Pb({"x","y(1)"});
    rec_sol(arr,0,stk,ansarr);
    disp_vector(ansarr);

    //arr.Pb({"."});

    //rec_sol(arr,0,stk,ans);
}

Drt
