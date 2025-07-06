/*
 * Created by me on 24-02-2022.
 */
#include <bits/stdc++.h>
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1; I t;
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
class Contr{
public:
    S name;
    ll n_skill;
    Uom(S,ll) skills;
};
class Projs{
public:
    S name;
    ll day_com;
    ll score;
    ll best_bef;
    ll n_roles;
    ll max_skill_level;
    V(P2(S,ll)) roles;
};

bool sortbysec(const Projs &a,const Projs &b)
{    /*if(a.best_bef==b.best_bef){
        return a.score>b.score;
        }*/
    return (a.score > b.score);
}

void soln(){
    ll m,n,k,a,b,u,d,l,r,cnt=0,ans=0,mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    ll n_contr,n_proj;
    I n_contr>>n_proj;

    Uom(S,Uom(ll,St(ll))) skill_available;
    V(V(ll)) next_available(300000);

    V(Contr) contr;
    F(i,n_contr){
        Contr c;
        I c.name>>c.n_skill;
        V(P2(S,ll)) skills;
        F(j,c.n_skill){
            S skill_name;ll skill_level;
            I skill_name>>skill_level;
            c.skills[skill_name]=skill_level;
            skill_available[skill_name][skill_level].insert(i);
        }
        contr.push_back(c);
    }

    V(Projs) projs;
    F(i,n_proj){
        Projs p;
        I p.name>>p.day_com>>p.score>>p.best_bef>>p.n_roles;
        F(j,p.n_roles){
            S skill_name;ll skill_level;
            I skill_name>>skill_level;
            p.roles.push_back({skill_name,skill_level});
        }
        projs.push_back(p);
    }

    sort(projs.begin(),projs.end(),sortbysec);

    //start processing
    V(P2(S,V(S))) ans_allocation;

    V(Projs) next_projs;

    //day 0 at start
    V(P2(S,ll)) curr_valid_allocations;
    F(i,n_proj){
        if(projs[i].best_bef+projs[i].score<=projs[i].day_com)
            continue;
        ////O "projname:"<<projs[i].name<<El
        vector<ll> curr_allocation;
        bool flag=true;
        Fa(role,projs[i].roles){
            ////O "\t role:"<<role.first<<El
            //O "\t\t"<<skill_available[role.first][role.second].empty()<<El
            if(!skill_available[role.first][role.second].empty()){//exact match
                ////O "\t\tfound exact match"<<El
                ll curr_contr=*skill_available[role.first][role.second].begin();
                curr_allocation.push_back(curr_contr);
                Fa(skill,contr[curr_contr].skills){//remove this guy from other places
                    skill_available[skill.first][skill.second].erase(curr_contr);
                }
            }else{
                ll next_greater_role;
                for(next_greater_role=role.second+1;next_greater_role<102;next_greater_role++){
                    if(!skill_available[role.first][next_greater_role].empty())break;
                }
                if(next_greater_role<102){
                    ////O "\t\tfound greater match"<<El
                    ll curr_contr=*skill_available[role.first][next_greater_role].begin();
                    curr_allocation.push_back(curr_contr);
                    Fa(skill,contr[curr_contr].skills){
                        skill_available[skill.first][skill.second].erase(curr_contr);
                    }
                }else {
                    if(!skill_available[role.first][role.second-1].empty()){//prev one
                        ll curr_contr=*skill_available[role.first][role.second-1].begin();
                        bool is_any_one_have=false;
                        Fa(AA,curr_allocation){
                            is_any_one_have|=(contr[AA].skills[role.first]>=role.second);
                        }
                        if(is_any_one_have){
                            curr_allocation.push_back(curr_contr);
                            Fa(skill,contr[curr_contr].skills){
                                skill_available[skill.first][skill.second].erase(curr_contr);
                            }
                        }else{
                            flag=false;
                        }
                    }else {
                        flag = false;
                    }
                }
            }
        }
        if(flag){//valid allocation
            ////O projs[i].name<<El
            V(S) contr_names;
            F(kk,projs[i].roles.size()) {
                ll curr_contr=curr_allocation[kk];
                if(projs[i].roles[kk].second>=contr[curr_contr].skills[projs[i].roles[kk].first]){
                    contr[curr_contr].skills[projs[i].roles[kk].first]++;
                }
                next_available[projs[i].day_com + 1].push_back(curr_contr);
                contr_names.push_back(contr[curr_contr].name);
                ///O "\t " << contr[curr_contr].name << El

            }
            ans+=projs[i].score;
            ans_allocation.push_back({projs[i].name,contr_names});
        }else{//invalid allocation
            Fa(curr_contr,curr_allocation){
                Fa(skill,contr[curr_contr].skills){
                    skill_available[skill.first][skill.second].insert(curr_contr);
                }
            }
            next_projs.push_back(projs[i]);
        }
    }




    //run for other day
    for(ll day=1;day<200005;day++){
        if(next_available[day].empty())continue;
        //ll dcnt=0;
        ////O "day "<<day<<El
        if(next_projs.empty())break;
        projs=next_projs;//available projects
        next_projs.erase(next_projs.begin(),next_projs.end());
        if(!next_available[day].empty()){//freeing old guys
            Fa(curr_contr,next_available[day]){
                Fa(skill,contr[curr_contr].skills){
                    skill_available[skill.first][skill.second].insert(curr_contr);
                }
            }
        }
        //process for today
        curr_valid_allocations.erase(curr_valid_allocations.begin(),curr_valid_allocations.end());

        F(i,projs.size()){
            if(projs[i].best_bef+projs[i].score<=projs[i].day_com+day)
                continue;
            ////O "projname:"<<projs[i].name<<El
            vector<ll> curr_allocation;
            bool flag=true;
            Fa(role,projs[i].roles){
                ////O "\t role:"<<role.first<<El
                //O "\t\t"<<skill_available[role.first][role.second].empty()<<El
                if(!skill_available[role.first][role.second].empty()){//exact match
                    ////O "\t\tfound exact match"<<El
                    ll curr_contr=*skill_available[role.first][role.second].begin();
                    curr_allocation.push_back(curr_contr);
                    Fa(skill,contr[curr_contr].skills){//remove this guy from other places
                        skill_available[skill.first][skill.second].erase(curr_contr);
                    }
                }else{
                    ll next_greater_role;
                    for(next_greater_role=role.second+1;next_greater_role<102;next_greater_role++){
                        if(!skill_available[role.first][next_greater_role].empty())break;
                    }
                    if(next_greater_role<102){
                        ////O "\t\tfound greater match"<<El
                        ll curr_contr=*skill_available[role.first][next_greater_role].begin();
                        curr_allocation.push_back(curr_contr);
                        Fa(skill,contr[curr_contr].skills){
                            skill_available[skill.first][skill.second].erase(curr_contr);
                        }
                    }else {
                        if(!skill_available[role.first][role.second-1].empty()){
                            ll curr_contr=*skill_available[role.first][role.second-1].begin();
                            bool is_any_one_have=false;
                            Fa(AA,curr_allocation){
                                is_any_one_have|=(contr[AA].skills[role.first]>=role.second);
                            }
                            if(is_any_one_have){
                                curr_allocation.push_back(curr_contr);
                                Fa(skill,contr[curr_contr].skills){
                                    skill_available[skill.first][skill.second].erase(curr_contr);
                                }
                            }else{
                                flag=false;
                            }
                        }else {
                            flag = false;
                        }
                    }
                }
            }
            if(flag){//valid allocation
                ////O projs[i].name<<El
                V(S) contr_names;
                F(kk,projs[i].roles.size()) {
                    ll curr_contr=curr_allocation[kk];
                    if(projs[i].roles[kk].second>=contr[curr_contr].skills[projs[i].roles[kk].first]){
                        contr[curr_contr].skills[projs[i].roles[kk].first]++;
                    }
                    next_available[projs[i].day_com + 1].push_back(curr_contr);
                    contr_names.push_back(contr[curr_contr].name);
                    ////O "\t " << contr[curr_contr].name << El

                }
                //dcnt++;
                ans_allocation.push_back({projs[i].name,contr_names});
            }else{//invalid allocation
                Fa(curr_contr,curr_allocation){
                    Fa(skill,contr[curr_contr].skills){
                        skill_available[skill.first][skill.second].insert(curr_contr);
                    }
                }
                next_projs.push_back(projs[i]);
            }
        }

        /*if(!dcnt){
            day++;
            while(!next_available[day].empty()){
                day++;
            }
        }*/
        //day loop ends
    }

    //print the answer
    O ans_allocation.size()<<El
    Fa(alloca,ans_allocation){
        O alloca.first<<El
        Fa(allcc,alloca.second){
            O allcc<<" ";
        }O El
    }

    //O ans<<El


}

int cc_main() {
    //Sync
    /*ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    pre();*/


    S path="../external_files/contests/hashcode 2022/inout/";
    //ifstream cin("./inout/input.txt");
    //ofstream cout("./inout/output.txt");

    freopen("../external_files/contests/hashcode 2022/inout/c_output.txt", "a", stdout);
    freopen(("../external_files/contests/hashcode 2022/inout/c.txt"), "r", stdin);
    soln();

    /*freopen("b_output.txt", "a", stdout);
    freopen("b.txt", "r", stdin);
    soln();
    freopen("c_output.txt", "a", stdout);
    freopen("c.txt", "r", stdin);
    soln();
    freopen("d_output.txt", "a", stdout);
    freopen("d.txt", "r", stdin);
    soln();
    freopen("e_output.txt", "a", stdout);
    freopen("e.txt", "r", stdin);
    soln();
    freopen("f_output.txt", "a", stdout);
    freopen("f.txt", "r", stdin);
    soln();
     */
    return 0;
}