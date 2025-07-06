/*
 * Created by mukul on 01-10-2024.
 */
#include <bits/stdc++.h>
#define Sync ios_base::sync_with_stdio(false); cin.tie(nullptr);pre();ll t=1; // I t;
#define Dr int main(){Sync W(t)soln(t);return 0;}
#define Drt int cc_main(){Sync W(t)soln(t);return 0;}
#define F(a,c) for(ll a=0;a<c; a++)
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

struct Point{
    int x, y;
};


// returns the orientation of the ordered triplet(p, q, r).
// 0 -> p, q, r are collinear
// >0 -> clockwise
// <0 -> counterclockwise
int orientation(Point p, Point q, Point r){
    int val =(q.y - p.y) *(r.x - q.x) -(q.x - p.x) *(r.y - q.y);
    if(val == 0) return 0;  // 0: collinear
    return (val > 0) ? 1 : 2; // 1: clock 2: anticlock wise
}

//square distance betwn points
int distSq(Point p1, Point p2){
    return (p1.x - p2.x) *(p1.x - p2.x) +(p1.y - p2.y) *(p1.y - p2.y);
}

// comparison function for point sorting
Point p0;
bool compare(Point p1, Point p2){
    int o = orientation(p0, p1, p2);
    if(o == 0)
        return distSq(p0, p2) >= distSq(p0, p1);
    return (o == 2);
}

// returns the convex hull of a set of n points
// using grahams scan algo
V(Point) convexHull(V(Point)& points){
    int n = points.size();

    // Finding the point with the lowest y-coordinate(and lowest x if tied)
    int ymin = points[0].y, min = 0;
    for(int i = 1; i < n; i++){
        if((points[i].y < ymin) ||(points[i].y == ymin && points[i].x < points[min].x)){
            ymin = points[i].y;
            min = i;
        }
    }


    swap(points[0], points[min]);
    p0 = points[0];

    // Sorting points based on polar angle with p0
    sort(points.begin() + 1, points.end(), compare);

    // collinear points removal
    int m = 1;
    for(int i = 1; i < n; i++){
        while(i < n - 1 && orientation(p0,points[i],points[i + 1]) == 0){
            i++;
        }
        points[m] = points[i];
        m++;
    }

    if(m<3) return {};  // less than 3 point can't form a covex hull

    // push three point on the stack
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    // for remaining points
    for(int i = 3; i < m; i++){
        while(S.size()> 1){
            Point secondTop = S.top();
            S.pop();
            Point firstTop = S.top();
            if(orientation(firstTop, secondTop, points[i])== 2){
                S.push(secondTop);
                break;
            }
        }
        S.push(points[i]);
    }

    // The convex hull is in the stack
    // we can return no of elements on the stack here
    //return S.size();

    V(Point) hull;
    while(!S.empty()){
        hull.push_back(S.top());
        S.pop();
    }
    return hull;
}


void soln(ll t){
    V(Point) points ={{0, 3},{2, 3},{1, 1},{2, 2},{4, 4},{0, 0},{4, 0},{4, 3}};

    V(Point) hull = convexHull(points);

    O "Number of points on the convex hull: " << hull.size()<< El

}

Dr


/**
 * Problem statement
 * Given n points in a plane, output the number of points on the convex hull.
 */


/**
 *  HOW TO RUN
 *  1. Consider soln() as main function for the program
 *  change iff any changes in test cases are required
 *
 */
