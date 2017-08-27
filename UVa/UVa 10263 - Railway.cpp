/**********************************************/
/**                                          **/
/**   UVa 10263 - Railway.cpp                **/
/**   Credits to Mahmoud Tarek Samir         **/
/**   Ma7moud.tarek97@gmail.com              **/
/**                                          **/
/**********************************************/
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <complex>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

const double PI = acos(-1);
const double EPS = (1e-8);

typedef complex<double> point;

#define X real()
#define Y imag()

//we can rewrite any of the following as functions
#define angle(a)        (atan2((a).imag(), (a).real()))
#define vec(a,b)        ((b)-(a))
#define length(a)       (hypot((a).imag(), (a).real()))     //avoid sqrt() to avoid overflow
#define normalize(a)    (a)/length(a)   // a unit vector of vector a
// if dot(a,b) > 0 ==> angle > 90
// if dot(a,b) = 0 ==> a prep b
// if dot(a,b) < 0 ==> angle < 90
#define dot(a,b)        ( (conj(a)*(b)).real() )
// if cross(a,b) > 0 ==> angle from a to b is convex (CCW)
// if cross(a,b) = 0 ==> a parallel b
// if cross(a,b) < 0 ==> angle from a to b is concave (CW)
// calculate magnitude of cross product
#define cross(a,b)      ( (conj(a)*(b)).imag() )
// rotate vector around origin with angle ccw
#define rotate0(p,ang)  ((p)*exp(point(0,ang)))
// rotate vector around specific point with angle ccw
// Generalization for last rotate0
#define rotateA(p,ang,about)    (rotate0(vec(about,p),ang)+about)
// reflect vector v around vector m from origin
#define reflect0(v,m)   (conj((v)/(m))*(m))
// boolean function to test if 2 vectors are the same (have the same length and angle)
#define same(p1,p2)             (dot(vec(p1,p2),vec(p1,p2)) < EPS)


point ans;
// distance from point p to segment p0-p1
double distToSegment( point p0, point p1, point p )
{
    double c1, c2;
    point v = p1-p0, w = p-p0;
    if( (c1 = dot(v, w) ) <= 0)
    {
        ans=p0;
        return length(p-p0);
    }
    if( (c2 = dot(v, v) ) <= c1){
        ans=p1;
    	return length(p-p1);
    }
    double t = c1/c2;   // p above the segment
    ans = p0 + v*t;
    return length(p - ans);
}

int main()
{
    cout << fixed << setprecision(4);
    double x,y;
    while(cin >> x >> y)
    {
        point M(x,y);
        int n;
        cin >> n;
        vector<point> points(0);
        for(int i=0; i<n+1; i++)
        {
            cin >> x >> y;
            points.push_back(point(x,y));
        }
        double min_dist=100000000,dist;
        point p;
        for(int i=0; i<n; i++)
        {
            if((dist=distToSegment(points[i],points[i+1],M))<min_dist)
            {
                min_dist=dist;
                p=ans;
            }
        }
        cout << p.X << endl << p.Y << endl;
    }
    return 0;
}
